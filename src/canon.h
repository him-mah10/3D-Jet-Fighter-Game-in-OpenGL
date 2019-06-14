#include "main.h"

#ifndef CANON_H
#define CANON_H


class Canon {
public:
    Canon() {}
    Canon(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    double radius;
private:
    VAO *object_main; 
};

#endif // CANON_H
