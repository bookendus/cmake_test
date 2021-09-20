#version 330 core

layout (location = 0) in vec3 aPos;

out vec4 vertexColor; // fragment shader를 위한 컬러 출력을 지정

void main() {
    gl_Position = vec4(aPos, 1.0);
    // gl_Position = vec4(0.5, 0.5, 0.5, 1.0);
    vertexColor = vec4(1.0, 1.0, 1.0, 1.0); //출력변수에 짙은 빨간색..
}