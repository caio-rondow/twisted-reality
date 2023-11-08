#include "Actor.h"

/* CONSTRUCTORS AND DESTRUCTOR */
Actor::Actor(Game *game):
    mGame(game),
    mScale(1.0f),
    mRotation(0.0f),
    mPosition(Vector2::Zero),
    mState(ActorState::ACTIVE)
{
    mGame->AddActor(this);
}

Actor::~Actor(){
    mGame->RemoveActor(this);
    // for(auto component : mComponents){
    //     delete component;
    // }
}

/* PUBLIC METHODS */
    
/* Generic actor update code */
void Actor::Update(float DeltaTime){

    if(mState == ActorState::ACTIVE){
        // for(auto component : mComponents){
        //     if( component->IsEnabled() ){
        //         component->Update(DeltaTime);
        //     }
        // }
        OnUpdate(DeltaTime); // update specific task
    }
}

void Actor::ProcessInput(const Uint8 *KeyState){
    if(mState == ActorState::ACTIVE){
        // for(auto component : mComponents){
        //     if( component->IsEnabled() ){
        //         component->ProcessInput(KeyState);
        //     }
        // }
        OnProcessInput(KeyState); // process specific task
    }
}

/* Getters and Setters */
/* Position */
const Vector2 &Actor::GetPosition() const{
    return mPosition;
}

void Actor::SetPosition(const Vector2&position){
    mPosition = position;
}

/* Scale */
float Actor::GetScale() const{
    return mScale;
}

void Actor::SetScale(float scale){
    mScale = scale;
}

/* Rotation */
float Actor::GetRotation() const{
    return mRotation;
}

void Actor::SetRotation(float rotation){
    mRotation = rotation;
}

/* Actor State */
ActorState Actor::GetActorState() const{
    return mState;
}

void Actor::SetActorState(ActorState state){
    mState = state;
}

/* Game */
const Game &Actor::GetGame() const{
    return *mGame;
}

/* PROTECTED METHODS */

/* Specific actor update code */
void Actor::OnUpdate(float DeltaTime){

}

void Actor::OnProcessInput(const Uint8 *KeyState){

}