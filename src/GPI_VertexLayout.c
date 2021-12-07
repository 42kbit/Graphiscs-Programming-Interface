#include "GPI_VertexLayout.h"

void GPI_PushLayoutData(GPI_VertexLayout* layout, uint32_t count, uint32_t TYPE, uint32_t NORMALIZED) 
{
    GPI_VertexSegment segment;
    segment.count = count;
    segment.type = TYPE;
    segment.normalized = NORMALIZED;
    layout->segments[layout->segmentsTop++] = segment;
    layout->stride += GPI_GetGlTypeSize(TYPE) * count;
}

GPI_VertexLayout GPI_CreateVertexLayout()
{
    GPI_VertexLayout layout = {0, NULL, 0};
    return layout;
}

void GPI_FreeLayout(GPI_VertexLayout* target)
{
    free(target->segments);
}
