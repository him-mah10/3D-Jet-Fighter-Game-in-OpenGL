#include "main.h"

#ifndef FUEL_H
#define FUEL_H


class Fuel {
public:
    Fuel() {}
    Fuel(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();
    double radius;
private:
    VAO *object_main; 
    VAO *object_rings; 
};

#endif // FUEL_H
