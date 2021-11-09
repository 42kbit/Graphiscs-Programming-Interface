#version 330 core

layout(location = 0) out vec4 o_Color;

in vec2 v_TexCoords;

uniform sampler2D[32] u_Textures;
uniform float u_TextureID;

void main()
{
	uint textureID = uint(u_TextureID);
	o_Color = texture(u_Textures[textureID], v_TexCoords);
}