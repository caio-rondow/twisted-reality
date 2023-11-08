#include "Game.h"

const uint SCREEN_WIDTH = 800;
const uint SCREEN_HEIGHT = 600;

int main(int argc, char **argv){

    Game TwistedReality(SCREEN_WIDTH, SCREEN_HEIGHT);
    bool Success = TwistedReality.InitGame();
    if(Success){
        TwistedReality.EnterMainLoop();
    }
    TwistedReality.ShutDown();

    return 0;
}