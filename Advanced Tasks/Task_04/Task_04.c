#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

/* function prototypes */
void BubbleSort(int *numarr, int arraylen);
void XORSwap(int *a, int *b);
int InOrder(int *numarr, int arraylen);

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

int main() {
    int i = 0, numarr[10000];
    char num[6];

    FILE *fp;
    fp = fopen("numbers.txt", "r");

    if (fp == NULL) { // detects whether the text file is present or not
        printf("Text file not detected\n");
        system("pause");
        return 0;
    }

    for (i = 0; i < 10000; i++) {
        fscanf(fp, "%d", &numarr[i]);
    }

    BubbleSort(numarr, 10000);

    if (!(InOrder(numarr, 10000))) {
        printf("Error! Array not in order\n");
        system("pause");
        return 0;
    } 

    for (i = 0; i < 10000; i++) {
        printf("%d\t", numarr[i]);
    }

    printf("\nTotal number of swaps is %d\n", SwapCount);

    system("pause");
    return 0;
}