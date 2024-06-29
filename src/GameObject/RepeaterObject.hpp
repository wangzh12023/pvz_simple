#ifndef RepeaterObject_HPP__
#define RepeaterObject_HPP__

#include "PlantsObject.hpp"
class RepeaterObject : public PlantsObject
{ 
public:
  RepeaterObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, ObjectType objectType, pGameWorld gameWorld, PlantsType type = PlantsType::REPEATER, int hp = 300, int coolTime = PEAS_COOLDOWN, double interval = PEAS_INTERVAL):
    PlantsObject(imageID, x, y, layer, width, height, animID, objectType, gameWorld, type,hp) , m_coolTime(coolTime), m_interval(interval){};

  virtual ~RepeaterObject(){};

  void Update() override;


private:
  int m_coolTime;
  double m_lastTime = 0;
  double m_interval;
  double m_lastTime2 = - m_interval;
};
#endif // RepeaterObject_HPP__