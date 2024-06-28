#ifndef RepeaterObject_HPP__
#define RepeaterObject_HPP__

#include "PlantsObject.hpp"
class RepeaterObject : public PlantsObject
{ 
public:
  RepeaterObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::REPEATER, int hp = 300):
    PlantsObject(imageID, x, y, layer, width, height, animID, gameWorld, type,hp) {};

  virtual ~RepeaterObject(){};

  void Update() override;


private:

};

#endif // RepeaterObject_HPP__