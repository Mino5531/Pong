#include "GraphicsHelper.h"
#include <GLFW/glfw3.h>
#include <gl/GL.h>

void GraphicsHelper::DrawRect(float x, float y, int width, int height)
{
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void GraphicsHelper::DrawNumber(int x, int y, int num)
{
	switch (num) {
    case 0:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x, y + 5, 5, 20);
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x, y + 30, 5, 20);
        DrawRect(x + 25, y + 30, 5, 20);
        DrawRect(x + 5, y + 50, 20, 5);
        break;

    case 1:
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x + 25, y + 30, 5, 20);
        break;
    case 2:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x + 5, y + 25, 20, 5);
        DrawRect(x, y + 30, 5, 20);
        DrawRect(x + 5, y + 50, 20, 5);
        break;
    case 3:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x + 5, y + 25, 20, 5);
        DrawRect(x + 25, y + 30, 5, 20);
        DrawRect(x + 5, y + 50, 20, 5);
        break;
    case 4:
        DrawRect(x, y + 5, 5, 20);
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x + 5, y + 25, 20, 5);
        DrawRect(x + 25, y + 30, 5, 20);
        break;
    case 5:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x, y + 5, 5, 20);
        DrawRect(x + 5, y + 25, 20, 5);
        DrawRect(x + 25, y + 30, 5, 20);
        DrawRect(x + 5, y + 50, 20, 5);
        break;
    case 6:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x, y + 5, 5, 20);
        DrawRect(x + 5, y + 25, 20, 5);
        DrawRect(x, y + 30, 5, 20);
        DrawRect(x + 25, y + 30, 5, 20);
        DrawRect(x + 5, y + 50, 20, 5);
        break;
    case 7:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x, y + 5, 5, 20);
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x + 25, y + 30, 5, 20);
        break;
    case 8:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x, y + 5, 5, 20);
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x + 5, y + 25, 20, 5);
        DrawRect(x, y + 30, 5, 20);
        DrawRect(x + 25, y + 30, 5, 20);
        DrawRect(x + 5, y + 50, 20, 5);
        break;
    case 9:
        DrawRect(x + 5, y, 20, 5);
        DrawRect(x, y + 5, 5, 20);
        DrawRect(x + 25, y + 5, 5, 20);
        DrawRect(x + 5, y + 25, 20, 5);
        DrawRect(x + 25, y + 30, 5, 20);
        DrawRect(x + 5, y + 50, 20, 5);
        break;

	}
}
