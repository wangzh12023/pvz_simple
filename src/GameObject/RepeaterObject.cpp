#include "RepeaterObject.hpp"
#include "GameWorld.hpp"

void RepeaterObject::Update() {
  m_lastTime += MS_PER_FRAME / 1000.0;
  m_lastTime2 += MS_PER_FRAME / 1000.0;
  if (m_gameWorld->IfTheRowForwardHasZombie(GetX(), GetY())){
    if (m_lastTime >= m_coolTime){
      m_gameWorld->AddPea(GetX() + 30, GetY() + 20);
      m_lastTime = 0;
    }
    if (m_lastTime2 >= m_coolTime){
      m_gameWorld->AddPea(GetX() + 30, GetY() + 20);
      m_lastTime2 = 0;
    }
  }
  ManageAttack();

  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}


