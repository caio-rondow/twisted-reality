#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <SDL2/SDL.h>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 4
#define STASH_WIDTH 4
#define STASH_HEIGHT 7

class Game{
public:
    /* GAME CONSTUCTOR */
    Game(uint WindowWidth, uint WindowHeight);

    /* PUBLIC METHODS */
    bool InitGame();
    void EnterMainLoop();
    void ShutDown();
    void Quit();
    uint GetWindowWidth() const;
    uint GetWindowHeight() const;

private:
    /* PRIVATE METHODS */
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    SDL_Window *mWindow;
    SDL_Renderer *mRenderer;

    uint mWindowWidth, mWindowHeight;
    bool mIsRunning;
};