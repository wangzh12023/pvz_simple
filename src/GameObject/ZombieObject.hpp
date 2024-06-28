#ifndef ZombieObject_HPP__
#define ZombieObject_HPP__

#include "GameObject.hpp"

class GameWorld;

class ZombieObject : public GameObject{
  public:
    ZombieObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, ZombieType type, int hp):
      GameObject(imageID, x, y, layer, width, height, animID), m_gameWorld(gameWorld), m_type(type), m_hp(hp){};

    virtual ~ZombieObject(){};
    virtual void Update(){};
    void OnClick() override{};
    int GetHP() const{
      return m_hp;
    }
  protected:
    pGameWorld m_gameWorld;
  private:
    ZombieType m_type;
    int m_hp;

};

class RegularZombieObject : public ZombieObject{
  public:
    RegularZombieObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, ZombieType type, int hp, bool ifCanJump = false):
      ZombieObject(imageID, x, y, layer, width, height, animID, gameWorld, type, hp){};

    virtual ~RegularZombieObject(){};
    void Update() override;
    void OnClick() override{};
};

class BucketHeadZombieObject : public ZombieObject{
  public:
    BucketHeadZombieObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, ZombieType type, int hp, bool ifCanJump = false):
      ZombieObject(imageID, x, y, layer, width, height, animID, gameWorld, type, hp){};
    virtual ~BucketHeadZombieObject(){};
    void Update() override;
    void OnClick() override{};
};




























#endif // ZombieObject_HPP__