#include <GL/freeglut.h>
#include <iostream>
#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Land.h"
#include "Platform.h"
#include "Menu.h"
#include "Time.h"

#define FPS 60
bool collision; // Used for jumping when we land on the ground or floating platform
float gravity = -0.006;
player myPlayer(0, -2, 1, 1, 0, 0, gravity); // Player
land ground(0, -10, 20, 10);

bool inMenu = true; // Initially, the game starts with the menu
Menu mainMenu; // Menu instance

Timer gameTimer;

std::vector<platform> platforms; // Vector to store platforms



void createPlatform() {
    float yPosition = static_cast<float>(rand() % 3 - 5); // Random y-position between -5 and 0
    platform newPlatform(8, yPosition, 4, 1, -0.1);

    if (!platforms.empty() && newPlatform.xpos - platforms.back().xpos < 10) {
        newPlatform.xpos = platforms.back().xpos + 10;
    }

    platforms.push_back(newPlatform);
}

void deleteOffscreenPlatforms() {
    platforms.erase(std::remove_if(platforms.begin(), platforms.end(),
        [](const platform& p) { return p.xpos < -10; }), platforms.end());
}

void playgame() {
    if (!myPlayer.gameover) {
        myPlayer.draw();
        ground.draw();

        createPlatform();
        deleteOffscreenPlatforms();

        for (auto& platform : platforms) {
            platform.draw();
            platform.move();
        }

        collision = false;

        if (myPlayer.checkCollision(ground).collision) {
            collision = true;
            myPlayer.acc = myPlayer.yspeed = 0;
        }

        for (auto& platform : platforms) {
            if (myPlayer.checkCollision(platform).collision) {
                collision = true;
                if (myPlayer.checkCollision(platform).position == 1) {
                    std::cout << "positon 1" << std::endl;
                    myPlayer.acc = myPlayer.yspeed = 0;
                }
                else if (myPlayer.checkCollision(platform).position == 0) {
                    std::cout << "positon 0" << std::endl;
                    myPlayer.yspeed = 0;
                    myPlayer.acc = gravity;
                }
            }
        }

        if (!collision) myPlayer.acc = gravity;
        myPlayer.move();
    }
}

void init() {
    glClearColor(0.2, 0.5, 0.0, 1.0); // Set background color
}

void display_call_back() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (inMenu) {
        mainMenu.display();
    }
    else {
        playgame();
        gameTimer.displayTime();
    }

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

void keyboard_func(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        if (collision) {
            myPlayer.ypos += 0.1;
            myPlayer.yspeed = -0.6 * FPS * gravity;
        }
        break;
    case ' ':
        if (inMenu) {
            inMenu = false;
            gameTimer.start(); // Start the timer when leaving the menu
        }
        break;
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