project(final)
cmake_minimum_required(VERSION 3.9)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GL REQUIRED gl)

#Bring the headers
include_directories(include)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})

include_directories(/usr/local/include/assimp)
link_directories(/usr/local/lib)

#wildcard
file(GLOB SOURCES "src/*.cpp" "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(
    ${PROJECT_NAME}
    glfw
    -lassimp
    ${CMAKE_DL_LIBS}
    ${OPEN_gl_LIBRARIES} )