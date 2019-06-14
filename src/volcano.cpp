#include "volcano.h"
#include "main.h"

Volcano::Volcano(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
    this->radius_island = 1;
    this->radius_volcano_base=0.7;
    this->radius_volcano_top=0.4;

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

    GLfloat vertex_buffer_data_fire[9000];
    for (int i=0;i<1000;i++)
    { 
        vertex_buffer_data_fire[i*9+0]=0.0f;
        vertex_buffer_data_fire[i*9+1]=1.0f;
        vertex_buffer_data_fire[i*9+2]=0.0f;

        vertex_buffer_data_fire[i*9+3]=this->radius_volcano_top*cos(2*3.14159265*i/1000);
        vertex_buffer_data_fire[i*9+4]=1.0f;
        vertex_buffer_data_fire[i*9+5]=this->radius_volcano_top*sin(2*3.14159265*i/1000);

        vertex_buffer_data_fire[i*9+6]=this->radius_volcano_top*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_fire[i*9+7]=1.0f;
        vertex_buffer_data_fire[i*9+8]=this->radius_volcano_top*sin(2*3.14159265*(i+1)/1000);
    };
    this->object_fire = create3DObject(GL_TRIANGLES, 3000, vertex_buffer_data_fire, COLOR_RED, GL_FILL);

    GLfloat vertex_buffer_data_volcano[18000];
    for(int i=0;i<1000;i++)
    {
        vertex_buffer_data_volcano[i*18]=this->radius_volcano_top*cos(2*3.14159265*i/1000);
        vertex_buffer_data_volcano[i*18+1]=1.0f;
        vertex_buffer_data_volcano[i*18+2]=this->radius_volcano_top*sin(2*3.14159265*i/1000);

        vertex_buffer_data_volcano[i*18+3]=this->radius_volcano_base*cos(2*3.14159265*i/1000);
        vertex_buffer_data_volcano[i*18+4]=0.0f;
        vertex_buffer_data_volcano[i*18+5]=this->radius_volcano_base*sin(2*3.14159265*i/1000);

        vertex_buffer_data_volcano[i*18+6]=this->radius_volcano_top*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_volcano[i*18+7]=1.0f;
        vertex_buffer_data_volcano[i*18+8]=this->radius_volcano_top*sin(2*3.14159265*(i+1)/1000);


        vertex_buffer_data_volcano[i*18+9]=this->radius_volcano_top*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_volcano[i*18+10]=1.0f;
        vertex_buffer_data_volcano[i*18+11]=this->radius_volcano_top*sin(2*3.14159265*(i+1)/1000);

        vertex_buffer_data_volcano[i*18+12]=this->radius_volcano_base*cos(2*3.14159265*i/1000);
        vertex_buffer_data_volcano[i*18+13]=0.0f;
        vertex_buffer_data_volcano[i*18+14]=this->radius_volcano_base*sin(2*3.14159265*i/1000);

        vertex_buffer_data_volcano[i*18+15]=this->radius_volcano_base*cos(2*3.14159265*(i+1)/1000);
        vertex_buffer_data_volcano[i*18+16]=0.0f;
        vertex_buffer_data_volcano[i*18+17]=this->radius_volcano_base*sin(2*3.14159265*(i+1)/1000);        

    }
    this->object_volcano = create3DObject(GL_TRIANGLES, 6000, vertex_buffer_data_volcano, COLOR_VOLCANO, GL_FILL);
    
}

void Volcano::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_island);
    draw3DObject(this->object_volcano);
    draw3DObject(this->object_fire);
}