#ifndef CoolDownMaskObject_HPP__
#define CoolDownMaskObject_HPP__
#include "GameObject.hpp"

class GameWorld;
class CoolDownMaskObject : public GameObject{

public:
  CoolDownMaskObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int coolDownTime, PlantsType type = PlantsType::NONE):
    GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld), m_coolDownTime(coolDownTime), m_type(type){};

  virtual ~CoolDownMaskObject(){};

  void Update() override;
  void OnClick() override{return;};

private:
  pGameWorld m_gameWorld;
  int m_coolDownTime;
  PlantsType m_type;


};





#endif // !CoolDownMaskObject_HPP__
