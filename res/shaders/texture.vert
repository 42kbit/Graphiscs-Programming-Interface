#version 330 core
layout(location = 0) in vec2 a_Position;
layout(location = 1) in vec2 a_TextureCoords;

out vec2 v_TexCoords;

void main(){
	gl_Position = vec4(a_Position, 0, 1);
	v_TexCoords = a_TextureCoords;
}