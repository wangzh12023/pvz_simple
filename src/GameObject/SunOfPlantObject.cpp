#include "SunOfPlantObject.hpp"
#include "../GameWorld/GameWorld.hpp"


void SunOfPlantObject::Update() {
  SetCoolTime(GetCoolTime() + MS_PER_FRAME / 1000.0) ; 
  if (GetCoolTime() >= SUN_COOL_TIME){
    m_gameWorld->RemoveGameObject(PlantsType::SUN, GetX(), GetY());
    SetCoolTime(0);
  }
}