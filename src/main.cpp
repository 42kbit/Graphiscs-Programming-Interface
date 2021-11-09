#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <cinttypes>

#include "glad/glad.h"

const uint32_t WIDTH = 600, HEIGHT = 480;
const uint32_t FPS_LIMIT = 60;

struct Vertex
{
    float px, py;
};

static uint32_t createBuffer(uint32_t TYPE,
                             uint32_t byte_size,
                             void* data,
                             uint32_t DRAW_MODE)
{
    uint32_t id;
    glGenBuffers(1, &id);
    glBindBuffer(TYPE, id);
    glBufferData(TYPE, byte_size, data, DRAW_MODE);
    glBindBuffer(TYPE, 0);
    return id;
}

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

    uint32_t vbo, ebo;

    Vertex vertecies[4] = {{0.f, 0.f}, {1.f, 0.f}, {1.f, 1.f}, {0.f, 1.f}};
    uint32_t indecies[] = {0,1,2, 2,3,0};

    vbo = createBuffer(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, vertecies, GL_STATIC_DRAW);
    ebo = createBuffer(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * 6, indecies, GL_STATIC_DRAW);

    while(!windowShouldClose){
        uint32_t startFrameTime = SDL_GetTicks();

        while (SDL_PollEvent(&events)){
            switch(events.type){
                case SDL_QUIT:
                {
                    SDL_Log("Program quit after %d ticks\n",
                            events.quit.timestamp);
                    windowShouldClose = true;
                    break;
                }
            }
        }

        glClearColor(0.5, 0.8, 0.9, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glVertexPointer(2, GL_FLOAT, sizeof(Vertex), NULL);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glEnableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glDisableClientState(GL_VERTEX_ARRAY);

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
