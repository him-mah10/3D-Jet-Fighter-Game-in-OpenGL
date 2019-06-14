#include "coins.h"
#include "main.h"

Coins::Coins(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    GLfloat vertex_buffer_data[27000];
    this->radius=0.8;
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data[i*9+0]=0.0f;
        vertex_buffer_data[i*9+1]=0.0f;
        vertex_buffer_data[i*9+2]=0.0f;

        vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+4]=0.0f;
        vertex_buffer_data[i*9+5]=this->radius*sin(2*3.14159265*i/1000);

        vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+7]=0.0f;
        vertex_buffer_data[i*9+8]=this->radius*sin(2*3.14159265*(i+1)/1000);
    };
    for (int i=1000;i<2000;i++)
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
    for (int i=2000;i<3000;i++)
    { 
        vertex_buffer_data[i*9+0]=0.0f;
        vertex_buffer_data[i*9+1]=0.0f;
        vertex_buffer_data[i*9+2]=0.0f;

        vertex_buffer_data[i*9+3]=0.0f;
        vertex_buffer_data[i*9+4]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+5]=this->radius*sin(2*3.14159265*i/1000);

        vertex_buffer_data[i*9+6]=0.0f;
        vertex_buffer_data[i*9+7]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+8]=this->radius*sin(2*3.14159265*(i+1)/1000);
    };
    this->object = create3DObject(GL_TRIANGLES, 9000, vertex_buffer_data, COLOR_COINS, GL_FILL);    
}

void Coins::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.8f);
    glm::mat4 translate = glm::translate (this->position);   
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}