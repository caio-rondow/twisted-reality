#pragma once

#include "Actor.h"

class InterfaceGame;

class Piece : public Actor{
public:
    explicit Piece(InterfaceGame *game, char type, const Vector2&origin, float rotation, bool flip);

    /* PUBLIC METHODS */
    void OnUpdate(float DeltaTime) override;
    void OnProcessInput(const Uint8 *KeyState) override;

private:
    bool mFlip;
    char mType;
};