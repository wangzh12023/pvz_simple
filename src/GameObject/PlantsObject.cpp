#include "PlantsObject.hpp"
#include "../GameWorld/GameWorld.hpp"
void PlantsObject::OnClick() {
  m_gameWorld->RemoveGameObject(m_gameWorld->GetChoosingPlantType(), GetX(), GetY());
}

void PlantsObject::SetHP(int hp){
    m_hp = hp;
}

void PlantsObject::ManageAttack(){
  if (GetStatus() == true){
    m_hp -= 3;
    ChangeStatus(false);
  }
}





