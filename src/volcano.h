#include "main.h"

#ifndef VOLCANO_H
#define VOLCANO_H


class Volcano {
public:
    Volcano() {}
    Volcano(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double radius_island;
    double radius_fire;
    double radius_volcano_base;
    double radius_volcano_top;
private:
    VAO *object_island;
    VAO *object_volcano;
    VAO *object_fire;    
};

#endif