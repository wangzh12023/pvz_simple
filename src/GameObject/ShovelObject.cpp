#include "ShovelObject.hpp"
#include "../GameWorld/GameWorld.hpp"
void ShovelObject::OnClick() {
  m_gameWorld->ChangeChoosingPlantType(PlantsType::SHOVEL);
}