#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "glad/glad.h"

#include "glm/vec2.hpp"

#include <cinttypes>

#include "Modules/FileReader.h"
#include "Modules/ShaderCompiler.h"

#include "GlWrappers/Buffer.h"

const uint32_t WIDTH = 600, HEIGHT = 480;
const uint32_t FPS_LIMIT = 60;

struct Vertex
{
    glm::vec2 pos;
};

int main( int argc, char* args[] )
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* windowPtr = SDL_CreateWindow("SDL Window",
                                             SDL_WINDOWPOS_CENTERED,
                                             SDL_WINDOWPOS_CENTERED,
                                             WIDTH,
                                             HEIGHT,
                                             SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    if(!windowPtr)
    {
        SDL_LogError(0, "%s", SDL_GetError());
        exit(1);
    }
    SDL_GL_CreateContext(windowPtr);

    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);
    gladLoadGL();

    SDL_Event events;
    bool windowShouldClose = false;



    Vertex vertecies[4] = {glm::vec2(0.f, 0.f),
                           glm::vec2(1.f, 0.f),
                           glm::vec2(1.f, 1.f),
                           glm::vec2(0.f, 1.f)};
    uint32_t indecies[] = {0,1,2, 2,3,0};

    gm::gl::Buffer vbo, ebo;
    vbo = gm::gl::createBuffer(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, vertecies, GL_STATIC_DRAW);
    ebo = gm::gl::createBuffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * 6, indecies, GL_STATIC_DRAW);

    uint32_t vertexShaderID, fragmentShaderID, programID;
    vertexShaderID =   gm::gl::createShader(gm::mod::readFile("res/rect.vert").c_str(),
                                            GL_VERTEX_SHADER);
    fragmentShaderID = gm::gl::createShader(gm::mod::readFile("res/rect.frag").c_str(),
                                            GL_FRAGMENT_SHADER);
    programID = gm::gl::createProgram(vertexShaderID, fragmentShaderID);

    while(!windowShouldClose){
        uint32_t startFrameTime = SDL_GetTicks();

        while (SDL_PollEvent(&events)){
            switch(events.type){
                case SDL_QUIT:
                {
                    windowShouldClose = true;
                    break;
                }
            }
        }

        glClearColor(0.5, 0.8, 0.9, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(programID);

        gm::gl::bindBuffer(&vbo);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), offsetof(Vertex, pos));
        gm::gl::unbindBuffer(&vbo);

        glEnableVertexAttribArray(0);
        gm::gl::bindBuffer(&ebo);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
        gm::gl::unbindBuffer(&ebo);
        glDisableVertexAttribArray(0);

        SDL_GL_SwapWindow(windowPtr);

        uint32_t endFrameTime = SDL_GetTicks();
        uint32_t frameLenght = endFrameTime - startFrameTime;
        if(frameLenght < (1000/FPS_LIMIT)){
            SDL_Delay(1000/FPS_LIMIT - frameLenght);
        }
    }

    SDL_DestroyWindow(windowPtr);
    SDL_Quit();
    return 0;
}
