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
  //Adjudt the game status
  for (auto &obj : m_GameList){
    if (obj->GetX() < 0){
      return LevelStatus::LOSING;
    }
  }

  m_GameTime += MS_PER_FRAME / 1000.0;
  m_SunTime += MS_PER_FRAME / 1000.0;
  m_ZombieTime += MS_PER_FRAME / 1000.0;
  //Solve Sun
  if (m_SunTime >= SUN_GENERATE_SPEED) {
    auto sun = std::make_shared<SunOfNormalObject>(IMGID_SUN, randInt(FIRST_COL_CENTER, LAST_COL_CENTER), LAST_ROW_CENTER, LAYER_SUN, SUN_WIDTH, SUN_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
    m_GameList.push_back(sun);
    m_SunTime -= SUN_GENERATE_SPEED;
  }
  //Solve Zombie
  if (m_ZombieTime >= ZOMBIE_GENERATE_SPEED){
    m_ZombieWave++;
    m_ZombieTime = 0;
    //TODO:
    int zombieNumber = (15 + m_ZombieWave) / 10;
    for (int i = 0;i < zombieNumber;i++){
      if (m_ZombieWave <= 5){
        int row = randRow({FIRST_ROW_CENTER, FIRST_ROW_CENTER + LAWN_GRID_HEIGHT, FIRST_ROW_CENTER + 2*LAWN_GRID_HEIGHT, FIRST_ROW_CENTER + 3 * LAWN_GRID_HEIGHT, LAST_ROW_CENTER});
        ZombieType zombieType = static_cast<ZombieType>(0);
        ZombieAdd(zombieType, WINDOW_WIDTH, row);
      }
      else{
        int row = randRow({FIRST_ROW_CENTER, FIRST_ROW_CENTER + LAWN_GRID_HEIGHT, FIRST_ROW_CENTER + 2*LAWN_GRID_HEIGHT, FIRST_ROW_CENTER + 3 * LAWN_GRID_HEIGHT, LAST_ROW_CENTER});
        ZombieType zombieType = static_cast<ZombieType>(randInt(0,1));
        ZombieAdd(zombieType, WINDOW_WIDTH, row);
      }
    }
  }

  //Update all objects
  for (auto &gameObject : m_GameList) {
    gameObject->Update();
  }

  //Update all texts
  for (auto &textObject : m_TextList) {
    if (textObject->GetTextType() == TextType::WAVE) textObject->SetText("wave : " + std::to_string(m_ZombieWave));
    else if (textObject->GetTextType() == TextType::SUN) textObject->SetText(std::to_string(m_Sun));
  }

  //Solve death
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if (it->get()->GetIfDead()){
      m_GameList.erase(it);
    }
  }


  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
  m_GameList.clear();
  m_TextList.clear();
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
  auto sunFlower = std::make_shared<SunFlowerObject>(IMGID_SUNFLOWER, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM,ObjectType::Plant ,shared_from_this());
  m_GameList.push_back(sunFlower);
  m_PlantTypeChoosingNow = PlantsType::NONE;
  auto sunMask = std::make_shared<CoolDownMaskObject>(IMGID_COOLDOWN_MASK, FIRST_SEED_COL_CENTER, SEED_ROW_CENTER, LAYER_COOLDOWN_MASK, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this(), SUNFLOWER_COOLDOWN);
  m_GameList.push_back(sunMask);
}
void GameWorld::PeaShooterAdd(int x, int y) {
  if (m_Sun < SUN_COST_PEASHOOTER) return;
  m_Sun -= SUN_COST_PEASHOOTER;
  auto peaShooter = std::make_shared<PeaShooterObject>(IMGID_PEASHOOTER, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, ObjectType::Plant, shared_from_this());
  m_GameList.push_back(peaShooter);
  m_PlantTypeChoosingNow = PlantsType::NONE;
  auto peaMask = std::make_shared<CoolDownMaskObject>(IMGID_COOLDOWN_MASK, FIRST_SEED_COL_CENTER + SEED_WIDTH, SEED_ROW_CENTER, LAYER_COOLDOWN_MASK, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this(), PEASHOOTER_COOLDOWN);
  m_GameList.push_back(peaMask);
}
void GameWorld::WallNutAdd(int x, int y) {
  if (m_Sun < SUN_COST_WALLNUT) return;
  m_Sun -= SUN_COST_WALLNUT;
  auto wallNut = std::make_shared<WallNutObject>(IMGID_WALLNUT, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, ObjectType::Plant, shared_from_this());
  m_GameList.push_back(wallNut);
  m_PlantTypeChoosingNow = PlantsType::NONE;
  auto wallMask = std::make_shared<CoolDownMaskObject>(IMGID_COOLDOWN_MASK, FIRST_SEED_COL_CENTER + 2 * SEED_WIDTH, SEED_ROW_CENTER, LAYER_COOLDOWN_MASK, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this(), WALLNUT_COOLDOWN);
  m_GameList.push_back(wallMask);
}
void GameWorld::CherryBombAdd(int x, int y) {
  if (m_Sun < SUN_COST_CHERRY_BOMB) return;
  m_Sun -= SUN_COST_CHERRY_BOMB;
  auto cherryBomb = std::make_shared<CherryBombObject>(IMGID_CHERRY_BOMB, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, ObjectType::Plant, shared_from_this());
  m_GameList.push_back(cherryBomb);
  m_PlantTypeChoosingNow = PlantsType::NONE;
  auto cherryMask = std::make_shared<CoolDownMaskObject>(IMGID_COOLDOWN_MASK, FIRST_SEED_COL_CENTER + 3 * SEED_WIDTH, SEED_ROW_CENTER, LAYER_COOLDOWN_MASK, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this(), CHERRY_BOMB_COOLDOWN);
  m_GameList.push_back(cherryMask);
}
void GameWorld::RepeaterAdd(int x, int y) {
  if (m_Sun < SUN_COST_REPEATER) return;
  m_Sun -= SUN_COST_REPEATER;
  auto repeater = std::make_shared<RepeaterObject>(IMGID_REPEATER, x, y, LAYER_PLANTS, LAWN_GRID_WIDTH, LAWN_GRID_HEIGHT, ANIMID_IDLE_ANIM, ObjectType::Plant, shared_from_this());
  m_GameList.push_back(repeater);
  m_PlantTypeChoosingNow = PlantsType::NONE;
  auto repeaterMask = std::make_shared<CoolDownMaskObject>(IMGID_COOLDOWN_MASK, FIRST_SEED_COL_CENTER + 4 * SEED_WIDTH, SEED_ROW_CENTER, LAYER_COOLDOWN_MASK, SEED_WIDTH, SEED_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this(), REPEATER_COOLDOWN);
  m_GameList.push_back(repeaterMask);
}

