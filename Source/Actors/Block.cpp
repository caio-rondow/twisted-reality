#include "Block.h"
#include "../Game/ConcreteGame.h"
#include "../Components/DrawComponents/DrawSpriteComponent.h"

#define BLOCK_SIZE 32

Block::Block(InterfaceGame *game, BlockType type):
    Actor(game),
    mType(type),
    mAdjacents(std::vector<Block*>(4, nullptr)) // up, down, left, right
{
    std::string TexturePath = "../Assets/Sprite/NodeDebug/";
    switch (mType)
    {
    case CURSOR:
        TexturePath += "NodeCursor.png";
        break;
    case TUNNEL:
        TexturePath += "NodeTunnel.png";
        break;
    default:
        TexturePath += "Node.png";
        break;
    }

    new DrawSpriteComponent(this, TexturePath, BLOCK_SIZE, BLOCK_SIZE);
}