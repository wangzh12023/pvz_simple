#include "CherryBombObject.hpp"
#include "GameWorld.hpp"

void CherryBombObject::Update() {
  m_Timer += MS_PER_FRAME / 1000.0;
  if (m_Timer > m_bombTime){
    m_gameWorld->AddBomb(GetX(), GetY());
    m_gameWorld->CherryBombAttack(GetX(), GetY());
    m_gameWorld->RemoveCherryBomb(GetX(), GetY());

    
    
  }
  
  ManageAttack();

  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}