#include "CherryBombObject.hpp"


void CherryBombObject::Update() {
  ManageAttack();
  
  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}