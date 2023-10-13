#include "Car.hpp"
#include <SDL.h>
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <GL/glew.h>
#include "abcgOpenGL.hpp"

Car::Car(float x, float y, float width, float height, float speed)
    : x(x), y(y), width(width), height(height), speed(speed) {}


    float minX = -1.0f;
    float minY =-0.9f;
    float maxX = 0.8f;
    float maxY = 0.0f;

void Car::handleKeyPress(int key) {

    if (key == SDLK_UP) {
        y += speed; // Mova o carro para cima
        if (y > maxY) {
            y = maxY;
        }
    } else if (key == SDLK_DOWN) {
        y -= speed; // Mova o carro para baixo
        if (y < minY) {
            y = minY;
        }
    } else if (key == SDLK_LEFT) {
        x -= speed; // Mova o carro para a esquerda
        if (x < minX) {
            x = minX;
        }
    } else if (key == SDLK_RIGHT) {
        x += speed; // Mova o carro para a direita
        if (x > maxX) {
            x = maxX;
        }
    }
}

void Car::render() {
    glColor3f(1.0f, 0.0f, 0.0f); // Cor vermelha
    glBegin(GL_QUADS);

    // Carro (retângulo principal)
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f); // Cor azul
    glBegin(GL_QUADS);
    // Carro (retângulo principal)
    glVertex2f(x+0.02, y+0.15);
    glVertex2f(x+width-0.02, y+0.15);
    glVertex2f(x+width-0.02, y + height+0.1);
    glVertex2f(x+0.02, y + height+0.1);
    glEnd();

    // Roda esquerda
    glColor3f(0.0f, 0.0f, 0.0f); // Cor preta
    glBegin(GL_QUADS);
    float wheelWidth = width * 0.2f;
    float wheelHeight = width * 0.2f;
    glVertex2f(x + width * 0.15f, y - wheelWidth);
    glVertex2f(x + width * 0.35f, y - wheelHeight);
    glVertex2f(x + width * 0.35f, y + 0.05f);
    glVertex2f(x + width * 0.15f, y + 0.05f);
    glEnd();

    // Roda direita
    glBegin(GL_QUADS);
    glVertex2f(x + width * 0.65f, y - wheelWidth);
    glVertex2f(x + width * 0.85f, y - wheelHeight);
    glVertex2f(x + width * 0.85f, y + 0.05f);
    glVertex2f(x + width * 0.65f, y + 0.05f);
    glEnd();
}
