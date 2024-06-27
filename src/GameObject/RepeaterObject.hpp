#ifndef RepeaterObject_HPP__
#define RepeaterObject_HPP__

#include "PlantsObject.hpp"
class RepeaterObject : public PlantsObject
{ 
public:
  RepeaterObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::REPEATER):
    PlantsObject(imageID, x, y, layer, width, height, animID, gameWorld, type) {};

  virtual ~RepeaterObject(){};

  void Update() override{
    return;
  };


private:

};

#endif // RepeaterObject_HPP__