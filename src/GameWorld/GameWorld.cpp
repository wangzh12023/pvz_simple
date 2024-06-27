#include "GameWorld.hpp"
#include <iostream>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  auto m_Background = std::make_shared<BackgroundObject>(IMGID_BACKGROUND, (WINDOW_WIDTH - 1) / 2, (WINDOW_HEIGHT - 1) / 2, 
                LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION);
  auto m_SunFlowerSeed = std::make_shared<PlantsSeedObject>(IMGID_SEED_SUNFLOWER, FIRST_SEED_COL_CENTER, SEED_ROW_CENTER,
                LAYER_UI, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, SUN_COST_SUNFLOWER, SUNFLOWER_COOLDOWN, PlantsType::SUNFLOWER, shared_from_this());
  auto m_PeaShooterSeed = std::make_shared<PlantsSeedObject>(IMGID_SEED_PEASHOOTER, FIRST_SEED_COL_CENTER + SEED_WIDTH, SEED_ROW_CENTER,
                LAYER_UI, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, SUN_COST_PEASHOOTER, PEASHOOTER_COOLDOWN, PlantsType::PEASHOOTER, shared_from_this()); 
  auto m_WallNutSeed = std::make_shared<PlantsSeedObject>(IMGID_SEED_WALLNUT, FIRST_SEED_COL_CENTER + 2 * SEED_WIDTH, SEED_ROW_CENTER,
                LAYER_UI, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, SUN_COST_WALLNUT, WALLNUT_COOLDOWN, PlantsType::WALLNUT, shared_from_this());
  auto m_CherryBombSeed = std::make_shared<PlantsSeedObject>(IMGID_SEED_CHERRY_BOMB, FIRST_SEED_COL_CENTER + 3 * SEED_WIDTH, SEED_ROW_CENTER,
                LAYER_UI, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, SUN_COST_CHERRY_BOMB, CHERRY_BOMB_COOLDOWN, PlantsType::CHERRY_BOMB, shared_from_this());
  auto m_RepeaterSeed = std::make_shared<PlantsSeedObject>(IMGID_SEED_REPEATER, FIRST_SEED_COL_CENTER + 4 * SEED_WIDTH, SEED_ROW_CENTER,
                LAYER_UI, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, SUN_COST_REPEATER, REPEATER_COOLDOWN, PlantsType::REPEATER, shared_from_this());
  auto m_Shovel = std::make_shared<ShovelObject>(IMGID_SHOVEL, SHOVEL_X, SHOVEL_Y, LAYER_UI, SHOVEL_WIDTH, SHOVEL_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this());
  m_GameList.push_back(m_Background);
  m_GameList.push_back(m_SunFlowerSeed);
  m_GameList.push_back(m_PeaShooterSeed);
  m_GameList.push_back(m_WallNutSeed);
  m_GameList.push_back(m_CherryBombSeed);
  m_GameList.push_back(m_RepeaterSeed);
  m_GameList.push_back(m_Shovel);
  for (int i = 0; i < GAME_ROWS; i++) {
    for(int j =0; j < GAME_COLS; j++) {
      auto m_plantingPos = std::make_shared<PlantingPosObject>(IMGID_NONE, FIRST_ROW_CENTER + j * LAWN_GRID_WIDTH, FIRST_COL_CENTER + i * LAWN_GRID_HEIGHT, LAYER_UI, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this());
      m_GameList.push_back(m_plantingPos);
    }
  }
}

LevelStatus GameWorld::Update() {
  for (auto &gameObject : m_GameList) {
    gameObject->Update();
  }
  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
}
void GameWorld::ChangeGameObject(PlantsType choosingType, int x, int y) {
  if (choosingType == PlantsType::NONE) return;
  else if (choosingType == PlantsType::SHOVEL) {
    RemoveGameObject(x, y);
    m_PlantTypeChoosingNow = PlantsType::NONE;
  }
  else AddGameObject(choosingType, x, y);
}
void GameWorld::AddGameObject(PlantsType type, int x, int y) {
  if (type == PlantsType::NONE || type == PlantsType::SHOVEL) return;
  if (IsPlanted(x, y)){
    m_PlantTypeChoosingNow = PlantsType::NONE;
    return;
  }
  ImageID plantId = ChangePlantsTypeToImageID(type);
  auto plant = std::make_shared<PlantsObject>(plantId, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM);
  m_GameList.push_back(plant);
  m_PlantTypeChoosingNow = PlantsType::NONE;
}

void GameWorld::RemoveGameObject(int x, int y){
  // YOUR CODE HERE
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if (it->get()->GetX() == x && it->get()->GetY() == y){
      m_GameList.erase(it);
      break;
    }
  }
}

void GameWorld::ChangeChoosingPlantType(PlantsType type){
  m_PlantTypeChoosingNow = type;
}

PlantsType GameWorld::GetChoosingPlantType(){
  return m_PlantTypeChoosingNow;
}

inline ImageID GameWorld::ChangePlantsTypeToImageID(PlantsType type){
  if (type == PlantsType::SUNFLOWER) return IMGID_SUNFLOWER;
  else if (type == PlantsType::PEASHOOTER) return IMGID_PEASHOOTER;
  else if (type == PlantsType::WALLNUT) return IMGID_WALLNUT;
  else if (type == PlantsType::CHERRY_BOMB) return IMGID_CHERRY_BOMB;
  else if (type == PlantsType::REPEATER) return IMGID_REPEATER;
  else return IMGID_NONE;
}

bool GameWorld::IsPlanted(int x, int y){
  // YOUR CODE HERE
  for (auto &gameObject : m_GameList) {
    if (gameObject->GetX() == x && gameObject->GetY() == y) {
      return true;
    }
  }
  return false;
}