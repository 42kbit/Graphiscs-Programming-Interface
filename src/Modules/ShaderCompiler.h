#ifndef H_SHADERCOMPILER
#define H_SHADERCOMPILER

#include <cinttypes>

namespace gm{
namespace gl{

uint32_t createShader(const char* src, uint32_t TYPE);

uint32_t createProgram(uint32_t vertexShaderID, uint32_t fragmentShaderID);

}
}
#endif // H_SHADERCOMPILER
