#ifndef CherryBombObject_HPP__
#define CherryBombObject_HPP__

#include "PlantsObject.hpp"

class CherryBombObject : public PlantsObject
{ 
public:
  CherryBombObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,ObjectType objectType,  pGameWorld gameWorld, PlantsType type = PlantsType::CHERRY_BOMB, int hp = 4000):
    PlantsObject(imageID, x, y, layer, width, height, animID,objectType, gameWorld, type, hp) {};

  virtual ~CherryBombObject(){};

  void Update() override;


private:

};

#endif // CherryBombObject_HPP__