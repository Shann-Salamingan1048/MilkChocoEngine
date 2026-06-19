add_library(EnginePlatform STATIC)

target_sources(EnginePlatform
        PRIVATE
        Window/GLFWWindow.cpp
        OpenGL/Vao.cpp
        OpenGL/Vbo.cpp
        OpenGL/Shader.cpp
        OpenGL/Ebo.cpp
        OpenGL/Texture.cpp
)

target_include_directories(EnginePlatform
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(EnginePlatform
        PUBLIC EngineCore
        PUBLIC glfw
        PUBLIC glad
        PUBLIC glm
        PUBLIC stb
)