#include "Shader.h"

#include "Modules/FileReader.h"
#include "Modules/ShaderCompiler.h"

#include "glad/glad.h"

gm::gl::Shader gm::gl::createShaderFromFiles(const char* vertexPath,
                                             const char* fragmentPath)
{
    std::string vertexSrc = gm::mod::readFile(std::string(vertexPath));
    std::string fragmentSrc = gm::mod::readFile(std::string(fragmentPath));

    uint32_t vertexShaderID = createShader(vertexSrc.c_str(), GL_VERTEX_SHADER);
    uint32_t fragmentShaderID = createShader(fragmentSrc.c_str(), GL_FRAGMENT_SHADER);

    uint32_t programID = createProgram(vertexShaderID, fragmentShaderID);
    return {programID};
}

int32_t gm::gl::getUniformLocation(Shader* shader, char* uniformName)
{
    int location = glGetUniformLocation(shader->glID, uniformName);
    return location;

}

void gm::gl::bindShader(Shader* target)
{
    glUseProgram(target->glID);
}

void gm::gl::unbindShader(Shader* target)
{
    glUseProgram(0);
}
