#include <GL/freeglut.h>
#include "control.h"
#include "transformations.h"


namespace{
    bool isDragging = false;
    int lastMouseX = 0;
    int lastMouseY = 0;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': selectObject(0) ;break;
    case '2': selectObject(1);break;
    case 'q':rotateObject(10.0f);break;
    case 'e':rotateObject(-10.0f); break;
    case '+':
    case '=':scaleObject(1.1f);break;
    case '-':
    case '_':scaleObject(1.0f / 1.1f);break;
    case 'x':mirrorX();break;
    case 'y':mirrorY();break;
    }

    glutPostRedisplay();
}
void controlKeys(int key, int x, int y){
    const float step = 10.0f;

    switch (key)
    {
    case GLUT_KEY_LEFT: moveObject(-step, 0.0f); break;
    case GLUT_KEY_RIGHT:moveObject(step, 0.0f); break;
    case GLUT_KEY_UP: moveObject(0.0f, step);break;
    case GLUT_KEY_DOWN: moveObject(0.0f, -step);break;
    }

    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y){
    if (button != GLUT_LEFT_BUTTON)
        return;
    if (state == GLUT_UP) {
        isDragging = false;
        return;
    }

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    float worldX = x - width / 2.0f;
    float worldY = height / 2.0 - y;

    const float selectionRadius = 100.0f;

    isDragging = false;

    for (int i = 0; i < 2; i++)
    {
        const Object2D& obj = getObject(i);

        float dx = worldX - obj.x;
        float dy = worldY - obj.y;

        float distanceSquared = dx * dx + dy * dy;

        if (distanceSquared <= selectionRadius * selectionRadius)
        {
            selectObject(i);
            isDragging = true;
            lastMouseX = x;
            lastMouseY = y;
            glutPostRedisplay();
            break;
        }
    }
}
void mouseMotion(int x, int y){
    if (!isDragging)
        return;
    int dx = x - lastMouseX;
    int dy = y - lastMouseY;

    moveObject(static_cast<float>(dx), static_cast<float>(-dy));

    lastMouseX = x;
    lastMouseY = y;

    glutPostRedisplay();
}
