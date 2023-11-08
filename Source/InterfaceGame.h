#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>

#include "Math.h"
#include "Actors/Actor.h"

class Actor;

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 4
#define STASH_WIDTH 4
#define STASH_HEIGHT 7

class Game{ /* this is the game interface */
public:
    virtual ~Game() = default;

    /* PUBLIC METHODS */
    virtual bool InitGame() = 0;
    virtual void InitActors() = 0;
    virtual void EnterMainLoop() = 0;
    virtual void ShutDown() = 0;
    virtual void Quit() = 0;
    virtual uint GetWindowWidth() const = 0;
    virtual uint GetWindowHeight() const = 0;
    virtual void AddActor(Actor *actor) = 0;
    virtual void RemoveActor(Actor *actor) = 0;

private:
    /* PRIVATE METHODS */
    virtual void ProcessInput() = 0;
    virtual void UpdateGame() = 0;
    virtual void GenerateOutput() = 0;
};