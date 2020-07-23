#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b) { // for swapping numbers
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int *arr, int s, int e) {
    if (s < e) {
        int i = s - 1, j;
        for (j = s; j < e; j++) {
            if (arr[j] <= arr[e]) {
                swap(&arr[++i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[e]);

        quickSort(arr, s, i);
        quickSort(arr, i + 1, e);
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

    quickSort(numarr, 0, 9999);

    if (!(InOrder(numarr, 10000))) {
        printf("Error! Array not in order\n");
        system("pause");
        return 0;
    }

    for (i = 0; i < 10000; i++) {
        printf("%d\t", numarr[i]);
    }

    system("pause");
    return 0;
}