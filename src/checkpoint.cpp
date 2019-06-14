#include "checkpoint.h"
#include "main.h"

Checkpoint::Checkpoint(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->radius_island = 2.5;

    GLfloat vertex_buffer_data_island[12000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_island[i*9+0]=0.0f;
        vertex_buffer_data_island[i*9+1]=0.0f;
        vertex_buffer_data_island[i*9+2]=0.0f;

        vertex_buffer_data_island[i*9+3]=this->radius_island*cos(2*3.14159265*i/1000);
        vertex_buffer_data_island[i*9+4]=0.0f;
        vertex_buffer_data_island[i*9+5]=this->radius_island*sin(2*3.14159265*i/1000);

        vertex_buffer_data_island[i*9+6]=this->radius_island*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_island[i*9+7]=0.0f;
        vertex_buffer_data_island[i*9+8]=this->radius_island*sin(2*3.14159265*(i+1)/1000);
    };
    this->object_island = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data_island, COLOR_ISLAND, GL_FILL);
}

void Checkpoint::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);   
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_island);
}