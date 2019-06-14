#include "main.h"

#ifndef MISSILE_H
#define MISSILE_H


class Missile {
public:
    Missile() {}
    Missile(float x, float y, float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void tick();
    double speed;
    double radius;
 	float x1,x2,y1,y2,z1,z2;
 	double rotation_angle;
 	double updown_angle;
private:
    VAO *object; 
};

#endif // MISSILE_H
