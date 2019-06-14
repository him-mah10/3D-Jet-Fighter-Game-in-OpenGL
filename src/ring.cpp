#include "ring.h"
#include "main.h"

Ring::Ring(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->speed = 1.5;
    this->radius_inner = 2;
    this->radius_outer = 2.5;
    
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_inner[i*9+0]=0.0f;
        vertex_buffer_data_inner[i*9+1]=0.0f;
        vertex_buffer_data_inner[i*9+2]=0.0f;

        vertex_buffer_data_inner[i*9+3]=this->radius_inner*cos(2*3.14159265*i/1000);
        vertex_buffer_data_inner[i*9+4]=this->radius_inner*sin(2*3.14159265*i/1000);
        vertex_buffer_data_inner[i*9+5]=0.0f;

        vertex_buffer_data_inner[i*9+6]=this->radius_inner*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_inner[i*9+7]=this->radius_inner*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_inner[i*9+8]=0.0f;
    }
    this->object_inner = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data_inner, COLOR_BACKGROUND, GL_FILL);

    GLfloat vertex_buffer_data_outer[9000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_outer[i*9+0]=0.0f;
        vertex_buffer_data_outer[i*9+1]=0.0f;
        vertex_buffer_data_outer[i*9+2]=0.0f;

        vertex_buffer_data_outer[i*9+3]=this->radius_outer*cos(2*3.14159265*i/1000);
        vertex_buffer_data_outer[i*9+4]=this->radius_outer*sin(2*3.14159265*i/1000);
        vertex_buffer_data_outer[i*9+5]=0.0f;

        vertex_buffer_data_outer[i*9+6]=this->radius_outer*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_outer[i*9+7]=this->radius_outer*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_outer[i*9+8]=0.0f;
    }
    this->object_outer = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data_outer, COLOR_SMOKE, GL_FILL);
    
}

void Ring::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_outer);
    draw3DObject(this->object_inner);
}

void Ring::color(int which) {
    if(!which)
        this->object_inner = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data_inner, COLOR_OCEAN, GL_FILL);
    else
        this->object_inner = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data_inner, COLOR_BACKGROUND, GL_FILL);
}