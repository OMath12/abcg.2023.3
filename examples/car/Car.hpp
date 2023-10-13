#ifndef CAR_HPP
#define CAR_HPP

class Car {
public:
    Car(float x, float y, float width, float height, float speed);

    void render();
    
    void handleKeyPress(int key);

    // void move();

private:
    float x;
    float y;
    float width;
    float height;
    float speed;
};

#endif

