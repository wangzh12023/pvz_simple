#ifndef SunFlowerObject_HPP__
#define SunFlowerObject_HPP__


#include "PlantsObject.hpp"
class SunFlowerObject : public PlantsObject
{ 
public:
  SunFlowerObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    PlantsObject(imageID, x, y, layer, width, height, animID) {};

  virtual ~SunFlowerObject(){};

  void Update() override{
    return;
  };
  void OnClick() override{
    
    return;
  };

private:

};

#endif // SunFlowerObject_HPP__