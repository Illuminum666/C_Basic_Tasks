#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>

/* function prototypes */
void BubbleSort(int *numarr, int arraylen);
void XORSwap(int *a, int *b);
int InOrder(int *numarr, int arraylen);
int random(int a, int b);

/*global variables*/
int SwapCount = 0;

void XORSwap(int *a, int *b) { // for swapping numbers
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    SwapCount++;
}

void BubbleSort(int *numarr, int arraylen) { // bubble sort function
    int i, j;
    for (i = 0; i < arraylen - 1; i++) {
        for (j = 0; j < arraylen - i - 1; j++) {
            if (numarr[j] > numarr[j + 1]) {
                XORSwap(&numarr[j], &numarr[j + 1]);
            }
        }
    }
}

int InOrder(int *numarr, int arraylen) { // checks array
    int i;
    for (i = 0; i < arraylen - 1; i++) {
        if (numarr[i] > numarr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int random(int a, int b) {
    return rand() % (b - a) + a;
}

int main() {
    srand(time(NULL));
    int i = 0, j, numarr[10000], results[100];

    for (j = 0; j <= 10000; j += 100) {
        for (i = 0; i < j; i++) {
            numarr[i] = random(0, j);
        }

        SwapCount = 0;
        BubbleSort(numarr, j);

        results[j / 100] = SwapCount;
        printf("Loading... (%d%%)\r", ((j + 1) / 100));
    }

    system("cls");
    for (j = 0; j <= 10000; j += 100) { // print result
        printf("%d\n", j);
    }
    for (j = 0; j <= 100; j++) { // print result
        printf("%d\n", results[j]);
    }

    system("pause");
    return 0;
}