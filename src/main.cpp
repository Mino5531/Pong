#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <iostream>
#include <Windows.h>

#include "graphicsHelper.h"
#include "Racket.h"
#include "Ball.h"

const int width = 600, height = 400;
bool keys[349];
Racket rightRacket(width - 20);
Racket leftRacket(10);
Ball ball(&rightRacket,&leftRacket);

void OnKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_UNKNOWN) {
        return;
    }
    if (action == GLFW_PRESS) {
        keys[key] = true;
    }
    if (action == GLFW_RELEASE) {
        keys[key] = false;
    }
}

void HandleKeys() {
    if (keys[GLFW_KEY_UP]) {
        rightRacket.MoveUp();
    }
    if (keys[GLFW_KEY_DOWN]) {
        rightRacket.MoveDown();
    }
    if (keys[GLFW_KEY_W]) {
        leftRacket.MoveUp();
    }
    if (keys[GLFW_KEY_S]) {
        leftRacket.MoveDown();
    }
}

void Reset() {
    rightRacket.Reset();
    leftRacket.Reset();
    ball.Reset(2);
}

int main(void)
{
    /* Hide the CMD window */
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(width, height, "Pong", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, OnKeyPress);

    /*Mainloop*/
    while (!glfwWindowShouldClose(window))
    {

        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        glOrtho(0, width, height, 0, 0, 1);

        glDisable(GL_DEPTH_TEST);

        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

        glClearColor(0.0f, 0.0f, 0.0f, 0);

        glClear(GL_COLOR_BUFFER_BIT);
        HandleKeys();
        Ball::CollisionSide col = ball.Move();
        if (col == Ball::CollisionSide::Left) {
            rightRacket.score++;
            if (rightRacket.score == 10) {
                Reset();
            }
            ball.Reset(-2);
        }
        if (col == Ball::CollisionSide::Right) {
            leftRacket.score++;
            if (leftRacket.score == 10) {
                Reset();
            }
            ball.Reset(2);
        }
        //Ball
        ball.Draw();

        //Rackets
        leftRacket.Draw();
        rightRacket.Draw();
        
        //Scores
        GraphicsHelper::DrawNumber(width / 2 - 40, 10, leftRacket.score);
        GraphicsHelper::DrawNumber(width / 2 + 10, 10, rightRacket.score);

        GraphicsHelper::DrawRect(width / 2 - 2, 25, 5, 5);
        GraphicsHelper::DrawRect(width / 2 - 2, 45, 5, 5);

        glfwSwapBuffers(window);
        glfwSwapInterval(1);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}