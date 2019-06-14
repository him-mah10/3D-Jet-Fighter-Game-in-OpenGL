#include "compass.h"
#include "main.h"

Compass::Compass(float x, float y, float z, color_t color, double radius,int type) {
    this->position = glm::vec3(x, y, z);
    this->radius = radius;

    //type == 0 -> Circle
    if(type==0)
    {
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
        }
        this->object = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data, color, GL_FILL);
    }
    if(type==1)
    {
        GLfloat vertex_buffer_data[]={
            0.0,radius,0.0,
            0.0,0.0,0.0,
            -radius/1.41421,-radius/1.41421,0.0,
            0.0,radius,0.0,
            0.0,0.0,0.0,
            radius/1.41421,-radius/1.41421,0.0,
        };
        this->object = create3DObject(GL_TRIANGLES,6, vertex_buffer_data, color, GL_FILL);
    }
    
}

void Compass::draw(glm::mat4 VP,double rotation) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);  
    glm::mat4 rotate    = glm::rotate((float) (rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}