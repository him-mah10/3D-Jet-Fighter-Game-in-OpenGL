#include "plane.h"
#include "main.h"

Plane::Plane(float x, float y, float z, color_t c) {
    this->position = glm::vec3(x, y, z);
    this->tilt = 0;
    speed = 1;
    this->radius = 0.7;
    this->rotation=0;
    this->updown=0;
    
    GLfloat vertex_buffer_data_main_body[36000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_main_body[i*9+0]=0.0f;
        vertex_buffer_data_main_body[i*9+1]=0.0f;
        vertex_buffer_data_main_body[i*9+2]=0.0f;

        vertex_buffer_data_main_body[i*9+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9+5]=0.0f;

        vertex_buffer_data_main_body[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9+8]=0.0f;
    };
    for (int i=1000;i<2000;i++)
    { 
        vertex_buffer_data_main_body[i*9+0]=0.0f;
        vertex_buffer_data_main_body[i*9+1]=0.0f;
        vertex_buffer_data_main_body[i*9+2]=3.0f;

        vertex_buffer_data_main_body[i*9+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9+4]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9+5]=3.0f;

        vertex_buffer_data_main_body[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9+8]=3.0f;
    };
    for(int i=1000;i<2000;i++)
    {
        vertex_buffer_data_main_body[i*9*2]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9*2+1]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9*2+2]=3.0f;

        vertex_buffer_data_main_body[i*9*2+3]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9*2+4]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9*2+5]=0.0f;

        vertex_buffer_data_main_body[i*9*2+6]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9*2+7]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9*2+8]=3.0f;


        vertex_buffer_data_main_body[i*9*2+9]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9*2+10]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9*2+11]=3.0f;

        vertex_buffer_data_main_body[i*9*2+12]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9*2+13]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data_main_body[i*9*2+14]=0.0f;

        vertex_buffer_data_main_body[i*9*2+15]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9*2+16]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_main_body[i*9*2+17]=0.0f;        

    }
    this->object_main_body = create3DObject(GL_TRIANGLES, 12000, vertex_buffer_data_main_body, c, GL_FILL);

    GLfloat vertex_buffer_data_front[18000];

    for(int i=0;i<2000;i++)
    {
        vertex_buffer_data_front[i*9*2]=this->radius*cos(2*3.14159265*i/1000);
        vertex_buffer_data_front[i*9*2+1]=this->radius*sin(2*3.14159265*i/1000);
        vertex_buffer_data_front[i*9*2+2]=3.0f;

        vertex_buffer_data_front[i*9*2+3]=this->radius*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_front[i*9*2+4]=this->radius*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_front[i*9*2+5]=3.0f;

        vertex_buffer_data_front[i*9*2+6]=0.0f;
        vertex_buffer_data_front[i*9*2+7]=0.0f;
        vertex_buffer_data_front[i*9*2+8]=3.7f;

    }
    this->object_front = create3DObject(GL_TRIANGLES, 6000, vertex_buffer_data_front, COLOR_ORANGE, GL_FILL);
    
    
    GLfloat vertex_buffer_data_wings[72];
    vertex_buffer_data_wings[0]=this->radius;
    vertex_buffer_data_wings[1]=0.1;
    vertex_buffer_data_wings[2]=1.8;

    vertex_buffer_data_wings[3]=this->radius;
    vertex_buffer_data_wings[4]=0.1;
    vertex_buffer_data_wings[5]=2.6;

    vertex_buffer_data_wings[6]=4*this->radius;
    vertex_buffer_data_wings[7]=0.1;
    vertex_buffer_data_wings[8]=2.2;


    vertex_buffer_data_wings[9]=this->radius;
    vertex_buffer_data_wings[10]=-0.1;
    vertex_buffer_data_wings[11]=1.8;

    vertex_buffer_data_wings[12]=this->radius;
    vertex_buffer_data_wings[13]=-0.1;
    vertex_buffer_data_wings[14]=2.6;

    vertex_buffer_data_wings[15]=4*this->radius;
    vertex_buffer_data_wings[16]=0.1;
    vertex_buffer_data_wings[17]=2.2;
 

    vertex_buffer_data_wings[18]=this->radius;
    vertex_buffer_data_wings[19]=-0.1;
    vertex_buffer_data_wings[20]=1.8;

    vertex_buffer_data_wings[21]=this->radius;
    vertex_buffer_data_wings[22]=0.1;
    vertex_buffer_data_wings[23]=1.8;

    vertex_buffer_data_wings[24]=4*this->radius;
    vertex_buffer_data_wings[25]=0.1;
    vertex_buffer_data_wings[26]=2.2;


    vertex_buffer_data_wings[27]=this->radius;
    vertex_buffer_data_wings[28]=-0.1;
    vertex_buffer_data_wings[29]=2.2;

    vertex_buffer_data_wings[30]=this->radius;
    vertex_buffer_data_wings[31]=0.1;
    vertex_buffer_data_wings[32]=2.2;

    vertex_buffer_data_wings[33]=4*this->radius;
    vertex_buffer_data_wings[34]=0.1;
    vertex_buffer_data_wings[35]=2.2;



    vertex_buffer_data_wings[0+36]=-this->radius;
    vertex_buffer_data_wings[1+36]=0.1;
    vertex_buffer_data_wings[2+36]=1.8;

    vertex_buffer_data_wings[3+36]=-this->radius;
    vertex_buffer_data_wings[4+36]=0.1;
    vertex_buffer_data_wings[5+36]=2.6;

    vertex_buffer_data_wings[6+36]=-4*this->radius;
    vertex_buffer_data_wings[7+36]=0.1;
    vertex_buffer_data_wings[8+36]=2.2;


    vertex_buffer_data_wings[9+36]=-this->radius;
    vertex_buffer_data_wings[10+36]=-0.1;
    vertex_buffer_data_wings[11+36]=1.8;

    vertex_buffer_data_wings[12+36]=-this->radius;
    vertex_buffer_data_wings[13+36]=-0.1;
    vertex_buffer_data_wings[14+36]=2.6;

    vertex_buffer_data_wings[15+36]=-4*this->radius;
    vertex_buffer_data_wings[16+36]=0.1;
    vertex_buffer_data_wings[17+36]=2.2;
 

    vertex_buffer_data_wings[18+36]=-this->radius;
    vertex_buffer_data_wings[19+36]=-0.1;
    vertex_buffer_data_wings[20+36]=1.8;

    vertex_buffer_data_wings[21+36]=-this->radius;
    vertex_buffer_data_wings[22+36]=0.1;
    vertex_buffer_data_wings[23+36]=1.8;

    vertex_buffer_data_wings[24+36]=-4*this->radius;
    vertex_buffer_data_wings[25+36]=0.1;
    vertex_buffer_data_wings[26+36]=2.2;


    vertex_buffer_data_wings[27+36]=-this->radius;
    vertex_buffer_data_wings[28+36]=-0.1;
    vertex_buffer_data_wings[29+36]=2.2;

    vertex_buffer_data_wings[30+36]=-this->radius;
    vertex_buffer_data_wings[31+36]=0.1;
    vertex_buffer_data_wings[32+36]=2.2;

    vertex_buffer_data_wings[33+36]=-4*this->radius;
    vertex_buffer_data_wings[34+36]=0.1;
    vertex_buffer_data_wings[35+36]=2.2;
    
    this->object_wings = create3DObject(GL_TRIANGLES, 2*4*3, vertex_buffer_data_wings, COLOR_ORANGE, GL_FILL);




    GLfloat vertex_buffer_data_tails[72];
    vertex_buffer_data_tails[0]=this->radius;
    vertex_buffer_data_tails[1]=0.1;
    vertex_buffer_data_tails[2]=0.0;

    vertex_buffer_data_tails[3]=this->radius;
    vertex_buffer_data_tails[4]=0.1;
    vertex_buffer_data_tails[5]=0.4;

    vertex_buffer_data_tails[6]=2*this->radius;
    vertex_buffer_data_tails[7]=0.1;
    vertex_buffer_data_tails[8]=0.2;


    vertex_buffer_data_tails[9]=this->radius;
    vertex_buffer_data_tails[10]=-0.1;
    vertex_buffer_data_tails[11]=0.0;

    vertex_buffer_data_tails[12]=this->radius;
    vertex_buffer_data_tails[13]=-0.1;
    vertex_buffer_data_tails[14]=0.4;

    vertex_buffer_data_tails[15]=2*this->radius;
    vertex_buffer_data_tails[16]=0.1;
    vertex_buffer_data_tails[17]=0.2;
 

    vertex_buffer_data_tails[18]=this->radius;
    vertex_buffer_data_tails[19]=-0.1;
    vertex_buffer_data_tails[20]=0.0;

    vertex_buffer_data_tails[21]=this->radius;
    vertex_buffer_data_tails[22]=0.1;
    vertex_buffer_data_tails[23]=0.0;

    vertex_buffer_data_tails[24]=2*this->radius;
    vertex_buffer_data_tails[25]=0.1;
    vertex_buffer_data_tails[26]=0.2;


    vertex_buffer_data_tails[27]=this->radius;
    vertex_buffer_data_tails[28]=-0.1;
    vertex_buffer_data_tails[29]=0.2;

    vertex_buffer_data_tails[30]=this->radius;
    vertex_buffer_data_tails[31]=0.1;
    vertex_buffer_data_tails[32]=0.2;

    vertex_buffer_data_tails[33]=2*this->radius;
    vertex_buffer_data_tails[34]=0.1;
    vertex_buffer_data_tails[35]=0.2;



    vertex_buffer_data_tails[0+36]=-this->radius;
    vertex_buffer_data_tails[1+36]=0.1;
    vertex_buffer_data_tails[2+36]=0.0;

    vertex_buffer_data_tails[3+36]=-this->radius;
    vertex_buffer_data_tails[4+36]=0.1;
    vertex_buffer_data_tails[5+36]=0.4;

    vertex_buffer_data_tails[6+36]=-2*this->radius;
    vertex_buffer_data_tails[7+36]=0.1;
    vertex_buffer_data_tails[8+36]=0.2;


    vertex_buffer_data_tails[9+36]=-this->radius;
    vertex_buffer_data_tails[10+36]=-0.1;
    vertex_buffer_data_tails[11+36]=0.0;

    vertex_buffer_data_tails[12+36]=-this->radius;
    vertex_buffer_data_tails[13+36]=-0.1;
    vertex_buffer_data_tails[14+36]=0.4;

    vertex_buffer_data_tails[15+36]=-2*this->radius;
    vertex_buffer_data_tails[16+36]=0.1;
    vertex_buffer_data_tails[17+36]=0.2;
 

    vertex_buffer_data_tails[18+36]=-this->radius;
    vertex_buffer_data_tails[19+36]=-0.1;
    vertex_buffer_data_tails[20+36]=0.0;

    vertex_buffer_data_tails[21+36]=-this->radius;
    vertex_buffer_data_tails[22+36]=0.1;
    vertex_buffer_data_tails[23+36]=0.0;

    vertex_buffer_data_tails[24+36]=-2*this->radius;
    vertex_buffer_data_tails[25+36]=0.1;
    vertex_buffer_data_tails[26+36]=0.2;


    vertex_buffer_data_tails[27+36]=-this->radius;
    vertex_buffer_data_tails[28+36]=-0.1;
    vertex_buffer_data_tails[29+36]=0.2;

    vertex_buffer_data_tails[30+36]=-this->radius;
    vertex_buffer_data_tails[31+36]=0.1;
    vertex_buffer_data_tails[32+36]=0.2;

    vertex_buffer_data_tails[33+36]=-2*this->radius;
    vertex_buffer_data_tails[34+36]=0.1;
    vertex_buffer_data_tails[35+36]=0.2;
    
    this->object_tails = create3DObject(GL_TRIANGLES, 2*4*3, vertex_buffer_data_tails, COLOR_ORANGE, GL_FILL);



    GLfloat vertex_buffer_data_fin[72];
    vertex_buffer_data_fin[0]=this->radius;
    vertex_buffer_data_fin[1]=0.0;
    vertex_buffer_data_fin[2]=0.0;

    vertex_buffer_data_fin[3]=-this->radius;
    vertex_buffer_data_fin[4]=0.0;
    vertex_buffer_data_fin[5]=0.0;

    vertex_buffer_data_fin[6]=0.0;
    vertex_buffer_data_fin[7]=3*this->radius;
    vertex_buffer_data_fin[8]=0.4;


    vertex_buffer_data_fin[9]=this->radius;
    vertex_buffer_data_fin[10]=0.0;
    vertex_buffer_data_fin[11]=0.4;

    vertex_buffer_data_fin[12]=-this->radius;
    vertex_buffer_data_fin[13]=0.0;
    vertex_buffer_data_fin[14]=0.4;

    vertex_buffer_data_fin[15]=0.0;
    vertex_buffer_data_fin[16]=3*this->radius;
    vertex_buffer_data_fin[17]=0.4;
 

    vertex_buffer_data_fin[18]=this->radius;
    vertex_buffer_data_fin[19]=0.0;
    vertex_buffer_data_fin[20]=0.0;

    vertex_buffer_data_fin[21]=this->radius;
    vertex_buffer_data_fin[22]=0.0;
    vertex_buffer_data_fin[23]=0.4;

    vertex_buffer_data_fin[24]=0.0;
    vertex_buffer_data_fin[25]=3*this->radius;
    vertex_buffer_data_fin[26]=0.4;


    vertex_buffer_data_fin[27]=-this->radius;
    vertex_buffer_data_fin[28]=0.0;
    vertex_buffer_data_fin[29]=0.0;

    vertex_buffer_data_fin[30]=-this->radius;
    vertex_buffer_data_fin[31]=0.0;
    vertex_buffer_data_fin[32]=0.4;

    vertex_buffer_data_fin[33]=0.0;
    vertex_buffer_data_fin[34]=3*this->radius;
    vertex_buffer_data_fin[35]=0.4;

    this->object_fin = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data_fin, COLOR_ORANGE, GL_FILL);


    GLfloat vertex_buffer_data_exhaust[9000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_exhaust[i*9+0]=0.0f;
        vertex_buffer_data_exhaust[i*9+1]=0.0f;
        vertex_buffer_data_exhaust[i*9+2]=0.0f;

        vertex_buffer_data_exhaust[i*9+3]=this->radius*cos(2*3.14159265*i/1000)*0.5;
        vertex_buffer_data_exhaust[i*9+4]=this->radius*sin(2*3.14159265*i/1000)*0.5;
        vertex_buffer_data_exhaust[i*9+5]=0.0f;

        vertex_buffer_data_exhaust[i*9+6]=this->radius*cos(2*3.14159265*(i+1)/1000)*0.5;
        vertex_buffer_data_exhaust[i*9+7]=this->radius*sin(2*3.14159265*(i+1)/1000)*0.5;
        vertex_buffer_data_exhaust[i*9+8]=0.0f;
    };
    this->object_exhaust = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data_exhaust, COLOR_RED, GL_FILL);


    GLfloat vertex_buffer_data_window[] = {
        -0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f, 
        -0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f, 
        0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f, 
        -0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f, 
        0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        -0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        -0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68,-0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        -0.4f, 0.1f+this->radius*0.68, 0.1f+3.05f,
        0.4f,-0.1f+this->radius*0.68, 0.1f+3.05f,
    };
    this->object_window = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data_window, COLOR_BLUE, GL_FILL);

    GLfloat vertex_buffer_data_target[] = {
        -0.01,0.5,17.0,
        0.01,0.5,17.0,
        -0.01,-0.5,17.0,
        0.01,0.5,17.0,
        -0.01,-0.5,17.0,
        0.01,-0.5,17.0,

        -0.5,0.01,17.0,
        -0.5,-0.01,17.0,
        0.5,0.01,17.0,
        -0.5,-0.01,17.0,
        0.5,0.01,17.0,
        0.5,-0.01,17.0,
    };
    this->object_target = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data_target, c , GL_FILL);

     GLfloat vertex_buffer_data_target_circle[6000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_target_circle[i*6]=0.5*cos(2*3.14159265*i/1000);
        vertex_buffer_data_target_circle[i*6+1]=0.5*sin(2*3.14159265*i/1000);
        vertex_buffer_data_target_circle[i*6+2]=17.0f;

        vertex_buffer_data_target_circle[i*6+3]=0.5*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_target_circle[i*6+4]=0.5*sin(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_target_circle[i*6+5]=17.0f;
    };
    this->object_target_circle = create3DObject(GL_LINES, 2000, vertex_buffer_data_target_circle, c, GL_FILL);
}

void Plane::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate_rotation * rotate_updown * rotate_tilt  );
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_front);
    draw3DObject(this->object_wings);
    draw3DObject(this->object_tails);
    draw3DObject(this->object_fin);
    draw3DObject(this->object_main_body);
    draw3DObject(this->object_exhaust);
    draw3DObject(this->object_window);
    draw3DObject(this->object_target);
    draw3DObject(this->object_target_circle);
}