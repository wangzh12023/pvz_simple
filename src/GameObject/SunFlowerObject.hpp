#ifndef SunFlowerObject_HPP__
#define SunFlowerObject_HPP__


#include "PlantsObject.hpp"

class GameWorld;
class SunFlowerObject : public PlantsObject
{ 
public:
  SunFlowerObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::SUNFLOWER, int hp = 300, int sunFlowerGenerateTime = 5):
    PlantsObject(imageID, x, y, layer, width, height, animID, gameWorld, type, hp), m_sunFlowerGenerateTime(sunFlowerGenerateTime) {};

  virtual ~SunFlowerObject(){};

  void Update() override;


private:
  int m_sunFlowerGenerateTime;
  double m_sunFlowerTimer = 0;
};

#endif // SunFlowerObject_HPP__