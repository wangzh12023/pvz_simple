#include "SunFlowerObject.hpp"  
#include "GameWorld.hpp"

void SunFlowerObject::Update() {
  m_sunFlowerTimer += MS_PER_FRAME / 1000.0;
  if (m_sunFlowerTimer >= SUN_FLOWER_GENERATE_TIME) {
    m_gameWorld->AddSunOfPlant(GetX() + 20, GetY() - 20);
    m_sunFlowerTimer = 0;
  }
  ManageAttack();

  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}