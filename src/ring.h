#include "main.h"

#ifndef RING_H
#define RING_H


class Ring {
public:
    Ring() {}
    Ring(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void color(int which);
    double speed;
    GLfloat vertex_buffer_data_inner[9000];
    double radius_inner;
    double radius_outer;
private:
    VAO *object_inner; 
    VAO *object_outer; 
};

#endif