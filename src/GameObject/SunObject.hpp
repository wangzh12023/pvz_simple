#ifndef SunObject_HPP__
#define SunObject_HPP__

#include "GameObject.hpp"
class GameWorld;
class SunObject : public GameObject{
public:
  SunObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, PlantsType type = PlantsType::SUN):
    GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld), m_type(type) {};

  virtual ~SunObject(){};

  void Update() override = 0;
  void OnClick() override;

  void SetCoolTime(double coolTime){
    m_coolTime = coolTime;
  }

  double GetCoolTime() const{
    return m_coolTime;
  }
protected:
  pGameWorld m_gameWorld;
private:
  PlantsType m_type;
  double m_coolTime = 0;
  
};

#endif // SunObject_HPP__