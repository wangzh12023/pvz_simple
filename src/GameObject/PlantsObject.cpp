#include "PlantsObject.hpp"
#include "../GameWorld/GameWorld.hpp"
void PlantsObject::OnClick() {
  m_gameWorld->RemoveGameObject(m_gameWorld->GetChoosingPlantType(), GetX(), GetY());
}