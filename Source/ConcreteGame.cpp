#include "ConcreteGame.h"

/* PUBLIC METHODS */

/* Constructors */
ConcreteGame::ConcreteGame(uint WindowWidth, uint WindowHeight):
    mTicksCount(0),
    mIsRunning(true),
    mWindow(nullptr),
    mRenderer(nullptr),
    mIsUpdatingActors(false),
    mWindowWidth(WindowWidth),
    mWindowHeight(WindowHeight)
{

}

/* Game Loop */
bool ConcreteGame::InitGame(){
    
    if( SDL_Init(SDL_INIT_VIDEO) != 0 ){
        std::cerr << "In Bool ConcreteGame::InitGame()\n";
        SDL_Log("Could not initialize SDL: %s", SDL_GetError());
        return false;
    }

    /* Create window and renderer*/
    mWindow = SDL_CreateWindow("Twisted Reality", 0, 0, GetWindowWidth(), GetWindowWidth(), 0);
    if(!mWindow){
        std::cerr << "In Bool ConcreteGame::InitGame()\n";
        SDL_Log("Could not initialize SDL window: %s", SDL_GetError());
        return false;
    }
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!mRenderer){
        std::cerr << "In Bool ConcreteGame::InitGame()\n";
        SDL_Log("Could not initialize SDL renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void ConcreteGame::InitActors(){
    // Create actors here...
}

void ConcreteGame::EnterMainLoop(){
    while(mIsRunning){
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void ConcreteGame::ShutDown(){
    // also delete all actors here...
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void ConcreteGame::Quit(){
    mIsRunning = false;
}

/* Game Window */
uint ConcreteGame::GetWindowWidth() const{
    return mWindowWidth;
}

uint ConcreteGame::GetWindowHeight() const{
    return mWindowHeight;
}

/* Actors */
void ConcreteGame::AddActor(Actor *actor){
    if(mIsUpdatingActors){
        mPendingActors.emplace_back(actor);
    } else{
        mActors.emplace_back(actor);
    }
}

void ConcreteGame::RemoveActor(Actor *actor){
    auto it = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
    if(it != mPendingActors.end()){
        std::iter_swap(it, mPendingActors.end()-1);
        mPendingActors.pop_back();
    }

    it = std::find(mActors.begin(), mActors.end(), actor);
    if(it != mActors.end()){
        std::iter_swap(it, mActors.end()-1);
        mActors.pop_back();
    }
}

/* PRIVATE METHODS */
void ConcreteGame::ProcessInput(){
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

void ConcreteGame::UpdateGame(){
    // update actors here...
}

void ConcreteGame::GenerateOutput(){
    /* Set draw color */
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    /* Clear the current rendering */
    SDL_RenderClear(mRenderer);
    /* Swap front and back buffers - actually rendering */
    SDL_RenderPresent(mRenderer);
}
