#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* function prototypes */
void InsertionSort(int *numarr, int arraylen);
int InOrder(int *numarr, int arraylen);

void InsertionSort(int *numarr, int arraylen) { // insertion sort function
    int i, j, temp;
    for (i = 1; i < arraylen; i++) {
        temp = numarr[i];
        for (j = i; j > 0 && numarr[j-1] > temp; j--) {
            numarr[j] = numarr[j-1];
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

int main() {
    int i, numarr[10000];

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

    InsertionSort(numarr, 10000);

    if (!(InOrder(numarr, 10000))) {
        printf("Error! Array not in order\n");
        system("pause");
        return 0;
    }

    for (i = 0; i < 10000; i++) { // printing
        printf("%d\t", numarr[i]);
    }

    system("pause");
    return 0;
}