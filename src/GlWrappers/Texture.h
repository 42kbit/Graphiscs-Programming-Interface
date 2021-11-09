#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include <cinttypes>
#include "glad/glad.h"

namespace gm{
namespace gl{

struct Texture
{
    uint32_t glID;
    uint32_t textureType;
};

Texture createTexture(const char* path,
                      uint32_t WRAP_MODE = GL_CLAMP_TO_BORDER,
                      uint32_t FILTER_MODE = GL_NEAREST,
                      uint32_t TEXTURE_TYPE = GL_TEXTURE_2D);

void bindTexture(Texture* texture);
void unbindTexture(Texture* texture);

}
}
#endif // TEXTURE_H_INCLUDED
