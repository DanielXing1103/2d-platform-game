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
    }

    void handleMouseClick(int button, int state, int x, int y) {
        // Implementation of handleMouseClick method
    }

    bool isGameStarted() const {
        return gameStarted;
    }

private:
    bool startButtonClicked(int x, int y) {
        // Implementation of startButtonClicked method
    }

    void drawStartButton() {
        // Implementation of drawStartButton method
    }

    void startGame() {
        // Implementation of startGame method
    }

    bool gameStarted;
};

#endif
