cmake_minimum_required(VERSION 3.20)

project(MilkChocoEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# -------------------------
# Third Party
# -------------------------
add_subdirectory(ThirdParty)

# -------------------------
# Engine Modules
# -------------------------
add_subdirectory(Engine/Core)
add_subdirectory(Engine/Platform)
#add_subdirectory(Engine/Rendering)
#add_subdirectory(Engine/Input)
#add_subdirectory(Engine/Scene)
#add_subdirectory(Engine/Assets)
#add_subdirectory(Engine/Math)
#
## -------------------------
## Sandbox (test game)
## -------------------------
#add_subdirectory(Sandbox)