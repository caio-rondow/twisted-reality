#pragma once

#include "InterfaceGame.h"

class ConcreteGame : public InterfaceGame{
public:
    /* PUBLIC METHODS */
    
    /* Constructors */
    ConcreteGame(uint WindowWidth, uint WindowHeight);
    /* Game Loop */
    bool InitGame() override;
    void InitActors() override;
    void EnterMainLoop() override;
    void ShutDown() override;
    void Quit() override;
    /* Game Window */
    uint GetWindowWidth() const override;
    uint GetWindowHeight() const override;
    /* Actors */
    void AddActor(Actor *actor) override;
    void RemoveActor(Actor *actor) override;
    /* Load methods */
    SDL_Texture *LoadTexture(const std::string&TextureFile) const override;

private:
    /* PRIVATE METHODS */
    void ProcessInput() override;
    void UpdateGame() override;
    void GenerateOutput() override;

    /* PRIVATE ATTRIBUTES */

    /* Game properties */
    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;
    uint mWindowWidth, mWindowHeight;
    bool mIsRunning, mIsUpdatingActors;
    Uint32 mTicksCount;
    /* Game Actors */
    std::vector<Actor*> mActors;
    std::vector<Actor*> mPendingActors;
};