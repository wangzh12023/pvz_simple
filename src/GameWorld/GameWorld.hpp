#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "../GameObject/GameObject.hpp"
#include "../Framework/WorldBase.hpp"



#include "../Framework/TextBase.hpp"
#include "utils.hpp"

#include "../GameObject/BackgroundObject.hpp"


class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  using std::enable_shared_from_this<GameWorld>::shared_from_this;
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

private: 
std::list<std::shared_ptr<ObjectBase>> m_GameList;
std::shared_ptr<BackgroundObject> m_Background;

};

#endif // !GAMEWORLD_HPP__
