#include "DrawComponent.h"

/* CONSTUCTOR AND DESTRUCTOR */
DrawComponent::DrawComponent(Actor *owner, int DrawOrder):
    Component(owner),
    mDrawOrder(DrawOrder),
    mState(DRAWABLE_STATE_VISIBLE)
{
    // mOwner->AddDrawable(this);
}

DrawComponent::~DrawComponent(){
    // mOwner->RemoveDrawable(this);
}

/* PUBLIC METHODS */
void DrawComponent::Update(float DeltaTime){

}

void DrawComponent::ProcessInput(const Uint8 *KeyState){

}

void DrawComponent::Draw(SDL_Renderer *renderer){

}

bool DrawComponent::IsVisible() const{
    return mState;
}

void DrawComponent::SetDrawableState(bool state){
    mState = state;
}

int DrawComponent::GetDrawOrder() const{
    return mDrawOrder;
}