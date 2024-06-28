#include "WallNutObject.hpp"

void WallNutObject::Update() {
  ManageAttack();
  if (GetHP() <= 1000) {
    ChangeImage(IMGID_WALLNUT_CRACKED);
  }
  if (GetHP() <= 0) {
    ChangeIfDead(true);
  }

}