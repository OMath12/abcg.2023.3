#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "abcgOpenGL.hpp"
#include <SDL_opengl.h>


class Window {
public:

    Window(const char* title, int width, int height);
    ~Window();

    bool shouldQuit() const;
    void handleEvents();
    void render();


  private:
    SDL_Window* sdlWindow;
    SDL_GLContext glContext;
    bool quit;

};


#endif
