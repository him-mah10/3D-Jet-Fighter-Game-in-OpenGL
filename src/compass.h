#include "main.h"

#ifndef COMPASS_H
#define COMPASS_H


class Compass {
public:
    Compass() {}
    Compass(float x, float y, float z, color_t color, double radius,int type);
    glm::vec3 position;
    void draw(glm::mat4 VP,double rotation);
    double radius;
private:
    VAO *object;
};

#endif