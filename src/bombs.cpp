#include "bombs.h"
#include "main.h"

Bomb::Bomb(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->speed = 0.1;
    this->radius = 0.2;
    
    GLfloat vertex_buffer_data[54000];
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
        vertex_buffer_data[i*9+1]=-0.5f;
        vertex_buffer_data[i*9+2]=0.0f;

        vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+4]=-0.5f;
        vertex_buffer_data[i*9+5]=this->radius*sin(2*3.14159265*i/1000);

        vertex_buffer_data[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+7]=-0.5f;
        vertex_buffer_data[i*9+8]=this->radius*sin(2*3.14159265*(i+1)/1000);
    };
    for(int i=1000;i<2000;i++)
    {
        vertex_buffer_data[i*9*2]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+1]=-0.5f;
        vertex_buffer_data[i*9*2+2]=this->radius*sin(2*3.14159265*i/1000);

        vertex_buffer_data[i*9*2+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+4]=0.0f;
        vertex_buffer_data[i*9*2+5]=this->radius*sin(2*3.14159265*i/1000);

        vertex_buffer_data[i*9*2+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+7]=-0.5f;
        vertex_buffer_data[i*9*2+8]=this->radius*sin(2*3.14159265*(i+1)/1000);


        vertex_buffer_data[i*9*2+9]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+10]=-0.50f;
        vertex_buffer_data[i*9*2+11]=this->radius*sin(2*3.14159265*(i+1)/1000);

        vertex_buffer_data[i*9*2+12]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9*2+13]=0.0f;
        vertex_buffer_data[i*9*2+14]=this->radius*sin(2*3.14159265*i/1000);

        vertex_buffer_data[i*9*2+15]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9*2+16]=0.0f;        
        vertex_buffer_data[i*9*2+17]=this->radius*sin(2*3.14159265*(i+1)/1000);

    }
    

    for(int i=4000;i<5000;i++)
    {
        vertex_buffer_data[i*9]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data[i*9+1]=-0.5f;
        vertex_buffer_data[i*9+2]=this->radius*sin(2*3.14159265*i/1000);

        vertex_buffer_data[i*9+3]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data[i*9+4]=-0.5f;
        vertex_buffer_data[i*9+5]=this->radius*sin(2*3.14159265*(i+1)/1000);

        vertex_buffer_data[i*9+6]=0.0f;
        vertex_buffer_data[i*9+7]=-0.7f;
        vertex_buffer_data[i*9+8]=0.0f;

    }
    this->object = create3DObject(GL_TRIANGLES, 15000, vertex_buffer_data, COLOR_BLACK, GL_FILL);
    
}

void Bomb::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);   
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}