cmake_minimum_required(VERSION 3.16)

add_library(
  GameObject
  STATIC
  GameObject.hpp
  GameObject.cpp
  BackgroundObject.hpp
  BackgroundObject.cpp
  PlantsSeedObject.hpp
  PlantsSeedObject.cpp
  PlantingPosObject.hpp
  PlantingPosObject.cpp
  PlantsObject.hpp
  PlantsObject.cpp
  SunFlowerObject.hpp
  SunFlowerObject.cpp
  PeaShooterObject.hpp
  PeaShooterObject.cpp
  WallNutObject.hpp
  WallNutObject.cpp
  CherryBombObject.hpp
  CherryBombObject.cpp
  RepeaterObject.hpp
  RepeaterObject.cpp
  SunObject.hpp
  SunObject.cpp
  ShovelObject.hpp
  ShovelObject.cpp
  SunOfNormalObject.hpp
  SunOfNormalObject.cpp
  SunOfPlantObject.hpp
  SunOfPlantObject.cpp
  PeaObject.hpp
  PeaObject.cpp
  CoolDownMaskObject.hpp
  CoolDownMaskObject.cpp
  ZombieObject.hpp
  ZombieObject.cpp
  Bomb.hpp
  Bomb.cpp
)

target_link_libraries(
  GameObject
  Framework
)

target_include_directories(
  GameObject
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/

)
