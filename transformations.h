#pragma once

int getSelectedObj();

struct Object2D
{
    float x;
    float y;
    float angle;
    float scaleX;
    float scaleY;
};

// object's state
const Object2D& getObject(int index);
void selectObject(int index);
void moveObject(float dx, float dy);
void rotateObject(float degrees);
void scaleObject(float factor);
void mirrorX();
void mirrorY();
