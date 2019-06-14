#include "parachute.h"
#include "main.h"

Parachute::Parachute(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->radius_base=0.4;
    this->radius_top=0.7;

    GLfloat vertex_buffer_data_ballon[18000];
    
    for(int i=0;i<1000;i++)
    {
        vertex_buffer_data_ballon[i*18]=this->radius_base*cos(2*3.14159265*i/1000);
        vertex_buffer_data_ballon[i*18+1]=-2.0f;
        vertex_buffer_data_ballon[i*18+2]=this->radius_base*sin(2*3.14159265*i/1000);

        vertex_buffer_data_ballon[i*18+3]=this->radius_top*cos(2*3.14159265*i/1000);
        vertex_buffer_data_ballon[i*18+4]=0.0f;
        vertex_buffer_data_ballon[i*18+5]=this->radius_top*sin(2*3.14159265*i/1000);

        vertex_buffer_data_ballon[i*18+6]=this->radius_base*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_ballon[i*18+7]=-2.0f;
        vertex_buffer_data_ballon[i*18+8]=this->radius_base*sin(2*3.14159265*(i+1)/1000);


        vertex_buffer_data_ballon[i*18+9]=this->radius_base*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_ballon[i*18+10]=-2.0f;
        vertex_buffer_data_ballon[i*18+11]=this->radius_base*sin(2*3.14159265*(i+1)/1000);

        vertex_buffer_data_ballon[i*18+12]=this->radius_top*cos(2*3.14159265*i/1000);
        vertex_buffer_data_ballon[i*18+13]=0.0f;
        vertex_buffer_data_ballon[i*18+14]=this->radius_top*sin(2*3.14159265*i/1000);

        vertex_buffer_data_ballon[i*18+15]=this->radius_top*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_ballon[i*18+16]=0.0f;
        vertex_buffer_data_ballon[i*18+17]=this->radius_top*sin(2*3.14159265*(i+1)/1000);        

    }
    this->object_ballon = create3DObject(GL_TRIANGLES, 6000, vertex_buffer_data_ballon, COLOR_ORANGE, GL_FILL);

    GLfloat vertex_buffer_data_dome[27000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_dome[i*9+0]=0.0f;
        vertex_buffer_data_dome[i*9+1]=0.0f;
        vertex_buffer_data_dome[i*9+2]=0.0f;

        vertex_buffer_data_dome[i*9+3]=this->radius_top*cos(2*3.14159265*i/1000);
        vertex_buffer_data_dome[i*9+4]=0.0f;
        vertex_buffer_data_dome[i*9+5]=this->radius_top*sin(2*3.14159265*i/1000);

        vertex_buffer_data_dome[i*9+6]=this->radius_top*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_dome[i*9+7]=0.0f;
        vertex_buffer_data_dome[i*9+8]=this->radius_top*sin(2*3.14159265*(i+1)/1000);
    };
    for (int i=1000;i<2000;i++)
    { 
        vertex_buffer_data_dome[i*9+0]=0.0f;
        vertex_buffer_data_dome[i*9+1]=0.0f;
        vertex_buffer_data_dome[i*9+2]=0.0f;

        vertex_buffer_data_dome[i*9+3]=this->radius_top*cos(2*3.14159265*i/1000);
        vertex_buffer_data_dome[i*9+4]=this->radius_top*sin(2*3.14159265*i/1000);
        vertex_buffer_data_dome[i*9+5]=0.0f;

        vertex_buffer_data_dome[i*9+6]=this->radius_top*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_dome[i*9+7]=this->radius_top*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_dome[i*9+8]=0.0f;
    };
    for (int i=2000;i<3000;i++)
    { 
        vertex_buffer_data_dome[i*9+0]=0.0f;
        vertex_buffer_data_dome[i*9+1]=0.0f;
        vertex_buffer_data_dome[i*9+2]=0.0f;

        vertex_buffer_data_dome[i*9+3]=0.0f;
        vertex_buffer_data_dome[i*9+4]=this->radius_top*cos(2*3.14159265*i/1000);
        vertex_buffer_data_dome[i*9+5]=this->radius_top*sin(2*3.14159265*i/1000);

        vertex_buffer_data_dome[i*9+6]=0.0f;
        vertex_buffer_data_dome[i*9+7]=this->radius_top*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_dome[i*9+8]=this->radius_top*sin(2*3.14159265*(i+1)/1000);
    };
    this->object_dome = create3DObject(GL_TRIANGLES, 9000, vertex_buffer_data_dome, COLOR_ORANGE, GL_FILL);

    GLfloat vertex_buffer_data_basket[18000];
    for(int i=0;i<1000;i++)
    {
        vertex_buffer_data_basket[i*9*2]=this->radius_base*cos(2*3.14159265*i/1000);
        vertex_buffer_data_basket[i*9*2+1]=0.7f-3.5f;
        vertex_buffer_data_basket[i*9*2+2]=this->radius_base*sin(2*3.14159265*i/1000);

        vertex_buffer_data_basket[i*9*2+3]=this->radius_base*cos(2*3.14159265*i/1000);
        vertex_buffer_data_basket[i*9*2+4]=0.0f-3.5f;
        vertex_buffer_data_basket[i*9*2+5]=this->radius_base*sin(2*3.14159265*i/1000);

        vertex_buffer_data_basket[i*9*2+6]=this->radius_base*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_basket[i*9*2+7]=0.7f-3.5f;
        vertex_buffer_data_basket[i*9*2+8]=this->radius_base*sin(2*3.14159265*(i+1)/1000);


        vertex_buffer_data_basket[i*9*2+9]=this->radius_base*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_basket[i*9*2+10]=0.7f-3.5f;
        vertex_buffer_data_basket[i*9*2+11]=this->radius_base*sin(2*3.14159265*(i+1)/1000);

        vertex_buffer_data_basket[i*9*2+12]=this->radius_base*cos(2*3.14159265*i/1000);
        vertex_buffer_data_basket[i*9*2+13]=0.0f-3.5f;
        vertex_buffer_data_basket[i*9*2+14]=this->radius_base*sin(2*3.14159265*i/1000);

        vertex_buffer_data_basket[i*9*2+15]=this->radius_base*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_basket[i*9*2+16]=0.0f-3.5f;        
        vertex_buffer_data_basket[i*9*2+17]=this->radius_base*sin(2*3.14159265*(i+1)/1000);

    }
    this->object_basket = create3DObject(GL_TRIANGLES, 6000, vertex_buffer_data_basket, COLOR_CANON, GL_FILL);   

    GLfloat vertex_buffer_data_ropes[]={
         radius_base/2,-2.0f,radius_base/2,
         radius_base/2+0.1,-2.0f,radius_base/2+0.1,
         radius_base/2,-3.5f,radius_base/2,

        -(radius_base/2),-2.0f,-(radius_base/2),
        -(radius_base/2+0.1),-2.0f,-(radius_base/2+0.1),
        -(radius_base/2),-3.5f,-(radius_base/2),

        (radius_base/2),-2.0f,-(radius_base/2),
        (radius_base/2+0.1),-2.0f,-(radius_base/2+0.1),
        (radius_base/2),-3.5f,-(radius_base/2),

        -(radius_base/2),-2.0f,(radius_base/2),
        -(radius_base/2+0.1),-2.0f,(radius_base/2+0.1),
        -(radius_base/2),-3.5f,(radius_base/2),
    };
    this->object_ropes = create3DObject(GL_TRIANGLES,12, vertex_buffer_data_ropes, COLOR_BLACK, GL_FILL);   

}

void Parachute::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_ballon);
    draw3DObject(this->object_dome);
    draw3DObject(this->object_ropes);
    draw3DObject(this->object_basket);
}