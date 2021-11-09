#include "Buffer.h"
#include "glad/glad.h"

gm::gl::Buffer gm::gl::createBuffer(uint32_t TYPE, uint32_t byte_size, void* data, uint32_t DRAW_MODE)
{
    uint32_t id;
    glGenBuffers(1, &id);
    glBindBuffer(TYPE, id);
    glBufferData(TYPE, byte_size, data, DRAW_MODE);
    glBindBuffer(TYPE, 0);
    return {id, TYPE, DRAW_MODE};
}

void gm::gl::bindBuffer(Buffer* buffer)
{
    glBindBuffer(buffer->TYPE, buffer->glID);
}

void gm::gl::unbindBuffer(Buffer* buffer)
{
    glBindBuffer(buffer->TYPE, 0);
}
