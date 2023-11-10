#pragma once

#include "Actor.h"

class InterfaceGame;

enum class PieceState{
    MOVE,
    ROTATE,
    FLIP,
    PLACE,
    IDLE
};

class Piece : public Actor{
public:
    explicit Piece(InterfaceGame *game, char type, const Vector2&origin, float rotation, bool flip);

    /* PUBLIC METHODS */
    void OnUpdate(float DeltaTime) override;
    void OnProcessInput(const Uint8 *KeyState) override;
    /* Piece methods */
    void Rotate(const Uint8 *KeyState);
    void Flip(const Uint8 *KeyState);
    void Move(const Uint8 *KeyState);
    void Place();

private:
    bool mFlip;
    char mType;
    PieceState mState;
};