#ifndef SunOfNormalObject_HPP__
#define SunOfNormalObject_HPP__

#include "SunObject.hpp"
class GameWorld;
class SunOfNormalObject : public SunObject{
public:
  SunOfNormalObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::SUN):
    SunObject(imageID, x, y, layer, width, height, animID, gameWorld, type) {};

  virtual ~SunOfNormalObject(){};

  void Update() override;
};

#endif // SunOfNormalObject_HPP__