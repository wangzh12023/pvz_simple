#ifndef PeaShooterObject_HPP__
#define PeaShooterObject_HPP__

#include "PlantsObject.hpp"
class PeaShooterObject : public PlantsObject
{ 
public:
  PeaShooterObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::PEASHOOTER, int hp = 300):
    PlantsObject(imageID, x, y, layer, width, height, animID, gameWorld, type, hp) {};

  virtual ~PeaShooterObject(){};

  void Update() override;


private:

};

#endif // PeaShooterObject_HPP__