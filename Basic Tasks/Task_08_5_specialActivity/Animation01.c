#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define width 40
#define height 12
int random(int a, int b);
void update(); 
void draw();
int x, y, dx, dy;

int main() {
    srand(time(NULL));
    x = random(0, width + 1); //set init x
    y = random(0, height + 1); //set init y
    dx = random(-3, 3); //set init dx
    dy = sqrt(8 - dx*dx) * (random(0, 2) == 0 ? -1 : 1); //get init dy from init dx
    while (1) {
        system("cls");
        update();
        draw();
        Sleep(17);
    }
}

int random(int a, int b) {
    return rand() % (b - a) + a;
}

void update() {
    if (x + dx >= width) { //update x position
        x = width * 2 - x - dx;
        dx = -dx;
    }
    else if (x + dx <= 0) {
        x = -(x + dx);
        dx = -dx;
    }
    else {
        x = x + dx;
    }

    if (y + dy >= height) { //update y position
        y = height * 2 - y - dy;
        dy = -dy;
    }
    else if (y + dy <= 0) {
        y = -(y + dy);
        dy = -dy;
    }
    else {
        y = y + dy;
    }
}

void draw() { //render animation
    int i, j;
    for (i = 0; i <= height; i++) {
        for (j = 0; j <= width; j++) {
            if (x == j && y == i) {
                printf("O");
            }
            else {
                printf("_");
            }
        }
        printf("\n");
    }
}