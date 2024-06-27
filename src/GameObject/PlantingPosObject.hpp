#ifndef PlantingPosObject_HPP__
#define PlantingPosObject_HPP__

#include "GameObject.hpp"
#include "../GameWorld/GameWorld.hpp"

class GameWorld;
class PlantingPosObject : public GameObject{ 
public:
  PlantingPosObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld):
    GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld){};
  virtual ~PlantingPosObject(){};
  void Update() override{
    return;
  };
  void OnClick() override;
private:
  pGameWorld m_gameWorld;


};






#endif // !PlantingPosObject_HPP__