#ifndef CherryBombObject_HPP__
#define CherryBombObject_HPP__

#include "PlantsObject.hpp"

class CherryBombObject : public PlantsObject
{ 
public:
  CherryBombObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::CHERRY_BOMB):
    PlantsObject(imageID, x, y, layer, width, height, animID, gameWorld, type) {};

  virtual ~CherryBombObject(){};

  void Update() override{
    return;
  };


private:

};

#endif // CherryBombObject_HPP__