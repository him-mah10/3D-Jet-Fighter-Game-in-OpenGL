#include "main.h"

#ifndef COINS_H
#define COINS_H


class Coins {
public:
    Coins() {}
    Coins(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    float radius;
private:
    VAO *object; 
};

#endif