#ifndef TEXTUREREADER_H_INCLUDED
#define TEXTUREREADER_H_INCLUDED

#include <cinttypes>

namespace gm{
namespace mod{

uint32_t readTexture(const char* path,
                     uint32_t WRAP_MODE,
                     uint32_t FILTER_MODE,
                     uint32_t TEXTURE_TYPE);

}
}
#endif // TEXTUREREADER_H_INCLUDED
