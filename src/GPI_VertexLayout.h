#ifndef _HEADER__GPI_VERTEXLAYOUT
#define _HEADER__GPI_VERTEXLAYOUT

#include "glad/glad.h"
#include "GPI_Buffer.h"
#include <inttypes.h>

inline uint32_t GPI_GetGlTypeSize(uint32_t TYPE)
{
    switch (TYPE)
    {
    case GL_FLOAT:
    case GL_UNSIGNED_INT:
        return 4;
        break;
    }
    return 0;
}

typedef struct
{
    uint32_t count;
    uint32_t type;
    uint32_t normalized;
} GPI_VertexSegment;

typedef struct
{
    uint32_t stride;
    GPI_VertexSegment* segments;
    uint32_t segmentsTop;
} GPI_VertexLayout;

void GPI_PushLayoutData(GPI_VertexLayout* layout, uint32_t count, uint32_t TYPE, uint32_t NORMALIZED);
GPI_VertexLayout GPI_CreateVertexLayout();
void GPI_FreeLayout(GPI_VertexLayout* target);

#endif /* _HEADER__GPI_VERTEXLAYOUT */
