#ifndef Backgorund_H__
#define Backgorund_H__
#include "GameObject.hpp"
class BackgroundObject : public GameObject {
public:
  BackgroundObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID):
    GameObject(imageID, x, y, layer, width, height, animID){};


  virtual ~BackgroundObject(){};

  void Update() override{
    return;
  };
  void OnClick() override{
    
    return;
  };
private:
  // YOUR CODE HERE

  
};




#endif // !Backgorund_H__