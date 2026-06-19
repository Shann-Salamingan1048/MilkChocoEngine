add_library(EngineCore STATIC)

target_sources(EngineCore
        PRIVATE
        Application.cpp
        Time.cpp
        Logger.cpp
)

target_include_directories(EngineCore
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)