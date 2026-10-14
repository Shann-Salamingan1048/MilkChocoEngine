# =========================================================
# MilkChocoEngine - Rendering Module
# =========================================================
add_library(Scene STATIC)
target_sources(Scene PRIVATE
        Camera.cpp
)

target_include_directories(Scene PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# External dependencies
target_link_libraries(Scene
        PUBLIC glm
        PRIVATE glad)