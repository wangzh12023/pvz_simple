#include "GameWorld.hpp"

GameWorld::GameWorld():
  m_Background(std::make_shared<BackgroundObject>(IMGID_BACKGROUND, (WINDOW_WIDTH - 1) / 2, (WINDOW_HEIGHT - 1) / 2, 
                LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION))
 {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  // YOUR CODE HERE
  auto background = std::make_shared<BackgroundObject>(IMGID_BACKGROUND, (WINDOW_WIDTH - 1) / 2, (WINDOW_HEIGHT - 1) / 2, 
                LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION);
  m_GameList.push_back(background);
  



}

LevelStatus GameWorld::Update() {


  // YOUR CODE HERE
  // if (isLevelComplete()) {
  //   return LevelStatus::COMPLETED;
  // } else if (isGameOver()) {
  //   return LevelStatus::FAILED;
  // } else {
    // Continue the game
    // YOUR CODE HERE
  // }
  for (auto &gameObject : m_GameList) {
    gameObject->Update();
  }
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
}

