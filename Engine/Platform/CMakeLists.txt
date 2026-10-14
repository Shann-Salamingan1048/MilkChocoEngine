add_library(Platform STATIC)

target_sources(Platform
        PRIVATE
        Window/GLFWWindow.cpp
        OpenGL/Vao.cpp
        OpenGL/Vbo.cpp
        OpenGL/Shader.cpp
        OpenGL/Ebo.cpp
        OpenGL/Texture.cpp
)

target_include_directories(Platform
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(Platform
        PUBLIC Core
        PUBLIC glfw
        PUBLIC glad
        PUBLIC glm
        PUBLIC stb
)