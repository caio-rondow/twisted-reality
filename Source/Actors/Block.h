#pragma once 

#include "Actor.h"

#define UP 0
#define DOWN 1
#define LEFT 2 
#define RIGHT 3 

class Block : public Actor{
public:
    enum BlockType{
        DEFAULT, CURSOR, TUNNEL
    };
    explicit Block(InterfaceGame *game, BlockType type=DEFAULT);
    /* Add adjacenct blocks */
    inline void Link(Block *adj, uint dir){
        if(dir >= 0 && dir < 4)
            mAdjacents[dir] = adj;
        else{
            std::cerr << "invalid position.\n";
            exit(EXIT_FAILURE);
        }
    }
    Block *operator[](uint dir) const{
        return mAdjacents[dir];
    }

private:
    BlockType mType;
    std::vector<Block*> mAdjacents;
};