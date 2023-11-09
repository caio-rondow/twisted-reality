#include "Piece.h"
#include "../Components/DrawComponents/DrawSpriteComponent.h"

Piece::Piece(InterfaceGame *game, char type, const Vector2&origin, float rotation, bool flip):
    Actor(game),
    mType(type),
    mFlip(flip)
{
    this->SetPosition(origin);
    this->SetRotation(rotation);
    new DrawSpriteComponent(this, "../Assets/Sprite/Block.png", 32, 32);
}

void Piece::OnUpdate(float DeltaTime){
    // std::cout << "update piece!\n";
}

void Piece::OnProcessInput(const Uint8 *KeyState){
    
    Vector2 pos = this->GetPosition();
    float offset = 5.0f;

    if(KeyState[SDL_SCANCODE_W]){
        this->SetPosition(Vector2(pos.x,(pos.y-offset)));
    }

    if(KeyState[SDL_SCANCODE_A]){
        this->SetPosition(Vector2((pos.x-offset), pos.y));
    }

    if(KeyState[SDL_SCANCODE_S]){
        this->SetPosition(Vector2(pos.x, (pos.y+offset)));
    }

    if(KeyState[SDL_SCANCODE_D]){
        this->SetPosition(Vector2((pos.x+offset), pos.y));
    }
}