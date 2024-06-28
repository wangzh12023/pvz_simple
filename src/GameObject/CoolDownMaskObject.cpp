#include "CoolDownMaskObject.hpp"
#include "../GameWorld/GameWorld.hpp"



void CoolDownMaskObject::Update() {
  m_coolDownTime -= MS_PER_FRAME / 1000.0 ; 
  if (m_coolDownTime <= 0){
    m_gameWorld->RemoveMask(GetX(), GetY());
  }
}