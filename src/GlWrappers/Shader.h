#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <cinttypes>

namespace gm{
namespace gl{

struct Shader
{
    uint32_t glID;
};

Shader createShaderFromFiles(const char* vertexPath,
                             const char* fragmentPath);

int32_t getUniformLocation(Shader* shader, char* uniformName);

void bindShader(Shader* target);
void unbindShader(Shader* target);

}
}

#endif // SHADER_H_INCLUDED
