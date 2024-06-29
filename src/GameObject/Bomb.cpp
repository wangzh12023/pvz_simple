#include "Bomb.hpp"
#include "GameWorld.hpp"

void Bomb::Update() {
  m_Timer += MS_PER_FRAME / 1000.0;
  if (m_Timer > m_bombTime){
    m_gameWorld->RemoveBomb(GetX(), GetY());
  }
}