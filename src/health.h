#include "main.h"

#ifndef HEALTH_H
#define HEALTH_H


class Health {
public:
    Health() {}
    Health(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
private:
    VAO *object; 
};

#endif