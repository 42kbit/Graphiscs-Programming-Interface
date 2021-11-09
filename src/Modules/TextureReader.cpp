#include "TextureReader.h"
#include "glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

uint32_t gm::mod::readTexture(const char* path, uint32_t WRAP_MODE, uint32_t FILTER_MODE, uint32_t TEXTURE_TYPE)
{
    int width, height, channels;
    uint32_t glID;

    stbi_set_flip_vertically_on_load(1);
    unsigned char* tex_src = new unsigned char[2048];
    tex_src = stbi_load(path, &width, &height, &channels, 0);

    glGenTextures(1, &glID);
    glBindTexture(TEXTURE_TYPE, glID);

    glTexParameteri(TEXTURE_TYPE, GL_TEXTURE_WRAP_S, WRAP_MODE);
    glTexParameteri(TEXTURE_TYPE, GL_TEXTURE_WRAP_T, WRAP_MODE);
    glTexParameteri(TEXTURE_TYPE, GL_TEXTURE_MAG_FILTER, FILTER_MODE);
    glTexParameteri(TEXTURE_TYPE, GL_TEXTURE_MIN_FILTER, FILTER_MODE);
    glTexImage2D(TEXTURE_TYPE, 0, GL_RGBA, width, height, 0,
        channels == 4 ? GL_RGBA : GL_RGB,
        GL_UNSIGNED_BYTE,
        tex_src);

    delete [] tex_src;
    glBindTexture(TEXTURE_TYPE, 0);
    return glID;
}
