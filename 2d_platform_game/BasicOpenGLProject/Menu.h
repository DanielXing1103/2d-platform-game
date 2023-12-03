#ifndef MENU_H
#define MENU_H

#include <GL/glut.h>

class Menu {
public:
    Menu() {
        gameStarted = false; // Constructor implementation
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT);

        // Define the height of each zig-zag stripe
        float stripeHeight = 0.1f; // Adjust this value as needed
        bool isBlack = true;

        // Draw zig-zag pattern
        for (float y = 0.5f; y > -0.5f; y -= stripeHeight) {
            glBegin(GL_QUADS);

            if (isBlack) {
                glColor3f(0.0f, 0.0f, 0.0f); // Black color
            }
            else {
                glColor3f(1.0f, 1.0f, 1.0f); // White color
            }

            glVertex2f(-0.5f, y);
            glVertex2f(0.5f, y);
            glVertex2f(0.5f, y - stripeHeight);
            glVertex2f(-0.5f, y - stripeHeight);

            glEnd();

            isBlack = !isBlack; // Alternate color
        }


        // Text to be displayed
        const char* text = "Click Space start\nUse W to Jump";

        // Calculate the length of the text
        float textWidth = 0;
        for (const char* c = text; *c != '\0'; c++) {
            textWidth += glutBitmapWidth(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        }

        // Convert text width to OpenGL coordinates
        textWidth /= glutGet(GLUT_WINDOW_WIDTH);
        textWidth *= 2; // Adjust for OpenGL's -1 to 1 coordinate system

        // Set color for the text
        glColor3f(1, 0.0, 0); // Color for text

        // Positioning the text
        glRasterPos2f(-textWidth / 2, 0); // Center the text

        // Rendering each character of the text
        while (*text) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text);
            text++;
        }

        // Swap the buffers if using double buffering
        glutSwapBuffers();

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


    void startGame() {
        // Implementation of startGame method
    }

    bool gameStarted;
};

#endif