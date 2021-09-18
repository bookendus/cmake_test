#glfw

find_package(glfw3 REQUIRED)
set(DEP_LIB_DIR ${DEP_LIB_DIR} ${GLFW3_LIBRARIES})
set(DEP_INCLUDE_DIR ${DEP_INCLUDE_DIR} ${GLFW3_INCLUDE_DIRS})
set(DEP_LIBS ${DEP_LIBS} glfw)


# ExternalProject_add (
#     dep_glfw
#     GIT_REPOSITORY "https://github.com/glfw/glfw.git"
#     GIT_TAG "3.3.4"
#     GIT_SHALLOW 1
#     UPDATE_COMMAND ""
#     PATCH_COMMAND ""
#     TEST_COMMAND ""
#     CMAKE_ARGS 
#         -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
#         -DGLFW_BUILD_EXAMPLES=OFF
#         -DGLFW_BUILD_TEST=OFF
#         -DGLFW_BUILD_DOCS=OFF
#         -DCMAKE_OSX_ARCHITECTURES=arm64
#         -DCMAKE_APPLE_SILICON_PROCESSOR=arm64
#     )
# set(DEP_LIST ${DEP_LIST} dep_glfw)
# set(DEP_LIBS ${DEP_LIBS} glfw3)

