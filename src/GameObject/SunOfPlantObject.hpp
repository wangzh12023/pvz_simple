#ifndef SunOfPlantObject_HPP__
#define SunOfPlantObject_HPP__

#include "SunObject.hpp"
class GameWorld;
class SunOfPlantObject : public SunObject{
public:
  SunOfPlantObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::SUN):
    SunObject(imageID, x, y, layer, width, height, animID, gameWorld, type) {};

  virtual ~SunOfPlantObject(){};

  void Update() override;
};

#endif // SunOfPlantObject_HPP__