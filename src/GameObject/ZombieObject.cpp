#include "ZombieObject.hpp"
#include "../GameWorld/GameWorld.hpp"

void BucketHeadZombieObject::Update() {
  if (GetStatus() == true){
    SetHP(GetHP() -  PEAS_DAMAGE);
    ChangeStatus(false);
  }
  if (GetHP() <= 0){
      ChangeIfDead(true);
    }
  if (GetHP() <= 200) {
    ChangeImage(IMGID_REGULAR_ZOMBIE);
  }

  if (m_gameWorld->CollideCheck(GetX(), GetY())){
    if (GetCurrentAnimation() != ANIMID_EAT_ANIM){
      PlayAnimation(ANIMID_EAT_ANIM);
      
    }
    m_gameWorld->AttackPlant(GetX(), GetY());
  }
  else{
    if(GetCurrentAnimation() != ANIMID_WALK_ANIM){
      PlayAnimation(ANIMID_WALK_ANIM);
    }
    MoveTo(GetX() - 1, GetY());
  }
}

void RegularZombieObject::Update() {
  if (GetStatus() == true){

    SetHP(GetHP() - PEAS_DAMAGE);
    if (GetHP() <= 0){
      ChangeIfDead(true);
    }
    ChangeStatus(false);
  }

  if (m_gameWorld->CollideCheck(GetX(), GetY())){
    if (GetCurrentAnimation() != ANIMID_EAT_ANIM){
      PlayAnimation(ANIMID_EAT_ANIM);
    }
    m_gameWorld->AttackPlant(GetX(), GetY());
  }
  else{
    if(GetCurrentAnimation() != ANIMID_WALK_ANIM){
      PlayAnimation(ANIMID_WALK_ANIM);
    }
    MoveTo(GetX() - 1, GetY());
  }
}
