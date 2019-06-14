<h1 align="center">Jet Fighter Game in OpenGL</h1>

#### Author - Himanshu Maheshwari

The given game is a 3D emulation of a jet fighter plane game(Link: https://youtu.be/Am5t_dHqC9I). The game has been wiritten in c++ and openGL. Open Graphics Library(OpenGL) is a cross-language, cross-platform application programming interface for rendering 2D and 3D vector graphics.

#### How to run?
(Showing it for Linux, similar commands could be used for other platforms)
* First install OpenGL.
        
        1) For Fedora use - `sudo pkgconf-pkg-config dnf install glew-devel glfw-devel glm-devel cmake pkgconf`
        2) For Ubuntu use - `sudo apt install libglew-dev libglfw3-dev libglm-dev cmake pkg-config`
* Then git clone the given repo.
* Make directory `build` and cd into it.
* After that run `cmake ..`
* After that run `make`
* All the pre processing is done. Now to run the game use command `./graphics_asgn1`


#### Gameplay
| KEY | ACTION|
|-----|-------|
|W|Increase Speed|
|Space Bar|Increase Altitude|
|S|Decrease Altitude|
|Left Mouse Button|Fire Missile|
|Right Mouse Button|Drop a Bomb|
|A/D|Tilt the plane(Yaw)|
|Left and Right arrow keys|Rotate the plane (Roll)|
|Up and Down arrow key|Rotate the plane up and down(Pitch)|
|Scroll Up|Zoom in|
|Scroll Down|Zoom out|

#### Features
- The game could be played from multiple views(as mentioned in the specifications).
- The plane can launch missiles and bombs which could be used to destroy parachutes and
checkpoints.
- The plane has a dashboard which shows altitude(white),fuel(red), speed(black) and health(green).
Also the dashboard has a compass attached with it.
- On the way there are fuels that could be used to refill the plane's tank, coins to earn score and
health ups to increase health.
- The game has volcanos at random position, flying over which will lead to game over.
- The game gets over when - plane is near a volcano(or above it), the fuel is over, the health
becomes zero or you have achieved all the checkpoints.
- There are parachutes at random location, hitting them with missiles will earn you extra points.
- There are rings of smoke at random position, passing the plane through it will earn extra points.
- The game also has boats at random location.
- The checkpoints fires canon when plane goes near it.
- There is a red arrow just above the checkpoint and will guide you to the checkpoint.
- There is a finite play area and plane cannot go outside it.
- There is a cross, that will direct the missiles.
- The shapes on compass represents the following:

        1) Arrow - Plane
        2) Large bright green dots - Checkpoints
        3) Orange dots - Volcanos
        4) Green dots - Power ups
        5) Yellow dots - Coins
        6) Dark Green - Boats

#### Screenshots
<img src="Screen Shots/1.png" alt="1"></img>
<img src="Screen Shots/2.png" alt="2"></img>
<img src="Screen Shots/3.png" alt="3"></img>
<img src="Screen Shots/4.png" alt="4"></img>
<img src="Screen Shots/5.png" alt="5"></img>
<img src="Screen Shots/6.png" alt="6"></img>
<img src="Screen Shots/7.png" alt="7"></img>

#### Cheers!!!
