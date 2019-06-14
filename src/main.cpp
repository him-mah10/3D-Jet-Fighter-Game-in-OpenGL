#include "main.h"
#include "timer.h"
#include "plane.h"
#include "ocean.h"
#include "volcano.h"
#include "dashboard.h"
#include "bombs.h"
#include "ring.h"
#include "missile.h"
#include "fuel.h"
#include "checkpoint.h"
#include "boat.h"
#include "canon.h"
#include "health.h"
#include "compass.h"
#include "canon_ball.h"
#include "parachute.h"
#include "arrow.h"
#include "coins.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

Plane plane;
Ocean ocean;
Arrow arrow;
Compass main_compass;
Compass main_compass_border;
Compass aeoplane_compass;
Compass checkpoint1;
Compass checkpoint2;
vector <Boat> boat;
vector <Health> health;
vector <Coins> coins;
vector <Parachute> chute;
vector <Compass> volcano_compass; 
vector <Compass> health_compass; 
vector <Compass> boat_compass; 
vector <Compass> coins_compass; 
vector <Canon> canon;
vector <Canon_ball> canon_ball;
vector <Checkpoint> checkpoint;
vector <Ring> ring;
vector <Volcano> volcanos;
vector <Bomb> bomb;
vector <Missile> missile;
Dashboard speed_dash;
Dashboard fuel_dash;
vector <Fuel> fuel;
Dashboard altitude_dash;
Dashboard health_dash;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = -90;
float camera=0;
bool checkpoint_one_conquered,checkpoint_two_conquered;
int number_of_volcanos, bomb_launch,missile_launch,score=0,which_view=0,number_of_health,number_of_coins;
float health_count=100;
float xeye,yeye,zeye,xtarget,ytarget,ztarget;
double px=0,py=0,cam_heli_x=0,cam_heli_y=0;    

Timer t60(1.0 / 60);

