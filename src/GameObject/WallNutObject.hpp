#ifndef WallNutObject_HPP__
#define WallNutObject_HPP__




#include "PlantsObject.hpp"
class WallNutObject : public PlantsObject
{ 
public:
  WallNutObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    PlantsObject(imageID, x, y, layer, width, height, animID) {};

  virtual ~WallNutObject(){};

  void Update() override{
    return;
  };
  void OnClick() override{
    
    return;
  };

private:

};

#endif // WallNutObject_HPP__