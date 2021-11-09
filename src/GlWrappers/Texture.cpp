#include "Texture.h"
#include "Modules/TextureReader.h"

gm::gl::Texture gm::gl::createTexture(const char* path,
                                      uint32_t WRAP_MODE,
                                      uint32_t FILTER_MODE,
                                      uint32_t TEXTURE_TYPE){
    uint32_t glID = gm::mod::readTexture(path, WRAP_MODE, FILTER_MODE, TEXTURE_TYPE);
    return {glID, TEXTURE_TYPE};
}

void gm::gl::bindTexture(gm::gl::Texture* target)
{
    glBindTexture(target->textureType, target->glID);
}

void gm::gl::unbindTexture(gm::gl::Texture* target)
{
    glBindTexture(target->textureType, 0);
}
