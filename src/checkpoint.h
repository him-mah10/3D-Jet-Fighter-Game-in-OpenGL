#include "main.h"

#ifndef CHECKPOINT_H
#define CHECKPOINT_H


class Checkpoint {
public:
    Checkpoint() {}
    Checkpoint(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double radius_island;
private:
    VAO *object_island;
};

#endif