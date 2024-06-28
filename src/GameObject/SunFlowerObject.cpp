#include "SunFlowerObject.hpp"  


void SunFlowerObject::Update() {
  m_sunFlowerTimer += MS_PER_FRAME / 1000.0;
  if (m_sunFlowerTimer >= SUN_FLOWER_GENERATE_TIME) {
    m_gameWorld->AddGameObject(PlantsType::SUN, GetX(), GetY());
    m_sunFlowerTimer = 0;
  }
  ManageAttack();

  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}