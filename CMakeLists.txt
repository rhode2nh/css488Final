project(test)
cmake_minimum_required(VERSION 3.9)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GL REQUIRED gl)

#Bring the headers
include_directories(include)
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})


#wildcard
file(GLOB SOURCES "src/*.cpp" "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

link_directories(/usr/local/lib)

target_link_libraries(
    ${PROJECT_NAME}
    glfw
    ${CMAKE_DL_LIBS}
    ${OPEN_gl_LIBRARIES} )