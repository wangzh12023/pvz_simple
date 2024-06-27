#include "PlantingPosObject.hpp"
#include "../GameWorld/GameWorld.hpp"
void PlantingPosObject::OnClick() {
  m_gameWorld->ChangeGameObject(m_gameWorld->GetChoosingPlantType(), GetX(), GetY());
}
