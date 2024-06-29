#ifndef UTILS_HPP__
#define UTILS_HPP__

#include <random>
#include <string>
#include <list>

// This relative path on Mac OS is different from that on other OS, because the
// way Xcode organizes the project files is different from others.
// Change it if the program fails to load assets. You may also use an absolute
// path.
#ifdef __APPLE__
static const std::string ASSET_DIR = "../../assets/";
#else
static const std::string ASSET_DIR = "../assets/";
#endif // __APPLE__

// Returns a random integer within [min, max] (inclusive).
inline int randInt(int min, int max) {
  if (max < min)
    std::swap(max, min);
  static std::random_device rd;
  static std::mt19937 generator(rd());
  std::uniform_int_distribution<> distro(min, max);
  return distro(generator);
}
inline int randRow(std::list<int> numberList){
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_int_distribution<> distro(0, numberList.size() - 1);
  auto it = std::next(numberList.begin(), distro(generator));
  return *it;
}




enum class LevelStatus { ONGOING, LOSING };

enum class KeyCode {
  NONE,
  ENTER, // Enter
  QUIT   // Esc
};

enum class ObjectType {
  Plant,
  Zombie,
  Pea,
  Other
};



enum class PlantsType {
  SHOVEL,
  NONE,
  SUNFLOWER,
  PEASHOOTER,
  WALLNUT,
  CHERRY_BOMB,
  REPEATER,
  SUN
};
enum class TextType{
  WAVE,
  SUN
};

enum class ZombieType {
  REGULAR,
  BUCKET_HEAD
};

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int LAWN_GRID_WIDTH = 80;
const int LAWN_GRID_HEIGHT = 100;

const int FIRST_ROW_CENTER = 75;
const int FIRST_COL_CENTER = 75;
const int LAST_ROW_CENTER = 75 + 4 * LAWN_GRID_HEIGHT;
const int LAST_COL_CENTER = 75 + 8 * LAWN_GRID_WIDTH;
const int GAME_ROWS = 5;
const int GAME_COLS = 9;

const int FIRST_SEED_COL_CENTER = 130;
const int SEED_ROW_CENTER = WINDOW_HEIGHT - 44;  
const int SEED_WIDTH = 50;
const int SEED_HEIGHT = 70;

const int SHOVEL_X = 600;
const int SHOVEL_Y = WINDOW_HEIGHT - 40;
const int SHOVEL_WIDTH = 50;
const int SHOVEL_HEIGHT = 50;

using ImageID = int;

const ImageID IMGID_NONE = -1;
const ImageID IMGID_BACKGROUND = 0;
const ImageID IMGID_SUN = 1;
const ImageID IMGID_SHOVEL = 2;
const ImageID IMGID_COOLDOWN_MASK = 3;
const ImageID IMGID_SUNFLOWER = 10;
const ImageID IMGID_PEASHOOTER = 11;
const ImageID IMGID_WALLNUT = 12;
const ImageID IMGID_CHERRY_BOMB = 13;
const ImageID IMGID_REPEATER = 14;
const ImageID IMGID_WALLNUT_CRACKED = 15;
const ImageID IMGID_SEED_SUNFLOWER = 20;
const ImageID IMGID_SEED_PEASHOOTER = 21;
const ImageID IMGID_SEED_WALLNUT = 22;
const ImageID IMGID_SEED_CHERRY_BOMB = 23;
const ImageID IMGID_SEED_REPEATER = 24;
const ImageID IMGID_REGULAR_ZOMBIE = 30;
const ImageID IMGID_BUCKET_HEAD_ZOMBIE = 31;
const ImageID IMGID_POLE_VAULTING_ZOMBIE = 32;
const ImageID IMGID_PEA = 40;
const ImageID IMGID_EXPLOSION = 41;
const ImageID IMGID_ZOMBIES_WON = 99;

using AnimID = int;

const AnimID ANIMID_NO_ANIMATION = -1;
const AnimID ANIMID_IDLE_ANIM = 0;
const AnimID ANIMID_WALK_ANIM = 1;
const AnimID ANIMID_EAT_ANIM = 2;
const AnimID ANIMID_RUN_ANIM = 3;
const AnimID ANIMID_JUMP_ANIM = 4;

const int MAX_LAYERS = 7;
using LayerID = int;

const LayerID LAYER_SUN = 0;
const LayerID LAYER_ZOMBIES = 1;
const LayerID LAYER_PROJECTILES = 2;
const LayerID LAYER_PLANTS = 3;
const LayerID LAYER_COOLDOWN_MASK = 4;
const LayerID LAYER_UI = 5;
const LayerID LAYER_BACKGROUND = 6;

const int MS_PER_FRAME = 33;

const int SUN_COST_SUNFLOWER = 50;
const int SUN_COST_PEASHOOTER = 100;
const int SUN_COST_WALLNUT = 50;
const int SUN_COST_CHERRY_BOMB = 150;
const int SUN_COST_REPEATER = 200;

const int SUNFLOWER_COOLDOWN = 100;
const int PEASHOOTER_COOLDOWN = 100;
const int WALLNUT_COOLDOWN = 100;
const int CHERRY_BOMB_COOLDOWN = 100;
const int REPEATER_COOLDOWN = 100;

const int SUN_START = 5000;
const int SUN_TEXT_X = 60;
const int SUN_TEXT_Y = WINDOW_HEIGHT - 80;
const int SUN_GENERATE_SPEED = 5;
const int SUN_FALL_MS_PER_FRAME = 2 ;
const int SUN_COOL_TIME = 10;
const int SUN_WIDTH = 80;
const int SUN_HEIGHT = 80;

const int WAVE_TEXT_X = WINDOW_WIDTH * 6 / 7;
const int WAVE_TEXT_Y = 7;
const int ZOMBIE_GENERATE_SPEED = 5;
const int ZOMBIE_MOVE_SPEED = 1;
const int ZOMBIE_WIDTH = 20;
const int ZOMBIE_HEIGHT = 80;
const int HP_REGULAR_ZOMBIE = 200;
const int HP_BUCKET_HEAD_ZOMBIE = 1700;
const int HP_POLE_VAULTING_ZOMBIE = 700;

const int SUN_FLOWER_GENERATE_TIME = 5;
const int PEAS_WIDTH = 28;
const int PEAS_HEIGHT = 28;
const int PEAS_SPEED = 8;
const int PEAS_DAMAGE = 100;
const int PEAS_COOLDOWN = 3;
const double PEAS_INTERVAL = 0.1;



#endif // !UTILS_HPP__
