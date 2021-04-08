#version 330 core

layout( location = 0 ) in vec3 vertexPosition_modelspace;
//layout( location = 1 ) in vec3 vertexColor;

//out vec3 fragmentColor;

//uniform mat4 MVP;   // Value stays constant for the whole mesh

void main() {
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;
    //fragmentColor = vec3(1,0,0);
    //gl_Position = MVP * vec4(vertexPosition_modelspace, 1);

    //fragmentColor = vertexColor;
}