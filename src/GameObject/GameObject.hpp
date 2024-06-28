#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "../Framework/ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this;
  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, bool isAttack = false, ObjectType objectType = ObjectType::Other, bool ifDead = false):
    ObjectBase(imageID, x, y, layer, width, height, animID), m_isAttack(isAttack), m_objectType(objectType), m_ifDead(ifDead){};

  virtual ~GameObject(){};
  bool GetStatus() const {
    return m_isAttack;
  };
  void ChangeStatus(bool isAttack){
    m_isAttack = isAttack;
  };

  bool GetIfDead() const {
    return m_ifDead;
  };

  void ChangeIfDead(bool ifDead){
    m_ifDead = ifDead;
  };

private:
  bool m_isAttack;
  ObjectType m_objectType;
  bool m_ifDead;
};



#endif // !GAMEOBJECT_HPP__
