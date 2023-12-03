#pragma once
#ifndef TIME_H
#define TIME_H

#include <GL/freeglut.h>
#include <chrono>
#include <iostream>
#include <string>
class Timer {
private:
    std::chrono::time_point<std::chrono::steady_clock> start_time;
    bool running;

public:
    Timer() : running(false) {}

    void start() {
        start_time = std::chrono::steady_clock::now();
        running = true;
    }

    double getElapsedTime() {
        if (running) {
            auto current_time = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed = current_time - start_time;
            return elapsed.count();
        }
        return 0.0;
    }

    void displayTime() {
        double elapsed_time = getElapsedTime();
        std::string time_str = "Time: " + std::to_string((int)elapsed_time) + " sec";

        // Set position for text (top of the screen)
        glRasterPos2f(0.6f, 0.8f); // Adjust as necessary
        glColor3f(2, 0.0, 0); // Color for text
        // Display each character of the string
        for (char c : time_str) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
    }
};

#endif // TIME_H
