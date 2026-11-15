
#include "transformations.h"

namespace
{
    Object2D objects[2] = {
        { -240.0f, 0.0f, 0.0f, 1.0f, 1.0f }, // Gear
        { 240.0f, 0.0f, 0.0f, 1.0f, 1.0f }  // Star
    };

    int selectedObject = 0;
}

const Object2D& getObject(int index){
    return objects[index];
}

void selectObject(int index){
    if (index >= 0 && index < 2)
        selectedObject = index;
}

int getSelectedObj() {
    return selectedObject;
}

void moveObject(float dx, float dy) {
    objects[selectedObject].x += dx;
    objects[selectedObject].y += dy;
}

void rotateObject(float degrees) {
        objects[selectedObject].angle += degrees;
}

void scaleObject(float factor) {
    objects[selectedObject].scaleX *= factor;
    objects[selectedObject].scaleY *= factor;
}

void mirrorX() {
    objects[selectedObject].scaleY *= -1.0f;
}
void mirrorY() {
    objects[selectedObject].scaleX *= -1.0f;
}