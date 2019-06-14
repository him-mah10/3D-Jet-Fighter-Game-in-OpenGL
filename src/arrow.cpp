#include "arrow.h"
#include "main.h"

Arrow::Arrow(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    GLfloat vertex_buffer_data[]={
        -0.2,0.8,0.0,
        0.2,0.8,0.0,
        -0.2,-0.8,0.0,
        0.2,0.8,0.0,
        -0.2,-0.8,0.0,
        0.2,-0.8,0.0,

        0.0,-1.4,0.0,
        -0.6,-0.8,0.0,
        0.6,-0.6,0.0,

        0.0,0.8,-0.2,
        0.0,0.8,0.2,
        0.0,-0.8,-0.2,
        0.0,0.8,0.2,
        0.0,-0.8,-0.2,
        0.0,-0.8,0.2,

        0.0,-1.4,0.0,
        0.0,-0.8,-0.6,
        0.0,-0.6,0.6,
    };
    this->object = create3DObject(GL_TRIANGLES,18, vertex_buffer_data, COLOR_RED, GL_FILL);
    
}

void Arrow::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}