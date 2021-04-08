#version 330 core
//in vec3 fragmentColor;
out vec3 color;
void main() {
    color = vec3(.09f,.576f,.82f);//fragmentColor;  // Interpolated between all 3 surrounding vertices
}