#include "main.h"

#ifndef OCEAN_H
#define OCEAN_H


class Ocean {
public:
    Ocean() {}
    Ocean(float x, float y, float z);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    double radius;
private:
    VAO *object;
};

#endif