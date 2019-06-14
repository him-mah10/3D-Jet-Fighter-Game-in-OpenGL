#include "main.h"

#ifndef DASHBOARD_H
#define DASHBOARD_H


class Dashboard {
public:
    Dashboard() {}
    Dashboard(float x, float y, float z, color_t color);
    glm::vec3 position;
    void draw(glm::mat4 VP, color_t color);
    float len;
    GLfloat vertex_buffer_data[18];
private:
    VAO *object;
};

#endif