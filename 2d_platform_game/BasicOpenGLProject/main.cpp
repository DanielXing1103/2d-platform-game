#include <GL/freeglut.h>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Land.h"
#include "Platform.h"
#define FPS 60
bool collision; // Used for jumping when we land on the ground or floating platform
float gravity = -0.006;
platform p1(20, -3.5, 4, 1, -0.1);
player myPlayer(0, -2, 1, 1, 0, 0, gravity); // Player
land ground(0, -10, 20, 10);

void playgame() {
    if (!myPlayer.gameover) {//gameover logic are in player
        myPlayer.draw();//player render
        ground.draw();//ground render
        p1.draw();//platfrom render

        collision = false;//assume we didnt collide

        if (myPlayer.checkCollision(ground).collision) {     //player collsion with land 
            collision = true;
            myPlayer.acc = myPlayer.yspeed = 0;
        }

        //for loop


        if (myPlayer.checkCollision(p1).collision) {
            collision = true;
            if (myPlayer.checkCollision(p1).position == 1) {
                std::cout << "positon 1" << std::endl;
                myPlayer.acc = myPlayer.yspeed = 0;
            }
            else if (myPlayer.checkCollision(p1).position == 0) {
                std::cout << "positon 0" << std::endl;
                myPlayer.yspeed = 0;
                myPlayer.acc = gravity;
            }
            //break;
        }

        std::cout << "collision" << collision << std::endl;
        if (!collision) myPlayer.acc = gravity;//resume when we are at air
        std::cout << myPlayer.acc << std::endl;
        myPlayer.move();
        p1.move();
    }


}

void init() {
    glClearColor(0.2, 0.5, 0.0, 1.0); // Set background color
}



void display_call_back() {
    glClear(GL_COLOR_BUFFER_BIT);

    playgame();

    glutSwapBuffers();
}

void reshape_call_back(int w, int h) {
    glViewport(0, 0, w, h);
    glutPostRedisplay();
}

void timer_call_back(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timer_call_back, 0);

}
void keyboard_func(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    {
        if (collision) {

            myPlayer.ypos += 0.1;
            myPlayer.yspeed = -0.6 * FPS * gravity;

        }
    }
    }

    glutPostRedisplay();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("2D Platform game");
    glutDisplayFunc(display_call_back);
    glutReshapeFunc(reshape_call_back);
    glutKeyboardFunc(keyboard_func);

    glutTimerFunc(0, timer_call_back, 0);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
