#include "Table.h"
#include "Block.h"

Table::Table(InterfaceGame *game, uint width, uint height):
    Actor(game),
    mTableWidth(width),
    mTableHeight(height),
    mTable(height, std::vector<Block*>(width, nullptr)),
    mCursor(nullptr)
{
    for(int i=0; i<mTableHeight; i++){
        for(int j=0; j<mTableWidth; j++){
            mTable[i][j] = new Block(game);
            mTable[i][j]->SetPosition(Vector2(j*32, i*32));
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

void Table::OnProcessInput(const Uint8 *KeyState){

    if(mCursor == nullptr)
        return;
    if(KeyState[SDL_SCANCODE_W] && (*mCursor)[UP] != nullptr){
        mCursor = (*mCursor)[UP];
        std::cout << mCursor->GetPosition().x << " " << mCursor->GetPosition().y << "\n";
    }
    if(KeyState[SDL_SCANCODE_A] && (*mCursor)[LEFT] != nullptr){
        mCursor = (*mCursor)[LEFT];
        std::cout << mCursor->GetPosition().x << " " << mCursor->GetPosition().y << "\n";
    }
    if(KeyState[SDL_SCANCODE_S] && (*mCursor)[DOWN] != nullptr){
        mCursor = (*mCursor)[DOWN];
        std::cout << mCursor->GetPosition().x << " " << mCursor->GetPosition().y << "\n";
    }
    if(KeyState[SDL_SCANCODE_D] && (*mCursor)[RIGHT] != nullptr){
        mCursor = (*mCursor)[RIGHT];
        std::cout << mCursor->GetPosition().x << " " << mCursor->GetPosition().y << "\n";
    }
}
