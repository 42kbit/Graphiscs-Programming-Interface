#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

#include <cinttypes>

namespace gm
{

namespace gl
{

struct Buffer
{
    uint32_t glID;
    uint32_t TYPE;
    uint32_t DRAW_MODE;
};

Buffer createBuffer(uint32_t TYPE,
                    uint32_t byte_size,
                    void* data,
                    uint32_t DRAW_MODE);

void bindBuffer(Buffer* buffer);
void unbindBuffer(Buffer* buffer);

}
}

#endif // BUFFER_H_INCLUDED
