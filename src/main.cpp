#include "common.h"
#include "shader.h"
#include "program.h"
#include "context.h"

// using namespace std;


void OnFrameBufferSizeChange(GLFWwindow* window, int width, int height ) {
    SPDLOG_INFO("frmebuffer size changed: {} x {}", width, height);
    glViewport(0,0, width, height);
}

void OnKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
    SPDLOG_INFO("key: {}, scancode: {}, action: {}, mods: {}{}{}",
        key, scancode,
        action == GLFW_PRESS ? "Pressed":
        action == GLFW_RELEASE ? "Released" :
        action == GLFW_REPEAT ? "repeat" : "Unknown",
        mods & GLFW_MOD_CONTROL ? "C" : "-",
        mods & GLFW_MOD_SHIFT ? "S" : "-",
        mods & GLFW_MOD_ALT ? "A" : "-");
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Render() {
    glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) {
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        return -1;
    }

    // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
    if (!window) {
        SPDLOG_ERROR("failed to create glfw window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // glad를 활용한 OpenGL함수 로딩
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        SPDLOG_ERROR("failed to initialize glad");
        glfwTerminate();
        return -1;
    }
    auto glVersion = glGetString(GL_VERSION);
    SPDLOG_INFO("OpenGL context version: {}", glVersion);

    //  context 지정
    OnFrameBufferSizeChange(window, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, OnFrameBufferSizeChange);
    glfwSetKeyCallback(window, OnKeyEvent); 

    auto context = Context::Create();
    if (!context) {
        SPDLOG_ERROR("failed to create context");
        glfwTerminate();
        return -1;
    }

    // glfw 루프 실행, 윈도우 close 버튼을 누르면 ㅈㅇ상 종료
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) {
        context->Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // context->reset();
    glfwTerminate();

    return 0;
}

