#include "Piece.h"
#include "../Components/DrawComponents/DrawSpriteComponent.h"
#include "../Game/InterfaceGame.h"

Piece::Piece(InterfaceGame *game, char type, const Vector2&origin, float rotation, bool flip):
    Actor(game),
    mType(type),
    mFlip(flip),
    mState(PieceState::IDLE)
{
    this->SetPosition(origin);
    this->SetRotation(rotation);
    new DrawSpriteComponent(this, "../Assets/Sprite/Block.png", 32, 32);
}

void Piece::OnUpdate(float DeltaTime){
    
}

void Piece::OnProcessInput(const Uint8 *KeyState){
    
    Vector2 pos = this->GetPosition();

    if(KeyState[SDL_SCANCODE_Z]){
        mState = PieceState::MOVE;
    } else if(KeyState[SDL_SCANCODE_X]){
        mState = PieceState::ROTATE;
    } else if(KeyState[SDL_SCANCODE_C]){
        mState = PieceState::FLIP;
    } else if(KeyState[SDL_SCANCODE_SPACE]){
        mState = PieceState::PLACE;
    } else if(KeyState[SDL_SCANCODE_V]){
        mState = PieceState::IDLE;
    }

    switch (mState)
    {
    case PieceState::MOVE:
        Move(KeyState);
        break;
    case PieceState::ROTATE:
        Rotate(KeyState);
        break;
    case PieceState::FLIP:
        Flip(KeyState);
        break;
    case PieceState::PLACE:
        Place();
        break;
    default:
        break;
    }
}

/* Piece methods */
void Piece::Rotate(const Uint8 *KeyState){
    std::cout << "Rotate\n";
}

void Piece::Flip(const Uint8 *KeyState){
    std::cout << "Flip\n";
}

void Piece::Move(const Uint8 *KeyState){
    std::cout << "Move\n";
    Vector2 pos = GetPosition();
    float offset = 10;
    if(KeyState[SDL_SCANCODE_D])
        SetPosition(Vector2(pos.x+offset, pos.y));
    if(KeyState[SDL_SCANCODE_A])
        SetPosition(Vector2(pos.x-offset, pos.y));
    if(KeyState[SDL_SCANCODE_W])
        SetPosition(Vector2(pos.x, pos.y-offset));
    if(KeyState[SDL_SCANCODE_S])
        SetPosition(Vector2(pos.x, pos.y+offset));
}

void Piece::Place(){
    std::cout << "Place\n";
}