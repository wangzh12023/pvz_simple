#ifndef PlantsSeedObject_HPP__
#define PlantsSeedObject_HPP__
#include "GameObject.hpp"
class GameWorld;
class PlantsSeedObject : public GameObject {
public:
  PlantsSeedObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, int sunCost, int coolTime, PlantsType type, pGameWorld gameWorld ):
    GameObject(imageID, x, y, layer, width, height, animID), m_sunCost(sunCost), m_coolTime(coolTime), m_type(type), m_gameWorld(gameWorld) {};

  virtual ~PlantsSeedObject(){};

  void Update() override{
    return;
  };
  void OnClick() override;
private:
  // YOUR CODE HERE
  int m_sunCost;
  int m_coolTime;
  PlantsType m_type;
  pGameWorld m_gameWorld;
  bool m_isCooling = false;
  

};



#endif // !PlantsSeedObject_HPP__