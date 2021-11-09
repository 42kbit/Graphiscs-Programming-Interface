cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME SDL_OpenGL0)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
src/main.cpp
src/Modules/FileReader.cpp
src/Modules/ShaderCompiler.cpp
src/Modules/TextureReader.cpp

src/GlWrappers/Buffer.cpp 
src/GlWrappers/Shader.cpp
src/GlWrappers/Texture.cpp
)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_subdirectory(external/SDL2)
target_link_libraries(${PROJECT_NAME} SDL2)

add_subdirectory(external/glm)

target_include_directories(${PROJECT_NAME} PUBLIC src/)
target_include_directories(${PROJECT_NAME} PUBLIC external/)
target_include_directories(${PROJECT_NAME} PUBLIC external/SDL2/include)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)