void GameWorld::ZombieAdd(ZombieType type, int x, int y){
  if (type == ZombieType::REGULAR){
    auto zombie = std::make_shared<RegularZombieObject>(ChangeZombieTypeToImageID(type), x, y, LAYER_ZOMBIES, ZOMBIE_WIDTH, ZOMBIE_HEIGHT, ANIMID_WALK_ANIM, ObjectType::Zombie, shared_from_this(), type, HP_REGULAR_ZOMBIE);
    m_GameList.push_back(zombie);
  }
  else if (type == ZombieType::BUCKET_HEAD){
    auto zombie = std::make_shared<BucketHeadZombieObject>(ChangeZombieTypeToImageID(type), x, y, LAYER_ZOMBIES, ZOMBIE_WIDTH, ZOMBIE_HEIGHT, ANIMID_WALK_ANIM, ObjectType::Zombie, shared_from_this(), type, HP_BUCKET_HEAD_ZOMBIE);
    m_GameList.push_back(zombie);
  }
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
    if ((std::abs(it->get()->GetX() - x) <= it->get()->GetWidth() / 2 ) && (std::abs(it->get()->GetY() - y) <= it->get()->GetHeight() / 2) && (it->get()->GetObjectType() == ObjectType::Plant)){
      m_GameList.erase(it);
      break;
    }
  }
  m_PlantTypeChoosingNow = PlantsType::NONE;
}

