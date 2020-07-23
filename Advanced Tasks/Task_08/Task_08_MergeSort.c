#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function prototypes */
void merge(int *arr, int l, int m, int r);
void mergeSort(int *arr, int l, int r);
int InOrder(int *numarr, int arraylen);

void merge(int *arr, int l, int m, int r) { // merge arrays together
    int left[m - l + 1], right[r - m];
    int i, j, k = l;

    for (i = 0; i <= m - l; i++) {
        left[i] = arr[i + k];
    }
    for (j = 0; j < r - m; j++) {
        right[j] = arr[m + j + 1];
    }

    i = 0;
    j = 0;
    while (i <= m - l && j < r - m) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i <= m - l) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < r - m) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) { // merge sort
    if (l < r) {
        int m = floor(l + (r - l) / 2);
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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

    mergeSort(numarr, 0, 9999);

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