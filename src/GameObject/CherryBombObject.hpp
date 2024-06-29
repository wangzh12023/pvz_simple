#ifndef CherryBombObject_HPP__
#define CherryBombObject_HPP__

#include "PlantsObject.hpp"
class GameWorld;
class CherryBombObject : public PlantsObject
{ 
public:
  CherryBombObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID,ObjectType objectType,  pGameWorld gameWorld, PlantsType type = PlantsType::CHERRY_BOMB, int hp = 4000, double bombTiime = CHERRY_BOMB_EXPLOSION_TIME):
    PlantsObject(imageID, x, y, layer, width, height, animID,objectType, gameWorld, type, hp), m_bombTime(bombTiime) {};

  virtual ~CherryBombObject(){};

  void Update() override;


private:
  double m_Timer = 0;
  double m_bombTime;

};

#endif // CherryBombObject_HPP__