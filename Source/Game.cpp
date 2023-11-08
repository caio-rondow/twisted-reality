#include "Game.h"

/* GAME CONSTUCTOR */
Game::Game(uint WindowWidth, uint WindowHeight):
    mIsRunning(true),
    mWindow(nullptr),
    mRenderer(nullptr),
    mWindowWidth(WindowWidth),
    mWindowHeight(WindowHeight)
{

}

/* PUBLIC METHODS */
bool Game::InitGame(){
    
    if( SDL_Init(SDL_INIT_VIDEO) != 0 ){
        std::cerr << "In Bool Game::InitGame()\n";
        SDL_Log("Could not initialize SDL: %s", SDL_GetError());
        return false;
    }

    /* Create window and renderer*/
    mWindow = SDL_CreateWindow("Twisted Reality", 0, 0, GetWindowWidth(), GetWindowWidth(), 0);
    if(!mWindow){
        std::cerr << "In Bool Game::InitGame()\n";
        SDL_Log("Could not initialize SDL window: %s", SDL_GetError());
        return false;
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!mRenderer){
        std::cerr << "In Bool Game::InitGame()\n";
        SDL_Log("Could not initialize SDL renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::EnterMainLoop(){
    while(mIsRunning){
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ShutDown(){
    // also delete all actors here...
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::Quit(){
    mIsRunning = false;
}

uint Game::GetWindowWidth() const{
    return mWindowWidth;
}

uint Game::GetWindowHeight() const{
    return mWindowHeight;
}

/* PRIVATE METHODS */
void Game::ProcessInput(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch (event.type)
        {
        case SDL_QUIT:
            Quit();
            break;
        }
    }
    const Uint8 *state = SDL_GetKeyboardState(nullptr);
    // process actor's input here...
}

void Game::UpdateGame(){
    // update actors here...
}

void Game::GenerateOutput(){
    /* Set draw color */
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    /* Clear the current rendering */
    SDL_RenderClear(mRenderer);
    /* Swap front and back buffers - actually rendering */
    SDL_RenderPresent(mRenderer);
}
