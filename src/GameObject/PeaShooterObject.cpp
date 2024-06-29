#include "PeaShooterObject.hpp"
#include "GameWorld.hpp"

void PeaShooterObject::Update() {
  m_lastTime += MS_PER_FRAME / 1000.0;

  if (m_gameWorld->IfTheRowForwardHasZombie(GetX(), GetY()) && m_lastTime >= m_coolTime){
    m_gameWorld->AddPea(GetX() + 30, GetY() + 20);
    m_lastTime = 0;
  }
  ManageAttack();
  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}