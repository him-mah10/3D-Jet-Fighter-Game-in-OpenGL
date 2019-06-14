#include "main.h"

#ifndef PLANE_H
#define PLANE_H


class Plane {
public:
    Plane() {}
    Plane(float x, float y, float z, color_t c);
    glm::vec3 position;
    float rotation;
    float tilt;
    float updown;
    void draw(glm::mat4 VP);
    double speed;
    double radius;
    glm::mat4 rotate_tilt;
    glm::mat4 rotate_rotation;
    glm::mat4 rotate_updown;
private:
    VAO *object_main_body;
    VAO *object_front;
    VAO *object_wings;
    VAO *object_tails;
    VAO *object_fin;
    VAO *object_exhaust; 
    VAO *object_window; 
    VAO *object_target; 
    VAO *object_target_circle; 

};

#endif // PLANE_H
