#include "main.h"

#ifndef PARACHUTE_H
#define PARACHUTE_H


class Parachute {
public:
    Parachute() {}
    Parachute(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double radius_base;
    double radius_top;
private:
    VAO *object_ballon;  
    VAO *object_dome;  
    VAO *object_ropes;  
    VAO *object_basket;  
};

#endif