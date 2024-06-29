#ifndef Bomb_HPP__
#define Bomb_HPP__

#include "GameObject.hpp"

class GameWorld;
class Bomb : public GameObject{
public:
  Bomb(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, ObjectType objectType, pGameWorld gameWorld, double bombTime = CHERRY_BOMB_TIME):
    GameObject(imageID, x, y, layer, width, height, animID, objectType), m_gameWorld(gameWorld),m_bombTime(bombTime){};

  virtual ~Bomb(){};

  void Update() override;
  void OnClick() override{};

private:
  pGameWorld m_gameWorld;
  double m_Timer = 0;
  double m_bombTime;

};

#endif // Bomb_HPP__