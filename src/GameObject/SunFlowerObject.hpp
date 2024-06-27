#ifndef SunFlowerObject_HPP__
#define SunFlowerObject_HPP__


#include "PlantsObject.hpp"
class SunFlowerObject : public PlantsObject
{ 
public:
  SunFlowerObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::SUNFLOWER):
    PlantsObject(imageID, x, y, layer, width, height, animID, gameWorld, type) {};

  virtual ~SunFlowerObject(){};

  void Update() override{
    return;
  };


private:

};

#endif // SunFlowerObject_HPP__