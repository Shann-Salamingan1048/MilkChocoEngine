# -------------------------
# GLFW (precompiled lib)
# -------------------------
add_library(glfw STATIC IMPORTED)

set_target_properties(glfw PROPERTIES
        IMPORTED_LOCATION
        ${CMAKE_CURRENT_SOURCE_DIR}/glfw/lib/glfw.lib
        INTERFACE_INCLUDE_DIRECTORIES
        ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include
)

# -------------------------
# GLAD (C loader)
# -------------------------
add_library(glad STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/src/glad.c
)

target_include_directories(glad PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
)

set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)

# -------------------------
# GLM (header-only)
# -------------------------
add_library(glm INTERFACE)

target_include_directories(glm INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/glm
)

# -------------------------
# STB (header-only)
# -------------------------
add_library(stb INTERFACE)

target_include_directories(stb INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/stb
)