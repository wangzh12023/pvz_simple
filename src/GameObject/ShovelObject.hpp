#ifndef SHOVELOBJECT_HPP
#define SHOVELOBJECT_HPP

#include "GameObject.hpp"

class ShovelObject : public GameObject{
public:
  ShovelObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld):
    GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld){};

  virtual ~ShovelObject(){};

  void Update() override{
    return;
  };
  void OnClick() override;

private:
  pGameWorld m_gameWorld;
};

#endif // SHOVELOBJECT_HPP











