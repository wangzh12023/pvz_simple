#ifndef WallNutObject_HPP__
#define WallNutObject_HPP__




#include "PlantsObject.hpp"
class WallNutObject : public PlantsObject
{ 
public:
  WallNutObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::WALLNUT, int hp = 4000):
    PlantsObject(imageID, x, y, layer, width, height, animID, gameWorld, type, hp) {};

  virtual ~WallNutObject(){};

  void Update() override;


private:

};

#endif // WallNutObject_HPP__