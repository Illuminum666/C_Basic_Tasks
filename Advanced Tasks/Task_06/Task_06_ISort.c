#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

/* global variables */
int SwapCount;

/* function prototypes */
void InsertionSort(int *numarr, int arraylen);
int InOrder(int *numarr, int arraylen);
int random(int a, int b);

void InsertionSort(int *numarr, int arraylen) { // insertion sort function
    int i, j, temp;
    for (i = 1; i < arraylen; i++) {
        temp = numarr[i];
        for (j = i; j > 0 && numarr[j-1] > temp; j--) {
            numarr[j] = numarr[j-1];
            SwapCount++;
        }
        numarr[j] = temp;
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
    int i, j, numarr[10000], results[100];
    for (j = 0; j <= 10000; j += 100) {
        for (i = 0; i < j; i++) {
            numarr[i] = random(0, j);
        }

        SwapCount = 0;
        InsertionSort(numarr, j);

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