#include "SunOfNormalObject.hpp"
#include "../GameWorld/GameWorld.hpp"


void SunOfNormalObject::Update() {
  if (GetY() <= 2 * FIRST_ROW_CENTER){
    SetCoolTime(GetCoolTime() + MS_PER_FRAME / 1000.0) ; 
    if (GetCoolTime() >= SUN_COOL_TIME){
      m_gameWorld->RemoveGameObject(PlantsType::SUN, GetX(), GetY());
      SetCoolTime(0);
    }
  }
  else {
    MoveTo(GetX(), GetY() - SUN_FALL_MS_PER_FRAME);
  }
}