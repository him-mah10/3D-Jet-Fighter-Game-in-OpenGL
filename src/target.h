#include "main.h"

#ifndef TARGET_H
#define TARGET_H


class Target {
public:
    Target() {}
    Target(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double radius;
private:
    VAO *object_target; 
    VAO *object_target_circle; 
};

#endif // TARGET_H
