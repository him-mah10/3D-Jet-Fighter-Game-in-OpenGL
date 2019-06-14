#include "main.h"

#ifndef CANON_BALL_H
#define CANON_BALL_H


class Canon_ball {
public:
    Canon_ball() {}
    Canon_ball(float x, float y, float z,float x1,float y1,float z1);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();
    double radius;
    float plane_vertices[3];
    float ball_vertices[3];
private:
    VAO *object;
};

#endif