#ifndef PeaShooterObject_HPP__
#define PeaShooterObject_HPP__

#include "PlantsObject.hpp"
class GameManager;
class PeaShooterObject : public PlantsObject
{ 
public:
  PeaShooterObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,ObjectType objectType,  pGameWorld gameWorld, PlantsType type = PlantsType::PEASHOOTER, int hp = 300, int coolTime = PEAS_COOLDOWN):
    PlantsObject(imageID, x, y, layer, width, height, animID,objectType, gameWorld, type, hp), m_coolTime(coolTime) {};

  virtual ~PeaShooterObject(){};

  void Update() override;


private:
 int m_coolTime;
 double m_lastTime = 0;

};

#endif // PeaShooterObject_HPP__