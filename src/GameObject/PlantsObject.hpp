#ifndef PlantsObject_HPP__
#define PlantsObject_HPP__
#include "GameObject.hpp"


class PlantsObject : public GameObject
{
public:
  PlantsObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, ObjectType objectType, pGameWorld gameWorld, PlantsType type, int hp):
    GameObject(imageID, x, y, layer, width, height, animID, objectType), m_gameWorld(gameWorld), m_type(type), m_hp(hp){};

  virtual ~PlantsObject(){};

  void Update() override{
    return;
  };
  void ManageAttack();
  void OnClick() override;
  void SetHP(int hp);
  int GetHP() const{
    return m_hp;
  }

protected:
  pGameWorld m_gameWorld;
private:
  
  PlantsType m_type;
  int m_hp;

};

#endif // !PlantsObject_HPP__