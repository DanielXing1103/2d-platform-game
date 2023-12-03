#pragma once
#ifndef ENDGAME_H
#define ENDGAME_H

#include <GL/freeglut.h>
#include <string>

class EndGame {
public:
    bool isGameOver;

    EndGame() : isGameOver(false) {}

    void displayGameOver() {
        // Set the color for the text (red)
        glColor3f(1.0, 0.0, 0.0);

        // Positioning the text in the middle of the screen
        std::string gameOverText = "GAME OVER PRESS W OR SPACE TO RESTART";
        glRasterPos2f(-0.8f, 0.0f); // Adjust as necessary

        // Display each character of the string
        for (char c : gameOverText) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
    }

    void restartGame() {
        // Reset game state to initial values
        isGameOver = false;
        // Add any other necessary code to reset the game
    }
};

#endif // ENDGAME_H
