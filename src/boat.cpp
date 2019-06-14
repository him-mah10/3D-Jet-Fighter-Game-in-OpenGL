#include "boat.h"
#include "main.h"

Boat::Boat(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
    GLfloat vertex_buffer_data_left[] =   {
        //left
            -2.0,2.0,-2.0,
            -1.0,1.0,-1.0,
            -1.0,1.0,1.0,
            -2.0,2.0,-2.0,
            -2.0,2.0,2.0,
            -1.0,1.0,1.0,};

    GLfloat vertex_buffer_data_right[] =   {
            //right
            1.0,1.0,1.0,
            2.0,2.0,2.0,
            2.0,2.0,-2.0,
            1.0,1.0,1.0,
            1.0,1.0,-1.0,
            2.0,2.0,-2.0,};
    GLfloat vertex_buffer_data_front[] =   {
            //front
            -2.0,2.0,-2.0,
            -1.0,1.0,-1.0,
            1.0,1.0,-1.0,
            -2.0,2.0,-2.0,
            2.0,2.0,-2.0,
            1.0,1.0,-1.0,
    };
    GLfloat vertex_buffer_data_behind[] =   {
            //back
            1.0,1.0,1.0,
            2.0,2.0,2.0,
            -2.0,2.0,2.0,
            1.0,1.0,1.0,
            -1.0,1.0,1.0,
            -2.0,2.0,2.0,};
    GLfloat vertex_buffer_data_down[] =   {
            //bottom
            -1.0,1.0,1.0,
            -1.0,1.0,-1.0,
            1.0,1.0,-1.0,
            -1.0,1.0,1.0,
            1.0,1.0,1.0,
            1.0,1.0,-1.0,};


    GLfloat vertex_buffer_data_flag[] = {
            0.0,1.0,0.0,
            0.2,1.0,0.0,
            0.0,4.0,0.0,

            0.2,1.0,0.0,
            0.0,4.0,0.0,
            0.2,4.0,0.0,

            0.2, 2.0, 0.0,
            0.6, 3.0, 0.0,
            0.2, 4.0, 0.0,
        };

    this->object_left = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_left, COLOR_CANON, GL_FILL);
    this->object_right = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_right, COLOR_CANON, GL_FILL);
    this->object_behind = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_behind, COLOR_BLACK, GL_FILL);
    this->object_front = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_front, COLOR_BLACK, GL_FILL);
    this->object_down = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data_down, COLOR_WHITE, GL_FILL);
    this->object_flag = create3DObject(GL_TRIANGLES, 9, vertex_buffer_data_flag, COLOR_COINS, GL_FILL);
}

void Boat::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (0.0 * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object_left);
    draw3DObject(this->object_right);
    draw3DObject(this->object_behind);
    draw3DObject(this->object_front);
    draw3DObject(this->object_down);
    draw3DObject(this->object_flag);

}
