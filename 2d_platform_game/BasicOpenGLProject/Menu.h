#ifndef MENU_H
#define MENU_H

#include <GL/glut.h>

class Menu {
public:
    Menu() {
        gameStarted = false; // Constructor implementation
    }

    void display() {
        // Implementation of display method
        glBegin(GL_QUADS);
        glColor3f(0.1, 0.0, 0); // black color for land
        glVertex2f((10 - 5 / 2.0f) / 10, (10 - 5 / 2.0f) / 10);
        glVertex2f((10 + 5 / 2.0f) / 10, (10 - 5 / 2.0f) / 10);
        glVertex2f((10 + 5 / 2.0f) / 10, (10 + 5 / 2.0f) / 10);
        glVertex2f((10 - 5 / 2.0f) / 10, (10 + 5 / 2.0f) / 10);


        glEnd();

    }

    void handleMouseClick(int button, int state, int x, int y) {
        // Implementation of handleMouseClick method
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (startButtonClicked(x, y)) {
                startGame();
            }
        }
    }

    bool isGameStarted() const {
        return gameStarted;
    }

private:
    bool startButtonClicked(int x, int y) {
        // Implementation of startButtonClicked method
        return (x >= 50 && x <= 150) && (y >= 50 && y <= 100);
    }

    void drawStartButton() {
        // Implementation of drawStartButton method
        glColor3f(1.0, 0.0, 0.0); // Set button color
        glRectf(50.0, 50.0, 150.0, 100.0); // Draw button as a rectangle

        // Draw start text on the button
        const char* text = "Start";
        glRasterPos2i(75, 75);
        while (*text) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text);
            text++;
        }
    }

    void startGame() {
        // Implementation of startGame method
    }

    bool gameStarted;
};

#endif
