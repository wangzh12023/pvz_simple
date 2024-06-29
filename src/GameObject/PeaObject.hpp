#ifndef PeaObject_HPP__
#define PeaObject_HPP__

#include "GameObject.hpp"
class GameWorld;
class PeaObject : public GameObject{
public:
  PeaObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, ObjectType objectType, pGameWorld gameWorld):
    GameObject(imageID, x, y, layer, width, height, animID, objectType), m_gameWorld(gameWorld){};

  virtual ~PeaObject(){};

  void Update() override;
  void OnClick() override{};

private:
  pGameWorld m_gameWorld;

};

#endif // PeaObject_HPP__