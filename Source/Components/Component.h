#pragma once

#include "../InterfaceGame.h"

// class Actor;

enum class ComponentState{
    DISABLE,
    ENABLE
};

class Component{ /* This is the Component abstract class */ 
public:
    /* CONSTRUCTOR AND DESTRUCTOR */
    explicit Component(Actor *owner, int UpdateOrder=10);
    virtual ~Component();    

    /* PUBLIC METHODS */
    
    /* Component specific */
    virtual void Update(float DeltaTime) = 0;
    virtual void ProcessInput(const Uint8 *KeyState) = 0;
    /* Actor related */
    int GetUpdateOrder() const;
    const Actor &GetOwner() const;
    /* Component state */
    void SetComponentState(ComponentState state);
    bool IsComponentEnabled() const;

protected:
    /* PROTECTED ATTRIBUTES */
    Actor *mOwner;
    int mUpdateOrder;
    ComponentState mState;
};