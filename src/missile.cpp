#include "missile.h"
#include "main.h"

Missile::Missile(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->speed = 0.5;
    this->radius = 0.08;
    
    GLfloat vertex_buffer_data[36000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data[i*9+0]=0.0f;
        vertex_buffer_data[i*9+1]=0.0f;
        vertex_buffer_data[i*9+2]=0.0f;

        vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+5]=0.0f;

        vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+8]=0.0f;
    };
    for (int i=1000;i<2000;i++)
    { 
        vertex_buffer_data[i*9+0]=0.0f;
        vertex_buffer_data[i*9+1]=0.0f;
        vertex_buffer_data[i*9+2]=0.1f;

        vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+5]=0.1f;

        vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+8]=0.1f;
    };
    for(int i=1000;i<2000;i++)
    {
        vertex_buffer_data[i*9*2]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+1]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+2]=0.1f;

        vertex_buffer_data[i*9*2+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+4]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+5]=0.0f;

        vertex_buffer_data[i*9*2+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+8]=0.1f;


        vertex_buffer_data[i*9*2+9]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+10]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+11]=0.1f;

        vertex_buffer_data[i*9*2+12]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+13]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+14]=0.0f;

        vertex_buffer_data[i*9*2+15]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+16]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+17]=0.0f;        

    }
    this->object = create3DObject(GL_TRIANGLES, 12000, vertex_buffer_data, COLOR_BLACK, GL_FILL);
    
}

void Missile::draw(glm::mat4 VP) {
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

void Missile::tick() {
    
}