float mod(float a)
{
    return (a<0)?a*=-1:a;
}
void draw() {
    speed_dash.position.x=-3.8;
    speed_dash.position.y=2.5;
    speed_dash.position.z=0;

    fuel_dash.position.x=-3.8;
    fuel_dash.position.y=3;
    fuel_dash.position.z=0;

    altitude_dash.position.x=-3.8;
    altitude_dash.position.y=3.5;
    altitude_dash.position.z=0;

    health_dash.position.x=-3.8;
    health_dash.position.y=2.0;
    health_dash.position.z=0;

    altitude_dash.len = 2 * (plane.position.y+7.5) / 22.5;
                    
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram (programID);

    double theta = (plane.rotation)*(M_PI/180);
    switch(which_view)
    {   
        //follow cam
        case 0 :    xeye=plane.position.x-30*sin(theta);
                    yeye=plane.position.y+7.5;
                    zeye=plane.position.z-30*cos(theta);
                    xtarget=plane.position.x+10*sin(theta);
                    ytarget=plane.position.y;
                    ztarget=plane.position.z+10*cos(theta);

                    if(ring.size()>0)
                        ring[0].color(1);
            break;
        //top view
        case 1 :    xeye = plane.position.x;
                    yeye = 91;
                    zeye = plane.position.z;
                    xtarget=plane.position.x;
                    ytarget=plane.position.y;
                    ztarget=plane.position.z+1;
                    if(ring.size()>0)
                        ring[0].color(0);
            break;
        //plane view
        case 2 :    
                    xeye = plane.position.x+3*sin(theta);
                    yeye = plane.position.y+2;
                    zeye = plane.position.z+3*cos(theta);
                    xtarget = plane.position.x+10*sin(theta);
                    ytarget = plane.position.y+2;
                    ztarget = plane.position.z+10*cos(theta);
                    if(ring.size()>0)
                        ring[0].color(1);
            break;
        //tower
        case 3 :
            xeye = -30+plane.position.x;
            yeye= 30+plane.position.y;
            zeye = plane.position.z;
            xtarget = plane.position.x;
            ytarget = plane.position.y;
            ztarget = plane.position.z;
            if(ring.size()>0)
                ring[0].color(0);
            break;
        //Heli-cam    
        case 4 :
            double x,y;
            glfwGetCursorPos(window, &x,&y);
            cam_heli_x += + (x - px) * 90 / 1800;
            cam_heli_y -= + (y - py) * 90 / 1000;
            px = x;
            py = y;
            xtarget = plane.position.x;
            ytarget = plane.position.y;
            ztarget = plane.position.z;
            xeye = plane.position.x + (40-10*screen_zoom)*cos(cam_heli_x*M_PI/180.0f)*sin(cam_heli_y*M_PI/180.0f);
            yeye = plane.position.y + (40-10*screen_zoom)*cos(cam_heli_y*M_PI/180.0f);
            zeye = plane.position.z + (40-10*screen_zoom)*sin(cam_heli_x*M_PI/180.0f)*sin(cam_heli_y*M_PI/180.0f);
            if(ring.size()>0)
                ring[0].color(1);
            break;

    }
    glm::vec3 eye ( xeye,yeye,zeye );
    glm::vec3 target (xtarget, ytarget, ztarget);
    glm::vec3 up (0, 1, 0);

    Matrices.view = glm::lookAt( eye, target, up );
    glm::mat4 VP = Matrices.projection * Matrices.view;

    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
    glm::vec3 eye1 ( 0,0,10 );
    glm::vec3 target1 (0, 0, -10);
    glm::vec3 up1 (0, 1, 0);
    Matrices.view = glm::lookAt( eye1, target1, up1 );
    glm::mat4 VPO = Matrices.projection * Matrices.view;
    speed_dash.draw(VPO,COLOR_BLACK);
    altitude_dash.draw(VPO,COLOR_WHITE);
    fuel_dash.draw(VPO,COLOR_RED);
    health_dash.draw(VPO,COLOR_GREEN);
    main_compass_border.draw(VPO,0.0);
    main_compass.draw(VPO,0.0);
    if(!checkpoint_one_conquered)
        checkpoint1.draw(VPO,0.0);
    if(!checkpoint_two_conquered)
        checkpoint2.draw(VPO,0.0);
    aeoplane_compass.draw(VPO,plane.rotation);
    for(int i=0;i<number_of_volcanos;i++)
    {
        volcano_compass[i].draw(VPO,0.0);
    }
    for(int i=0;i<boat.size();i++)
    {
        boat_compass[i].draw(VPO,0.0);
    }
    for(int i=0;i<number_of_health;i++)
    {
        health_compass[i].draw(VPO,0.0);
    }
    for(int i=0;i<number_of_coins;i++)
    {
        coins_compass[i].draw(VPO,0.0);
    }
    Matrices.projection = glm::perspective(glm::radians(45.0f),3.0f/4.0f,0.1f,100.0f);
    Matrices.view = glm::lookAt( eye, target, up );
    
    glm::mat4 MVP;
    
    for(int i=0;i<bomb.size();i++)
        bomb[i].draw(VP);  
    for(int i=0;i<missile.size();i++)
        missile[i].draw(VP);

    if(ring.size()>0)
        ring[0].draw(VP);
    
    for(int i=0;i<chute.size();i++)
        chute[i].draw(VP);
    ocean.draw(VP);
    for(int i=0;i<boat.size();i++)
        boat[i].draw(VP);
    for(int i=0;i<health.size();i++)
        health[i].draw(VP);
    for(int i=0;i<coins.size();i++)
        coins[i].draw(VP);
    arrow.draw(VP);
    if(fuel.size()>0)
        fuel[0].draw(VP);  
    for(int i=0;i<number_of_volcanos;i++)
    {
        volcanos[i].draw(VP);
    }
    
    for(int i=0;i<checkpoint.size();i++)
        checkpoint[i].draw(VP);
    for(int i=0;i<canon.size();i++)
        canon[i].draw(VP);
    for(int i=0;i<canon_ball.size();i++)
    {
        canon_ball[i].draw(VP);
    }
    plane.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int up = glfwGetKey(window, GLFW_KEY_SPACE);
    int down = glfwGetKey(window, GLFW_KEY_S);
    int left_tilt = glfwGetKey(window, GLFW_KEY_A);
    int right_tilt = glfwGetKey(window, GLFW_KEY_D);
    int clockwise_rot = glfwGetKey(window, GLFW_KEY_LEFT);
    int counter_clockwise_rot = glfwGetKey(window, GLFW_KEY_RIGHT);
    int forward = glfwGetKey(window, GLFW_KEY_W);
    int up_updown = glfwGetKey(window, GLFW_KEY_UP);
    int down_updown = glfwGetKey(window, GLFW_KEY_DOWN);
    if(bomb_launch)
    {
        Bomb m;
        m = Bomb(plane.position.x, plane.position.y-0.1 , plane.position.z);
        bomb.push_back(m);
        bomb_launch=0;
    }
    if(missile_launch)
    {
        Missile m;
        m = Missile(plane.position.x,plane.position.y,plane.position.z);
        missile_launch=0;
        m.rotation_angle=plane.rotation;
        m.updown_angle=plane.updown;
        missile.push_back(m);

    }
    if(up && plane.position.y<=15)
    {
        plane.position.y+=0.05;
    }
    if(down && plane.position.y>=-7.5)
    {
        plane.position.y-=0.05;
    }
    if(left_tilt)
    {
        plane.tilt-=0.5;
        plane.rotate_tilt = glm::rotate((float) (plane.tilt * M_PI / 180.0f), glm::vec3(0, 0, 1));
    }
    if(right_tilt)
    {
        plane.tilt+=0.5;
        plane.rotate_tilt = glm::rotate((float) (plane.tilt * M_PI / 180.0f), glm::vec3(0, 0, 1));
    }
    if(up_updown)
    {
        plane.updown-=0.5;
        plane.rotate_updown = glm::rotate((float) (plane.updown * M_PI / 180.0f), glm::vec3(1, 0, 0));
    }
    if(down_updown)
    {
        plane.updown+=0.5;
        plane.rotate_updown = glm::rotate((float) (plane.updown * M_PI / 180.0f), glm::vec3(1, 0, 0));
    }
    if(clockwise_rot)
    {
        plane.rotation+=0.5;
        plane.rotate_rotation = glm::rotate((float) (plane.rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));   
    }
    if(counter_clockwise_rot)
    {
        plane.rotation-=0.5;
        plane.rotate_rotation = glm::rotate((float) (plane.rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));   
    }
    if(forward)// && plane.position.z<=19 && plane.position.z>=-19)
    {
        float a=plane.position.z+(cos(plane.rotation * M_PI / 180.0f)*0.1);
        float b=plane.position.x+(sin(plane.rotation * M_PI / 180.0f)*0.1);
        if(a*a+b*b<90*90)
        {
            plane.position.z+=(cos(plane.rotation * M_PI / 180.0f)*0.1);
            plane.position.x+=(sin(plane.rotation * M_PI / 180.0f)*0.1);
            for(int i=0;i<number_of_volcanos;i++)
            {
                if( plane.position.x > volcanos[i].position.x-3.5 && plane.position.x < volcanos[i].position.x+3.5 && plane.position.z > volcanos[i].position.z-3.5 && plane.position.z < volcanos[i].position.z+3.5 )
                    {
                        quit(window);
                    }            
            }
            speed_dash.len=2;
            fuel_dash.len-=0.0004;
            if(fuel.size()>0)
              if( plane.position.x > fuel[0].position.x-3.5 && plane.position.x < fuel[0].position.x+3.5 && plane.position.z > fuel[0].position.z-3.5 && plane.position.z < fuel[0].position.z+3.5  && plane.position.y <= -6.4)
                {
                    //cout<<"Fuel";
                    fuel.erase(fuel.begin());
                    fuel_dash.len+=0.5;
                    score+=10;
                    if(fuel_dash.len>2.0)
                        fuel_dash.len=2.0;
                }
        }
    }
    if(!forward)
    {
        float a=plane.position.z+(cos(plane.rotation * M_PI / 180.0f)*0.05);
        float b=plane.position.x+(sin(plane.rotation * M_PI / 180.0f)*0.05);
        if(a*a+b*b<90*90)
        {
            plane.position.z+=(cos(plane.rotation * M_PI / 180.0f)*0.05);
            plane.position.x+=(sin(plane.rotation * M_PI / 180.0f)*0.05);
            for(int i=0;i<number_of_volcanos;i++)
            {
                if( plane.position.x > volcanos[i].position.x-3.5 && plane.position.x < volcanos[i].position.x+3.5 && plane.position.z > volcanos[i].position.z-3.5 && plane.position.z < volcanos[i].position.z+3.5 )
                    quit(window);        
            }
            speed_dash.len=0.8;
            fuel_dash.len-=0.0002;
        }
    }
}

