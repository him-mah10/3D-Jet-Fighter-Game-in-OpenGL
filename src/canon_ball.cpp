#include "canon_ball.h"
#include "main.h"

Canon_ball::Canon_ball(float x, float y, float z,float x1,float y1,float z1) {
    this->position = glm::vec3(x, y, z);
    this->radius = 0.4;
    this->plane_vertices[0]=x1;
    this->plane_vertices[1]=y1;
    this->plane_vertices[2]=z1;
    this->ball_vertices[0]=x;
    this->ball_vertices[1]=y;
    this->ball_vertices[2]=z;
    GLfloat vertex_buffer_data[75000];
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
    this->object = create3DObject(GL_TRIANGLES, 9000, vertex_buffer_data, COLOR_BLACK, GL_FILL);

    
}

void Canon_ball::draw(glm::mat4 VP) {
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

void Canon_ball::tick() 
{
    this->position.y+=0.35;
    this->position.x=((this->position.y-ball_vertices[1])/(ball_vertices[1]-plane_vertices[1])*(ball_vertices[0]-plane_vertices[0]))+ball_vertices[0];
    this->position.z=((this->position.y-ball_vertices[1])/(ball_vertices[1]-plane_vertices[1])*(ball_vertices[2]-plane_vertices[2]))+ball_vertices[2];
}
