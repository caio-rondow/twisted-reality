#include "Block.h"
#include "../Game/ConcreteGame.h"
#include "../Components/DrawComponents/DrawAnimatedComponent.h"

#define BLOCK_SIZE 32

Block::Block(InterfaceGame *game, BlockType type):
    Actor(game),
    mType(type),
    mIsSelected(false),
    mAdjacents(std::vector<Block*>(4, nullptr)) // up, down, left, right
{
    std::string spritesheet = "../Assets/Sprite/NodeDebug/DebugSpriteSheet.jpg";
    std::string spritedata  = "../Assets/Sprite/NodeDebug/DebugSpriteSheet.json";

    mDrawComponent = new DrawAnimatedComponent(this, spritesheet, spritedata);
    mDrawComponent->AddAnimation("idle", {0});
    mDrawComponent->AddAnimation("cursor", {2});
    mDrawComponent->SetAnimation("idle");
    mDrawComponent->SetAnimationFPS(10);
}

void Block::OnUpdate(float DeltaTime){
    if(mIsSelected){
        mDrawComponent->SetAnimation("cursor");
    } else{
        mDrawComponent->SetAnimation("idle");
    }
}