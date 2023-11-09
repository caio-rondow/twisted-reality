#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "../Math.h"
#include "../Components/Component.h"

enum class ActorState{
    ACTIVE,
    PAUSED,
    DESTROY
};

class Component;
class InterfaceGame;

class Actor{ /* This is the actor abstract class */
public:
    Actor(InterfaceGame *game);
    virtual ~Actor();

    void Update(float DeltaTime);
    void ProcessInput(const Uint8* KeyState);
    
    const Vector2 &GetPosition() const;
    void SetPosition(const Vector2&position);
    
    float GetScale() const;
    void SetScale(float scale);

    float GetRotation() const;
    void SetRotation(float rotation);

    ActorState GetActorState() const;
    void SetActorState(ActorState state);

    InterfaceGame *GetGame() const;

    // add collision here...

protected:
    /* PROTECTED METHODS */
    
    /* Specific actor update code */
    virtual void OnUpdate(float DeltaTime) = 0;
    virtual void OnProcessInput(const Uint8 *KeyState) = 0;

    /* PROTECTED ATTRIBUTES */
    InterfaceGame *mGame;
    ActorState mState;
    Vector2 mPosition;
    float mScale;
    float mRotation;
    std::vector<Component*> mComponents;

private:
    /* PRIVATE METHODS */
    friend class Component;
    void AddComponent(Component *c);
};