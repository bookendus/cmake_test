
cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME example)
set(CMAKE_CXX_STANDARD 17)

set(WINDOW_NAME "Hello, HYUNA!")
set(WINDOW_WIDTH 640)
set(WINDOW_HEIGHT 480)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/main.cpp 
    src/common.cpp src/common.h 
    src/shader.cpp src/shader.h 
    src/program.cpp src/program.h )
    # src/context.cpp src/context.h)

include(cmake/spd_log.cmake)
include(cmake/glfw.cmake)
include(cmake/glad.cmake)


# 프로젝트 INCLUDE / LIB 옵션
target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})

target_compile_definitions(${PROJECT_NAME} PUBLIC
    WINDOW_NAME="${WINDOW_NAME}"
    WINDOW_WIDTH=${WINDOW_WIDTH}
    WINDOW_HEIGHT=${WINDOW_HEIGHT}
    )

# dependency
add_dependencies(${PROJECT_NAME} ${DEP_LIST})


