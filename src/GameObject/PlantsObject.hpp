#ifndef PlantsObject_HPP__
#define PlantsObject_HPP__
#include "GameObject.hpp"


class PlantsObject : public GameObject
{
public:
  PlantsObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    GameObject(imageID, x, y, layer, width, height, animID) {};

  virtual ~PlantsObject(){};

  void Update() override{
    return;
  };
  void OnClick() override{
    
    return;
  };

private:
  
  };

#endif // !PlantsObject_HPP__