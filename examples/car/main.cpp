#include "Window.hpp"
#include "Car.hpp"
#include <iostream>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/glew.h>
#include "abcgOpenGL.hpp"

int main(int argc, char* args[]) {
    // Inicializa a janela
    Window window("Car", 1200, 600);

    // Loop principal
    while (!window.shouldQuit()) {
        window.handleEvents();
        window.render();
    }

    return 0;
}