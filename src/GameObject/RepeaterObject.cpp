#include "RepeaterObject.hpp"


void RepeaterObject::Update() {
  ManageAttack();

  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}