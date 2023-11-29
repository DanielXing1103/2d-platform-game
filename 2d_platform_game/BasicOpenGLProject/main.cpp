#include <GL/freeglut.h>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Land.h"
#define FPS 60
bool landed;//use for jumping when we land on the ground or floating block
float gravity = -0.006;
player myPlayer(0, 0, 1, 1, 0, 0, gravity); // player
land theLand(0, -10, 20, 10);
void playgame() {//game logic 
    myPlayer.draw();
    theLand.draw();
    landed = myPlayer.checkCollision(theLand);
    landed ? myPlayer.acc = myPlayer.yspeed = 0 : myPlayer.acc = gravity;
    std::cout << landed << std::endl;
    myPlayer.move();

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
    glutTimerFunc(1000/FPS, timer_call_back, 0);

}
void keyboard_func(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	{
        if (landed) {
            
            myPlayer.ypos +=0.1;
            myPlayer.yspeed = -0.6*FPS* gravity;
                
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

    glutTimerFunc(0, timer_call_back,0);
    init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
