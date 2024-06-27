#ifndef PeaShooterObject_HPP__
#define PeaShooterObject_HPP__

#include "PlantsObject.hpp"
class PeaShooterObject : public PlantsObject
{ 
public:
  PeaShooterObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    PlantsObject(imageID, x, y, layer, width, height, animID) {};

  virtual ~PeaShooterObject(){};

  void Update() override{
    return;
  };
  void OnClick() override{
    
    return;
  };

private:

};

#endif // PeaShooterObject_HPP__