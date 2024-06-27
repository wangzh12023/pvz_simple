#include "GameWorld.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <format>

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
  auto m_SunText = std::make_shared<TextBase>(SUN_TEXT_X, SUN_TEXT_Y, TextType::SUN, std::to_string(SUN_START), 0,0,0);
  auto m_wave = std::make_shared<TextBase>(WAVE_TEXT_X, WAVE_TEXT_Y, TextType::WAVE, "wave : " + std::to_string(m_ZombieWave), 0,0,0);
  m_GameList.push_back(m_Background);
  m_GameList.push_back(m_SunFlowerSeed);
  m_GameList.push_back(m_PeaShooterSeed);
  m_GameList.push_back(m_WallNutSeed);
  m_GameList.push_back(m_CherryBombSeed);
  m_GameList.push_back(m_RepeaterSeed);
  m_GameList.push_back(m_Shovel);
  m_TextList.push_back(m_SunText);
  m_TextList.push_back(m_wave);



  for (int i = 0; i < GAME_ROWS; i++) {
    for(int j =0; j < GAME_COLS; j++) {
      auto m_plantingPos = std::make_shared<PlantingPosObject>(IMGID_NONE, FIRST_ROW_CENTER + j * LAWN_GRID_WIDTH, FIRST_COL_CENTER + i * LAWN_GRID_HEIGHT, LAYER_UI, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this());
      m_GameList.push_back(m_plantingPos);
    }
  }
}

LevelStatus GameWorld::Update() {
  m_GameTime += MS_PER_FRAME / 1000.0;
  m_SunTime += MS_PER_FRAME / 1000.0;

  if (m_SunTime >= SUN_GENERATE_SPEED) {
    //TODO: generate sun object
    auto sun = std::make_shared<SunObject>(IMGID_SUN, randInt(FIRST_COL_CENTER, LAST_COL_CENTER), LAST_ROW_CENTER, LAYER_SUN, SUN_WIDTH, SUN_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
    m_GameList.push_back(sun);

    m_SunTime -= SUN_GENERATE_SPEED;
  }

  for (auto &gameObject : m_GameList) {
    gameObject->Update();
  }

  for (auto &textObject : m_TextList) {
    if (textObject->GetTextType() == TextType::WAVE) textObject->SetText("wave : " + std::to_string(m_ZombieWave));
    else if (textObject->GetTextType() == TextType::SUN) textObject->SetText(std::to_string(m_Sun));
  }

  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
}
// void GameWorld::ChangeGameObject(PlantsType choosingType, int x, int y) {
//   if (choosingType == PlantsType::NONE) return;
//   else if (choosingType == PlantsType::SHOVEL) {
//     RemoveGameObject(x, y);
//     m_PlantTypeChoosingNow = PlantsType::NONE;
//   }
//   else AddGameObject(choosingType, x, y);
// }
void GameWorld::AddGameObject(PlantsType type, int x, int y) {
  if (type == PlantsType::NONE || type == PlantsType::SHOVEL) return;
  else if (type == PlantsType::SUNFLOWER) SunFlowerAdd(x,y);
  else if (type == PlantsType::PEASHOOTER) PeaShooterAdd(x,y);
  else if (type == PlantsType::WALLNUT) WallNutAdd(x,y);
  else if (type == PlantsType::CHERRY_BOMB) CherryBombAdd(x,y);
  else if (type == PlantsType::REPEATER) RepeaterAdd(x,y);
}


void GameWorld::SunFlowerAdd(int x, int y) {
  if (m_Sun < SUN_COST_SUNFLOWER) return;
  m_Sun -= SUN_COST_SUNFLOWER;
  auto sunFlower = std::make_shared<SunFlowerObject>(IMGID_SUNFLOWER, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
  m_GameList.push_back(sunFlower);
  m_PlantTypeChoosingNow = PlantsType::NONE;
}
void GameWorld::PeaShooterAdd(int x, int y) {
  if (m_Sun < SUN_COST_PEASHOOTER) return;
  m_Sun -= SUN_COST_PEASHOOTER;
  auto peaShooter = std::make_shared<PeaShooterObject>(IMGID_PEASHOOTER, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
  m_GameList.push_back(peaShooter);
  m_PlantTypeChoosingNow = PlantsType::NONE;
}
void GameWorld::WallNutAdd(int x, int y) {
  if (m_Sun < SUN_COST_WALLNUT) return;
  m_Sun -= SUN_COST_WALLNUT;
  auto wallNut = std::make_shared<WallNutObject>(IMGID_WALLNUT, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
  m_GameList.push_back(wallNut);
  m_PlantTypeChoosingNow = PlantsType::NONE;
}
void GameWorld::CherryBombAdd(int x, int y) {
  if (m_Sun < SUN_COST_CHERRY_BOMB) return;
  m_Sun -= SUN_COST_CHERRY_BOMB;
  auto cherryBomb = std::make_shared<CherryBombObject>(IMGID_CHERRY_BOMB, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
  m_GameList.push_back(cherryBomb);
  m_PlantTypeChoosingNow = PlantsType::NONE;
}
void GameWorld::RepeaterAdd(int x, int y) {
  if (m_Sun < SUN_COST_REPEATER) return;
  m_Sun -= SUN_COST_REPEATER;
  auto repeater = std::make_shared<RepeaterObject>(IMGID_REPEATER, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
  m_GameList.push_back(repeater);
  m_PlantTypeChoosingNow = PlantsType::NONE;
}


void GameWorld::RemoveGameObject(PlantsType type, int x, int y){
  // YOUR CODE HERE
  if (type == PlantsType::SUN){
    for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
      if ((std::abs(it->get()->GetX() - x) <= it->get()->GetWidth() / 2 ) && (std::abs(it->get()->GetY() - y) <= it->get()->GetHeight() / 2) && (it->get()->GetLayer() == LAYER_SUN)){
        m_GameList.erase(it);
        return;
      }
    }
  }

  if (type != PlantsType::SHOVEL) return;
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= it->get()->GetWidth() / 2 ) && (std::abs(it->get()->GetY() - y) <= it->get()->GetHeight() / 2) && (it->get()->GetLayer() == LAYER_PLANTS)){
      m_GameList.erase(it);
      break;
    }
  }

  m_PlantTypeChoosingNow = PlantsType::NONE;
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

void GameWorld::AddSun(int sun){
  m_Sun += sun;
}