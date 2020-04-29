#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
void update(int *x, int *y, int num);
void draw(int *x, int *y, int num, char l);
int num, i, j, h;
char k, l;

int main() {
    printf("Number of layers [integer, preferably not higher than 15]:\t"); // input number of layers, with a single motionless dot being 1
    scanf("%d", &num);
    printf("Enter a character:\t"); // input the character you want to use as the dot
    scanf(" %c", &l);
    int x[num], y[num];
    for (i = 0; i < num; i++) {
        x[i] = num;
        y[i] = num - i;
    }
    while (1) { // loop forever
        system("cls");
        draw(x, y, num, l);
        Sleep(33);
        update(x, y, num);
    }
}

void update(int *x, int *y, int num) { // update coordinates
    register int i;
    for (i = 0; i < num; i++) {
        if (x[i] == num - i) {
            if (y[i] == num - i) {
                if (i != 0) {
                    x[i] += 1;
                }
            }
            else {
                y[i] -= 1;
            }
        }
        else if (x[i] == num + i) {
            if (y[i] == num + i) {
                x[i] -= 1;
            }
            else {
                y[i] += 1;
            }
        }
        else {
            if (y[i] < num) {
                x[i] += 1;
            }
            else if (y[i] > num) {
                x[i] -= 1;
            }
        }
    }
}

void draw (int *x, int *y, int num, char l) { // render
    register int i, j, h;
    register char k;
    for (i = 1; i <= num * 2 - 1; i++) {
        for (j = 1; j <= num * 2 - 1; j++) {
            k = 'N';
            for (h = 0; h < num; h++) { // checks whether that spot has an char on it
                if (x[h] == j && y[h] == i) {
                    k = 'Y';
                }
            }
            if (k == 'Y') {
                printf("%c", l);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}