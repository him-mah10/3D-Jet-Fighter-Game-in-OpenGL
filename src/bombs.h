#include "main.h"

#ifndef BOMB_H
#define BOMB_H


class Bomb {
public:
    Bomb() {}
    Bomb(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double speed;
    double radius;
private:
    VAO *object; 
};

#endif