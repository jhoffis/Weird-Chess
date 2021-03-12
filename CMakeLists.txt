cmake_minimum_required(VERSION 3.17)

project(weirdchess)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(COPY ${CMAKE_SOURCE_DIR}/res DESTINATION ${PROJECT_BINARY_DIR})

add_executable (${PROJECT_NAME}
        src/engine/glad.c
        src/main.cpp
        # Engine
        src/engine/graphics/Shader.h src/engine/graphics/Shader.cpp
        src/engine/io/Window.h src/engine/io/Window.cpp
        src/engine/utils/Timer.h src/engine/utils/Timer.cpp
        src/engine/graphics/Camera.h
        src/engine/io/ResourceLoader.h src/engine/io/ResourceLoader.cpp
        src/engine/graphics/Sprite.h src/engine/graphics/Sprite.cpp
        # Game
        )

find_package(OpenGL REQUIRED COMPONENTS OpenGL)
include_directories( ${OPENGL_INCLUDE_DIRS} )
add_dependencies(${PROJECT_NAME} OpenGL::GL)

add_subdirectory (Libraries/glm)
target_link_libraries(${PROJECT_NAME} glm::glm)

add_subdirectory (Libraries/glfw)
include_directories(Libraries/glfw/include)

include_directories(Libraries/glm)
include_directories(Libraries/stb)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libraries/Nuklear)


target_link_libraries(${PROJECT_NAME}
        OpenGL::GL
        glfw)
