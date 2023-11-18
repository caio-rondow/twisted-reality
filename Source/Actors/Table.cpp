#include "Table.h"
#include "Block.h"
#include "../Game/ConcreteGame.h"

#define INPUT_DELAY 0.085

Table::Table(InterfaceGame *game, uint width, uint height):
    Actor(game),
    mTableWidth(width),
    mTableHeight(height),
    mTimesPassed(0.0f),
    mTable(height, std::vector<Block*>(width, nullptr)),
    mCursor(nullptr),
    mCanProcessInput(true)
{   

    float xMid = game->GetWindowWidth()/2;
    float yMid = game->GetWindowHeight()/2;

  
    for(int i=0; i<mTableHeight; i++){
        for(int j=0; j<mTableWidth; j++){
            mTable[i][j] = new Block(game);
            mTable[i][j]->SetPosition(Vector2(j*32 + yMid, i*32 + xMid));
        }
    }
    /* LINK BLOCKS */
    for(int i=0; i<mTableHeight; i++){
        for(int j=0; j<mTableWidth; j++){
            
            Block *CurrentBlock = mTable[i][j];

            if(i > 0){
                CurrentBlock->Link(mTable[i-1][j], UP);
            }

            if(i < mTableHeight-1){
                CurrentBlock->Link(mTable[i+1][j], DOWN);
            }

            if(j > 0){
                CurrentBlock->Link(mTable[i][j-1], LEFT);
            }

            if(j < mTableWidth-1){
                CurrentBlock->Link(mTable[i][j+1], RIGHT);
            }
        }
    }
    mCursor = mTable[0][0];
}

void Table::OnUpdate(float DeltaTime){
    mTimesPassed += DeltaTime;
    if(mTimesPassed >= INPUT_DELAY){
        mTimesPassed = 0.0f;
        mCanProcessInput = true;
    } 
}

void Table::OnProcessInput(const Uint8 *KeyState){

    if(mCursor == nullptr || mCanProcessInput == false)
        return;
        
    if(KeyState[SDL_SCANCODE_W] && (*mCursor)[UP] != nullptr){
        mCursor->SetSelected(false);
        mCursor = (*mCursor)[UP];
    }
    if(KeyState[SDL_SCANCODE_A] && (*mCursor)[LEFT] != nullptr){
        mCursor->SetSelected(false);
        mCursor = (*mCursor)[LEFT];
    }
    if(KeyState[SDL_SCANCODE_S] && (*mCursor)[DOWN] != nullptr){
        mCursor->SetSelected(false);
        mCursor = (*mCursor)[DOWN];
    }
    if(KeyState[SDL_SCANCODE_D] && (*mCursor)[RIGHT] != nullptr){
        mCursor->SetSelected(false);
        mCursor = (*mCursor)[RIGHT];
    }
    mCursor->SetSelected(true);
    mCanProcessInput = false;
}
