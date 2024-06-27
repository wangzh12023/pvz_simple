#ifndef CherryBombObject_HPP__
#define CherryBombObject_HPP__

#include "PlantsObject.hpp"

class CherryBombObject : public PlantsObject
{ 
public:
  CherryBombObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    PlantsObject(imageID, x, y, layer, width, height, animID) {};

  virtual ~CherryBombObject(){};

  void Update() override{
    return;
  };
  void OnClick() override{
    
    return;
  };

private:

};

#endif // CherryBombObject_HPP__