void tick_elements() {
    for(int i=0;i<canon_ball.size();i++)
    {
        canon_ball[i].tick();
        if( sqrt( (canon_ball[i].position.x - plane.position.x)*(canon_ball[i].position.x - plane.position.x) + (canon_ball[i].position.y - plane.position.y)*(canon_ball[i].position.y - plane.position.y) + (canon_ball[i].position.z - plane.position.z)*(canon_ball[i].position.z - plane.position.z) ) <= 0.81)
        {
            health_count-=20;
            canon_ball.erase(canon_ball.begin()+i);
        }
    }
    for(int i=0;i<bomb.size();i++)
    {
        bomb[i].position.y-=bomb[i].speed;
        if(bomb[i].position.y<-9.0)
            bomb.erase(bomb.begin()+i);
        if(bomb[i].position.y < -7.8)
        {
            if(checkpoint_one_conquered)
            {
                if(bomb[i].position.x>=-42 && bomb[i].position.x<=-38 && bomb[i].position.z>=-42 && bomb[i].position.z<=-38)
                {
                    bomb.erase(bomb.begin()+i);
                    checkpoint.erase(checkpoint.begin());
                    checkpoint_two_conquered=true;
                    canon.erase(canon.begin());
                }
            }
            else
            {
                if(bomb[i].position.x<=42 && bomb[i].position.x>=38 && bomb[i].position.z<=42 && bomb[i].position.z>=38)
                {
                    bomb.erase(bomb.begin()+i);
                    checkpoint.erase(checkpoint.begin());
                    canon.erase(canon.begin());
                    checkpoint_one_conquered=true;
                }
            }
        }
    }
    for(int i=0;i<missile.size();i++)
    {
        missile[i].position.z+=(cos(missile[i].rotation_angle * M_PI / 180.0f)*0.1*cos(missile[i].updown_angle * M_PI / 180.0f))*17;
        missile[i].position.x+=(sin(missile[i].rotation_angle * M_PI / 180.0f)*0.1)*17;
        missile[i].position.y+=(sin(missile[i].updown_angle * M_PI / 180.0f * -1)*0.1)*17;
        if(missile[i].position.z>59.0 || missile[i].position.x>59.0)
            missile.erase(missile.begin()+i);
        for(int j=0;j<chute.size();j++)
        {
            if(missile[i].position.x-chute[j].position.x > -0.3 && missile[i].position.x-chute[j].position.x < 0.3 && missile[i].position.z-chute[j].position.z > -0.3 && missile[i].position.z-chute[j].position.z < 0.3)
            {
                if(missile[i].position.y<=chute[j].position.y+chute[j].radius_top && missile[i].position.y>=chute[j].position.y-4.0f)
                {
                    chute.erase(chute.begin()+j);
                    missile.erase(missile.begin()+i);
                    score+=100;
                }
            }                
        }
    }

    for(int i=0;i<number_of_health;i++)
    {
        if(health[i].position.x-plane.position.x > -1.3 && health[i].position.x-plane.position.x < 1.3 && health[i].position.z-plane.position.z > -1.3 && health[i].position.z-plane.position.z < 1.3 && health[i].position.y-plane.position.y > -1.3 && health[i].position.y-plane.position.y < 1.3)
        {
            health.erase(health.begin()+i);
            health_count+=20;
            score+=10;
            if(health_count>100)
                health_count=100;
        }   
    }
    for(int i=0;i<number_of_coins;i++)
    {
        if(coins[i].position.x-plane.position.x > -1.3 && coins[i].position.x-plane.position.x < 1.3 && coins[i].position.z-plane.position.z > -1.3 && coins[i].position.z-plane.position.z < 1.3 && coins[i].position.y-plane.position.y > -1.3 && coins[i].position.y-plane.position.y < 1.3)
        {
            coins.erase(coins.begin()+i);
            score+=100;
        }   
    }
    aeoplane_compass.position.x=3.0-(plane.position.x*0.6/90);
    aeoplane_compass.position.y=3.0+(plane.position.z*0.6/90);
    
   
    if(ring.size() > 0 && plane.position.x > ring[0].position.x-0.5 && plane.position.x < ring[0].position.x+0.5 && plane.position.y > ring[0].position.y-0.5 && plane.position.y < ring[0].position.y+0.5 && plane.position.z > ring[0].position.z-1)
    {
        score+=100;
        ring.erase(ring.begin());
    }
    for(int i=0;i<canon_ball.size();i++)
    {
        if(canon_ball[i].position.y>=12)
            canon_ball.erase(canon_ball.begin()+i);
    }
}

