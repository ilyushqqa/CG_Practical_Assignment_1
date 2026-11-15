#include "shapes.h"
#include <GL/freeglut.h>
#include <cmath>
#include <string>

constexpr float PI = 3.14159265f;


float bezier(float p0, float p1, float p2, float p3, float t){
    float u = 1.0f - t;

    return u * u * u * p0
        + 3 * u * u * t * p1
        + 3 * u * t * t * p2
        + t * t * t * p3;
}
void getPoint(float radius, float angle, float& x, float& y){
    x = radius * cos(angle);
    y = radius * sin(angle);
}

void drawVLabels(const float vertices[][2], int vertexCount)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    // Loop for labels
    for (int i = 0; i < vertexCount; i++)
    {
        std::string label = "A" + std::to_string(i + 1);

        glRasterPos2f(vertices[i][0] + 8.0f, vertices[i][1] + 8.0f);

        glutBitmapString(
            GLUT_BITMAP_HELVETICA_12,
            reinterpret_cast<const unsigned char*>(label.c_str())
        );
    }
}

void drawBezierSegment(float x0, float y0, float x3, float y3, float curvature){
    // Difference between two vertices
    float dx = x3 - x0;
    float dy = y3 - y0;

    float length = sqrt(dx * dx + dy * dy);

    float nx = dy / length;
    float ny = -dx / length;

    float x1 = x0 + dx / 3.0f + nx * curvature;
    float y1 = y0 + dy / 3.0f + ny * curvature;

    float x2 = x0 + 2.0f * dx / 3.0f + nx * curvature;
    float y2 = y0 + 2.0f * dy / 3.0f + ny * curvature;

    //Curve points
    for (int i = 0; i <= 10; i++)
    {
        float t = i / 10.0f;

        glVertex2f(
            bezier(x0, x1, x2, x3, t),
            bezier(y0, y1, y2, y3, t)
        );
    }
}
void drawGear(){
    const int GearTeeth = 8;
    const int vertexCount = GearTeeth * 4;

    const float GearInnerRadius = 75;
    const float GearOuterRadius = 100;

    float vertices[vertexCount][2];


    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < vertexCount; i++)
    {
        int next = (i + 1) % vertexCount;

        float angle1 = 2.0f * PI * i / vertexCount;
        float angle2 = 2.0f * PI * next / vertexCount;

        float radius1 = (i % 4 == 1 || i % 4 == 2)
            ? GearOuterRadius : GearInnerRadius;

        float radius2 = (next % 4 == 1 || next % 4 == 2)
            ? GearOuterRadius : GearInnerRadius;

        float x1, y1, x2, y2;

        getPoint(radius1, angle1, x1, y1);
        getPoint(radius2, angle2, x2, y2);

        vertices[i][0] = x1;
        vertices[i][1] = y1;

        drawBezierSegment(x1, y1, x2, y2, 2.0f);
    }

    glEnd();
    drawVLabels(vertices, vertexCount);

}
void drawStar(){
    const int points = 5;
    const int vertexCount = points * 2;

    const float outerRadius = 100.0f;
    const float innerRadius = 45.0f;

    float vertices[vertexCount][2];

    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_LINE_LOOP);

    for (int i = 0; i < points * 2; i++)
    {
        int next = (i + 1) % (points * 2);

        float angle1 = -PI / 2.0f + PI * i / points;
        float angle2 = -PI / 2.0f + PI * next / points;

        float radius1 = (i % 2 == 0) ? outerRadius : innerRadius;
        float radius2 = (next % 2 == 0) ? outerRadius : innerRadius;

        float x1, y1, x2, y2;
        getPoint(radius1, angle1, x1, y1);
        getPoint(radius2, angle2, x2, y2);

        vertices[i][0] = x1;
        vertices[i][1] = y1;


        drawBezierSegment(x1, y1, x2, y2, 3.0f);
    }
    glEnd();
    drawVLabels(vertices, vertexCount);

}