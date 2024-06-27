#include "SunObject.hpp"
#include "../GameWorld/GameWorld.hpp"
void SunObject::OnClick() {
  m_gameWorld->AddSun(25);
  m_gameWorld->RemoveGameObject(PlantsType::SUN, GetX(), GetY());
}

void SunObject::Update() {

  if (GetY() <= 2 * FIRST_ROW_CENTER){
    m_coolTime += MS_PER_FRAME / 1000.0 ; 
    if (m_coolTime >= SUN_COOL_TIME){
      m_gameWorld->RemoveGameObject(PlantsType::SUN, GetX(), GetY());
      m_coolTime = 0;
    }
  }
  else {
    MoveTo(GetX(), GetY() - SUN_FALL_MS_PER_FRAME);
  }
}