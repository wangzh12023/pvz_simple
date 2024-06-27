#include "PlantsSeedObject.hpp"
#include "../GameWorld/GameWorld.hpp"


void PlantsSeedObject::OnClick() {
  if (m_isCooling) return;

  if(m_type == PlantsType::SUNFLOWER){
    m_gameWorld->ChangeChoosingPlantType(PlantsType::SUNFLOWER);
  }
  else if(m_type == PlantsType::PEASHOOTER){
    m_gameWorld->ChangeChoosingPlantType(PlantsType::PEASHOOTER);
  }
  else if(m_type == PlantsType::WALLNUT){
    m_gameWorld->ChangeChoosingPlantType(PlantsType::WALLNUT);
  }
  else if(m_type == PlantsType::CHERRY_BOMB){
    m_gameWorld->ChangeChoosingPlantType(PlantsType::CHERRY_BOMB);
  }
  else if(m_type == PlantsType::REPEATER){
    m_gameWorld->ChangeChoosingPlantType(PlantsType::REPEATER);
  }

}