void GameWorld::RemoveMask(int x, int y){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= it->get()->GetWidth() / 2 ) && (std::abs(it->get()->GetY() - y) <= it->get()->GetHeight() / 2) && (it->get()->GetLayer() == LAYER_COOLDOWN_MASK)){
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

void GameWorld::AddSun(int sun){
  m_Sun += sun;
}

// void GameWorld::AddZombieWave(){
//   m_ZombieWave++;
// }

bool GameWorld::CollideCheck(int x, int y){
  for (auto &gameObject : m_GameList) {
    if (gameObject->GetLayer() == LAYER_PLANTS && x - gameObject->GetX() <= LAWN_GRID_WIDTH / 2 && gameObject->GetX() - x <= 0 && std::abs(y - gameObject->GetY()) <= 10){
      return true;
    }
  }
  return false;
}

inline ImageID GameWorld::ChangeZombieTypeToImageID(ZombieType type){
  if(type == ZombieType::REGULAR) return IMGID_REGULAR_ZOMBIE;
  else if(type == ZombieType::BUCKET_HEAD) return IMGID_BUCKET_HEAD_ZOMBIE;
  else return IMGID_NONE;
}
void GameWorld::AttackPlant(int x, int y, int damage){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= LAWN_GRID_WIDTH / 2 ) && (std::abs(it->get()->GetY() - y) <= LAWN_GRID_HEIGHT / 2) && (it->get()->GetLayer() == LAYER_PLANTS)){
      it->get()->ChangeStatus(true);
    }
  }
}

void GameWorld::AddSunOfPlant(int x, int y){
  auto sun = std::make_shared<SunOfPlantObject>(IMGID_SUN, x, y, LAYER_SUN, SUN_WIDTH, SUN_HEIGHT, ANIMID_IDLE_ANIM, shared_from_this());
  m_GameList.push_back(sun);
}

bool GameWorld::IfTheRowForwardHasZombie(int x, int y){
  for (auto &gameObject : m_GameList) {
    if (gameObject->GetObjectType() == ObjectType::Zombie && std::abs(y - gameObject->GetY()) <= 10 && gameObject->GetX() - x >= 0){
      return true;
    }
  }
  return false;
}

void GameWorld::AddPea(int x, int y){
  auto pea = std::make_shared<PeaObject>(IMGID_PEA, x, y, LAYER_PROJECTILES, PEAS_WIDTH, PEAS_HEIGHT, ANIMID_NO_ANIMATION, ObjectType::Pea ,shared_from_this());
  m_GameList.push_back(pea);
}

bool GameWorld::CheckAttackZombie(int x, int y){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= LAWN_GRID_WIDTH / 2 ) && (std::abs(it->get()->GetY() - y) <= LAWN_GRID_HEIGHT / 2) && (it->get()->GetObjectType() == ObjectType::Zombie)){
      it->get()->ChangeStatus(true);
      return true;
    }
  }
  return false;
}



void GameWorld::RemovePea(int x, int y){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= LAWN_GRID_WIDTH / 2 ) && (std::abs(it->get()->GetY() - y) <= LAWN_GRID_HEIGHT / 2) && (it->get()->GetObjectType() == ObjectType::Pea )){
      m_GameList.erase(it);
    }
  }
}

void GameWorld::CherryBombAttack(int x, int y){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if (std::abs(it->get()->GetX() - x) <= CHERRY_BOMB_RADIUS && std::abs(it->get()->GetY() - y) <= CHERRY_BOMB_RADIUS && it->get()->GetObjectType() == ObjectType::Zombie){
      RemoveZombie(it->get()->GetX(), it->get()->GetY());
    }
  }
}

void GameWorld::AddBomb(int x, int y){
  auto bomb = std::make_shared<Bomb>(IMGID_EXPLOSION, x, y, LAYER_PROJECTILES, CHERRY_BOMB_RADIUS, CHERRY_BOMB_RADIUS, ANIMID_NO_ANIMATION, ObjectType::Bomb, shared_from_this());
  m_GameList.push_back(bomb);

}

void GameWorld::RemoveZombie(int x, int y){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= LAWN_GRID_WIDTH / 2 ) && (std::abs(it->get()->GetY() - y) <= LAWN_GRID_HEIGHT / 2) && (it->get()->GetObjectType() == ObjectType::Zombie)){
      m_GameList.erase(it);
      break;
    }
  }
}

void GameWorld::RemoveBomb(int x, int y){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= CHERRY_BOMB_RADIUS / 2 ) && (std::abs(it->get()->GetY() - y) <= CHERRY_BOMB_RADIUS / 2) && (it->get()->GetObjectType() == ObjectType::Bomb)){
      m_GameList.erase(it);

      break;
    }
  }
}

void GameWorld::RemoveCherryBomb(int x, int y){
  for (auto it = m_GameList.begin(); it != m_GameList.end(); it++) {
    if ((std::abs(it->get()->GetX() - x) <= LAWN_GRID_WIDTH / 2 ) && (std::abs(it->get()->GetY() - y) <= LAWN_GRID_HEIGHT / 2) && (it->get()->GetObjectType() == ObjectType::Plant)){
      m_GameList.erase(it);
      break;
    }
  }
}