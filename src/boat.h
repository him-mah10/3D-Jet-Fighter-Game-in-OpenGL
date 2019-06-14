#include "main.h"

#ifndef BOAT_H
#define BOAT_H


class Boat {
public:
    Boat() {}
    Boat(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
private:
    VAO *object_left;
    VAO *object_right;
    VAO *object_behind;
    VAO *object_front;
    VAO *object_down;
    VAO *object_flag;

};

#endif 