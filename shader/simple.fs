#version 330 core

out vec4 fragColor;

// in vec4 vertexColor; // Vertex Shader로 부터 받은 입력 변수

void main() {
    // fragColor = vertexColor;
    fragColor = vec4(1.0, 0.0, 0.0, 1.0);
}