void initGL(GLFWwindow *window, int width, int height) {
    plane       = Plane(0, 0 , 0, COLOR_WHITE);
    ocean       = Ocean(0, -8 , 0);
    speed_dash       = Dashboard(0, 0 , 0, COLOR_WHITE);
    fuel_dash       = Dashboard(0, 0 , 0, COLOR_RED);
    altitude_dash       = Dashboard(0, 0 , 0, COLOR_WHITE);
    altitude_dash       = Dashboard(0, 0 , 0, COLOR_GREEN);
    main_compass_border =  Compass(3.0,3.0,0.0,COLOR_WHITE,0.65,0);
    main_compass =  Compass(3.0,3.0,0.0,COLOR_BLACK,0.6,0);
    aeoplane_compass =  Compass(3.0-(plane.position.x*0.6/90),3.0+(plane.position.z*0.6/90),0.0,COLOR_WHITE,0.05,1);
    
    Checkpoint c;
        c = Checkpoint(40,-8,40);
        checkpoint.push_back(c);
        c= Checkpoint(-40,-8,-40);
        checkpoint.push_back(c);
    Canon cc;
        cc = Canon(checkpoint[0].position.x,checkpoint[0].position.y,checkpoint[0].position.z);
        canon.push_back(cc);
        cc= Canon(checkpoint[1].position.x,checkpoint[1].position.y,checkpoint[1].position.z);
        canon.push_back(cc);
    checkpoint1 = Compass(3.0-(checkpoint[0].position.x*0.6/90),3.0+(checkpoint[0].position.z*0.6/90),0.0,COLOR_ISLAND,0.02,0);
    checkpoint2 = Compass(3.0-(checkpoint[1].position.x*0.6/90),3.0+(checkpoint[1].position.z*0.6/90),0.0,COLOR_ISLAND,0.02,0);
    fuel_dash.len=2.0;
    arrow = Arrow(checkpoint[0].position.x,3,checkpoint[0].position.z);
    for(int i=0;i<10;i++)
    {
        Boat b;
        int x=rand()%70,z=rand()%70;
        if(x<5 || x==-30)
            x=((i+1)*4)%70;
        if(z==0 || z==-30)
            z=-((i+1)*4)%70;
        if(rand()%2==0)
        {
            x*=-1;
            z*=-1;
        }
        if(rand()%3==0)
        {
            x*=-1;
        }
        if(rand()%5==0)
        {
            z*=-1;
        }
        b  = Boat(x, -8 , z);
        boat.push_back(b);

        Compass c;
        c = Compass(3.0-(boat[i].position.x*0.6/90),3.0+(boat[i].position.z*0.6/90),0.0,COLOR_CANON,0.01,0);
        boat_compass.push_back(c);
    }
    for(int i=0;i<number_of_volcanos;i++)
    {
        Volcano v;
        int x=rand()%70,z=rand()%70;
        if(x<5 || x==-30)
            x=((i+1)*4)%70;
        if(z==0 || z==-30)
            z=-((i+1)*4)%70;
        if(rand()%2==0)
        {
            x*=-1;
            z*=-1;
        }
        if(rand()%3==0)
        {
            x*=-1;
        }
        if(rand()%5==0)
        {
            z*=-1;
        }
        v = Volcano(x, -8 , z);
        volcanos.push_back(v);
        
        Compass c;
        c = Compass(3.0-(volcanos[i].position.x*0.6/90),3.0+(volcanos[i].position.z*0.6/90),0.0,COLOR_ORANGE,0.01,0);
        volcano_compass.push_back(c);    
    }
    for(int i=0;i<(rand()%20+9);i++)
    {
        Parachute p;
        int x=rand()%70,z=rand()%70,y=rand()%15+2;
        if(x<5 || x==-30)
            x=((i+1)*4)%70;
        if(z==0 || z==-30)
            z=-((i+1)*4)%70;
        if(rand()%2==0)
        {
            x*=-1;
            z*=-1;
        }
        if(rand()%3==0)
        {
            x*=-1;
        }
        if(rand()%5==0)
        {
            z*=-1;
        }
        p = Parachute(x,y,z);
        chute.push_back(p);
    }
    for(int i=0;i<number_of_health;i++)
    {
        Health h;
        int x=rand()%70,z=rand()%70,y=-(rand()%6);
        if(x<5 || x==-30)
            x=((i+1)*4)%70;
        if(z==0 || z==-30)
            z=-((i+1)*4)%70;
        if(rand()%2==0)
        {
            x*=-1;
            z*=-1;
        }
        if(rand()%3==0)
        {
            x*=-1;
        }
        if(rand()%5==0)
        {
            z*=-1;
        }
        h = Health(x,y,z);
        health.push_back(h);
        
        Compass c;
        c = Compass(3.0-(health[i].position.x*0.6/90),3.0+(health[i].position.z*0.6/90),0.0,COLOR_GREEN,0.01,0);
        health_compass.push_back(c);
    }
    for(int i=0;i<number_of_coins;i++)
    {
        Coins h;
        int x=rand()%70,z=rand()%70,y=-(rand()%6);
        if(x<5 || x==-30)
            x=((i+1)*4)%70;
        if(z==0 || z==-30)
            z=-((i+1)*4)%70;
        if(rand()%2==0)
        {
            x*=-1;
            z*=-1;
        }
        if(rand()%3==0)
        {
            x*=-1;
        }
        if(rand()%5==0)
        {
            z*=-1;
        }
        h = Coins(x,y,z);
        coins.push_back(h);
        
        Compass c;
        c = Compass(3.0-(coins[i].position.x*0.6/90),3.0+(coins[i].position.z*0.6/90),0.0,COLOR_COINS,0.01,0);
        coins_compass.push_back(c);
    }
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 1800;
    int height = 1000;
    char title[1000];
    checkpoint_one_conquered = false;
    checkpoint_two_conquered = false;
    window = initGLFW(width, height);
    number_of_health=rand()%5+10;
    number_of_coins=rand()%10+10;
    plane.rotate_tilt = glm::rotate((float) (plane.tilt * M_PI / 180.0f), glm::vec3(0, 0, 1));
    plane.rotate_rotation = glm::rotate((float) (plane.rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));   
    plane.rotate_updown = glm::rotate((float) (plane.updown * M_PI / 180.0f), glm::vec3(1, 0, 0));   
    number_of_volcanos=rand()%10+10;
    initGL (window, width, height);
    bomb_launch=0;
    missile_launch=0;
    long long count=0;

    while (!glfwWindowShouldClose(window) &&health_count>0 && fuel_dash.len>0  &&!checkpoint_two_conquered) {
        if (t60.processTick()) 
        {
            if(count%60==0)
                score++;
            if(checkpoint_one_conquered && !checkpoint_two_conquered && ((plane.position.x-checkpoint[1].position.x)*(plane.position.x-checkpoint[1].position.x) + (plane.position.z-checkpoint[1].position.z)*(plane.position.z-checkpoint[1].position.z)>=70*70))
            {
                arrow.position.x=0.0;
                arrow.position.y=3.0;
                arrow.position.z=0.0;
            }
            else if(checkpoint_one_conquered && !checkpoint_two_conquered)
            {
                arrow.position.x=checkpoint[1].position.x;
                arrow.position.z=checkpoint[1].position.z;
            }

            count++;
            health_dash.len=(health_count/100.0)*2.0;
            if(count%50==1)
            {
                if(!checkpoint_one_conquered)
                {
                    if( (plane.position.x-checkpoint[0].position.x)*(plane.position.x-checkpoint[0].position.x)   +    (plane.position.z-checkpoint[0].position.z)*(plane.position.z-checkpoint[0].position.z) <=500)
                    {
                        Canon_ball c;
                        c = Canon_ball(checkpoint[0].position.x,checkpoint[0].position.y,checkpoint[0].position.z,plane.position.x,plane.position.y,plane.position.z);
                        canon_ball.push_back(c);
                    }
                }
                else if(!checkpoint_two_conquered)
                {
                    if( (plane.position.x-checkpoint[1].position.x)*(plane.position.x-checkpoint[1].position.x)   +    (plane.position.z-checkpoint[1].position.z)*(plane.position.z-checkpoint[1].position.z) <=500)
                    {

                        Canon_ball c;
                        c = Canon_ball(checkpoint[1].position.x,checkpoint[1].position.y,checkpoint[1].position.z,plane.position.x,plane.position.y,plane.position.z);
                        canon_ball.push_back(c);
                    }
                }
            }
            if(count % 800 == 1)
            {
                Ring r;
                r = Ring(plane.position.x+rand()%20,plane.position.y+rand()%20,plane.position.z+rand()%20+20);
                if(ring.size()>0)
                    ring.erase(ring.begin());
                ring.push_back(r);
            }
            if(count % 800 == 50)
            {
                Fuel f;
                f = Fuel(plane.position.x + rand()%5, -8.1 , plane.position.z + rand()%10);
                fuel.push_back(f);
            }
            if(count % 2000 == 950 && fuel.size()>0)
                fuel.erase(fuel.begin());
            draw();
            glfwSwapBuffers(window);
            sprintf(title,"Score %d",score);
            glfwSetWindowTitle(window,title);
            tick_elements();
            tick_input(window);
        }

        glfwPollEvents();
    }
    cout<<"\n\n\n\n\n\n\t\t\t\tGame Over\n\n\t\t\t\tYour score is: "<<score<<"\n\n\n\t\t\t      Thanks for playing. :)\n\n\n\n\n\n\n\n \n\n\n";
    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    Matrices.projection = glm::perspective(glm::radians(45.0f),3.0f/4.0f,0.1f,100.0f);
}
