add_library(Core STATIC)

target_sources(Core
        PRIVATE
        Application.cpp
        Time.cpp
        Logger.cpp
)

target_include_directories(Core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)
target_link_libraries(Core
        PUBLIC Platform
        PUBLIC glfw
        PUBLIC glad
        PUBLIC glm
        PUBLIC stb
)