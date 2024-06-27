#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>


#include "../Framework/WorldBase.hpp"



#include "../Framework/TextBase.hpp"
#include "utils.hpp"

#include "../GameObject/GameObject.hpp"
#include "../GameObject/BackgroundObject.hpp"
#include "../GameObject/PlantsSeedObject.hpp"
#include "../GameObject/PlantsObject.hpp"
#include "../GameObject/PlantingPosObject.hpp"
#include "../GameObject/SunFlowerObject.hpp"
#include "../GameObject/PeaShooterObject.hpp"
#include "../GameObject/WallNutObject.hpp"
#include "../GameObject/CherryBombObject.hpp"
#include "../GameObject/RepeaterObject.hpp"
#include "../GameObject/ShovelObject.hpp"


class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  using std::enable_shared_from_this<GameWorld>::shared_from_this;
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;
  void ChangeGameObject(PlantsType choosingType, int x, int y);
  void AddGameObject(PlantsType type, int x, int y);
  void RemoveGameObject(int x, int y);
  void ChangeChoosingPlantType(PlantsType type);
  PlantsType GetChoosingPlantType();

private: 
std::list<std::shared_ptr<ObjectBase>> m_GameList;


PlantsType m_PlantTypeChoosingNow = PlantsType::NONE;


inline ImageID ChangePlantsTypeToImageID(PlantsType type);
bool IsPlanted(int x, int y);
};

#endif // !GAMEWORLD_HPP__
