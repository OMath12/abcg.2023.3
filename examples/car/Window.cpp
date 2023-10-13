#include "Window.hpp"
#include "Car.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glew.h>
#include "abcgOpenGL.hpp"

Car car(-0.8f, -0.6f, 0.2f, 0.2f, 0.1f);

Window::Window(const char* title, int width, int height) : quit(false) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erro ao inicializar o SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
    if (!sdlWindow) {
        std::cerr << "Erro ao criar a janela: " << SDL_GetError() << std::endl;
        exit(2);
    }

    glContext = SDL_GL_CreateContext(sdlWindow);
    if (glContext == NULL) {
        std::cerr << "Erro ao criar o contexto OpenGL: " << SDL_GetError() << std::endl;
        exit(3);
    }

    glViewport(0, 0, width, height);
}

Window::~Window() {
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();
}

bool Window::shouldQuit() const {
    return quit;
}

void Window::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            // Lidar com o evento de fechamento da janela
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN) {
            // Verifique se uma tecla foi pressionada
            int key = event.key.keysym.sym;
            car.handleKeyPress(key);

        }
    }
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Window::render() {
    // Limpe o buffer, renderize o carro e atualize a tela
    glClear(GL_COLOR_BUFFER_BIT);
    car.render();
   SDL_GL_SwapWindow(sdlWindow);


}

