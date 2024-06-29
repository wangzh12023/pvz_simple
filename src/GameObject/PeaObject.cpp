#include "PeaObject.hpp"
#include "GameWorld.hpp"
void PeaObject::Update() {
  if (m_gameWorld->CheckAttackZombie(GetX(), GetY())) {
    m_gameWorld->RemovePea(GetX(), GetY());
  }

}