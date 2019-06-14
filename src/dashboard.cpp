#include "dashboard.h"
#include "main.h"

Dashboard::Dashboard(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->len=1;
    this->vertex_buffer_data[0]=0.0f;
    this->vertex_buffer_data[1]=0.0f;
    this->vertex_buffer_data[2]=0.0f;

    this->vertex_buffer_data[3]=0.0f;
    this->vertex_buffer_data[4]=0.3f;
    this->vertex_buffer_data[5]=0.0f;

    this->vertex_buffer_data[6]=this->len;
    this->vertex_buffer_data[7]=0.0f;
    this->vertex_buffer_data[8]=0.0f;

    this->vertex_buffer_data[9]=0.0f;
    this->vertex_buffer_data[10]=0.3f;
    this->vertex_buffer_data[11]=0.0f;

    this->vertex_buffer_data[12]=this->len;
    this->vertex_buffer_data[13]=0.0f;
    this->vertex_buffer_data[14]=0.0f;

    this->vertex_buffer_data[15]=this->len;
    this->vertex_buffer_data[16]=0.3f;
    this->vertex_buffer_data[17]=0.0f;

    this->object = create3DObject(GL_TRIANGLES, 6, this->vertex_buffer_data, color, GL_FILL);
    
}

void Dashboard::draw(glm::mat4 VP, color_t color) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);   
    glm::mat4 rotate    = glm::rotate((float) (0 * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    this->vertex_buffer_data[0]=0.0f;
    this->vertex_buffer_data[1]=0.0f;
    this->vertex_buffer_data[2]=0.0f;

    this->vertex_buffer_data[3]=0.0f;
    this->vertex_buffer_data[4]=0.3f;
    this->vertex_buffer_data[5]=0.0f;

    this->vertex_buffer_data[6]=this->len;
    this->vertex_buffer_data[7]=0.0f;
    this->vertex_buffer_data[8]=0.0f;

    this->vertex_buffer_data[9]=0.0f;
    this->vertex_buffer_data[10]=0.3f;
    this->vertex_buffer_data[11]=0.0f;

    this->vertex_buffer_data[12]=this->len;
    this->vertex_buffer_data[13]=0.0f;
    this->vertex_buffer_data[14]=0.0f;

    this->vertex_buffer_data[15]=this->len;
    this->vertex_buffer_data[16]=0.3f;
    this->vertex_buffer_data[17]=0.0f;
    this->object = create3DObject(GL_TRIANGLES, 6, this->vertex_buffer_data, color, GL_FILL);
    draw3DObject(this->object);
}