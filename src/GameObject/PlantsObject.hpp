#ifndef PlantsObject_HPP__
#define PlantsObject_HPP__
#include "GameObject.hpp"


class PlantsObject : public GameObject
{
public:
  PlantsObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type):
    GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld), m_type(){};

  virtual ~PlantsObject(){};

  void Update() override{
    return;
  };
  void OnClick() override;

private:
  pGameWorld m_gameWorld;
  PlantsType m_type;
};

#endif // !PlantsObject_HPP__