#include "PeaObject.hpp"
#include "GameWorld.hpp"
void PeaObject::Update() {
  if (m_gameWorld->CheckAttackZombie(GetX(), GetY()) || GetX() > WINDOW_WIDTH) {
    m_gameWorld->RemovePea(GetX(), GetY());
  }
  else {
    MoveTo(GetX() + 5, GetY());
  }

}