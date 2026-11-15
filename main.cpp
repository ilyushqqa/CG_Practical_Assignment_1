#include <GL/freeglut.h>
#include "shapes.h"
#include "transformations.h"
#include "control.h"

void reshape(int width, int height){
    if (height == 0)
        height = 1;
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-width / 2.0, width / 2.0, -height/ 2.0, height / 2.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display(){
    glClearColor(0.0f,0.0f,0.0f, 0.8f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    int selected = getSelectedObj();

    //gear
    const Object2D& gear = getObject(0);

    glPushMatrix();
    //Transformations
    glTranslatef(gear.x, gear.y, 0.0f);
    glRotatef(gear.angle, 0.0f, 0.0f, 1.0f);
    glScalef(gear.scaleX, gear.scaleY, 1.0f);
    glLineWidth(selected == 0 ? 3.0f : 1.5f);
    drawGear();
    glPopMatrix();

    //star
    const Object2D& star = getObject(1);

    glPushMatrix();
    //Transformations
    glTranslatef(star.x, star.y, 0.0f);
    glRotatef(star.angle, 0.0f, 0.0f, 1.0f);
    glScalef(star.scaleX, star.scaleY, 1.0f);
    glLineWidth(selected == 1 ? 3.0f : 1.5f);
    drawStar();
    glPopMatrix();

    glLineWidth(1.0f);

    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Computer Graphics - Practical 1");

    //render
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    //mouse and keyboard
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(controlKeys);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutMainLoop();

    return 0;
}