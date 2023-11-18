#pragma once

#include "Actor.h"

class Block;

class Table : public Actor{
public:
    Table(InterfaceGame *game, uint width, uint height);
    void OnProcessInput(const Uint8 *KeyState) override;
private:
    Block *mCursor;
    std::vector<std::vector<Block*>>mTable;
    uint mTableWidth, mTableHeight;
};