#include "SunObject.hpp"
#include "../GameWorld/GameWorld.hpp"
void SunObject::OnClick() {
  m_gameWorld->AddSun(25);
  m_gameWorld->RemoveGameObject(PlantsType::SUN, GetX(), GetY());
}

