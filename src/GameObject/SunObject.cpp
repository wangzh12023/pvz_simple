#include "SunObject.hpp"
#include "../GameWorld/GameWorld.hpp"
void SunObject::OnClick() {
  m_gameWorld->AddSun(25);
  m_gameWorld->RemoveGameObject(PlantsType::SUN, GetX(), GetY());
}

void SunObject::Update() {

  if (GetY() <= 2 * FIRST_ROW_CENTER) return;
  else {
    MoveTo(GetX(), GetY() - SUN_FALL_MS_PER_FRAME);
  }
}