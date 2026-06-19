# =========================================================
# MilkChocoEngine - Rendering Module
# =========================================================
add_library(EngineRendering STATIC)
target_sources(EngineRendering PRIVATE
        Camera.cpp
)

target_include_directories(EngineRendering PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)