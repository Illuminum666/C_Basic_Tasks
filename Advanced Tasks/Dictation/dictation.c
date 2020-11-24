#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#define arraylen 1000

void XORSwap (int *a, int *b);
int random(int a, int b);
void validate(int i);
int linearSearch(int *arr, int goal);
int binarySearch(int *arr, int goal);
void bubbleSort(int *arr);

void XORSwap (int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int random(int a, int b) {
    return (rand() % (b - a) + a);
}

int inOrder(int *arr) {
    int i;
    for (i = 1; i < arraylen; i++) {
        if (arr[i] < arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

void validate(int i) {
    if (i < 0) {
        printf("Not found\n");
    } else {
        printf("The item is found at %d\n", i);
    }
}

int linearSearch(int *arr, int goal) {
    int i;
    for (i = 0; i < arraylen; i++) {
        if (arr[i] == goal) {
            return (i);
        }
    }
    return (-1);
}

int binarySearch(int *arr, int goal) {
    int min = 0, mid, max = arraylen - 1;
    while (min <= max) {
        mid = (min + max) / 2;
        if (arr[mid] == goal) {
            return (mid);
        } else if (arr[mid] < goal) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return (-1);
}

void bubbleSort(int *arr) {
    int i, j;
    for (i = arraylen - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                XORSwap(arr+j, arr+(j + 1));
            }
        }
    }
}

void insertionSort(int *arr) {
    int i, j, temp;
    for (i = 1; i < arraylen; i++) {
        temp = arr[i];
        for (j = i; arr[j - 1] > temp && j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
}

void mergeSort(int *arr, int min, int max) {
    int mid, i, j, k;
    if (min < max) {
        mid = (min + max) / 2;
        int left[mid - min + 1], right[max - mid];
        mergeSort(arr, min, mid);
        mergeSort(arr, mid + 1, max);

        for (i = min; i <= mid; i++) {
            left[i - min] = arr[i];
        }
        for (i = mid + 1; i <= max; i++) {
            right[i - mid - 1] = arr[i];
        }

        i = min;
        j = 0;
        k = 0;
        while (i <= max && j <= (mid - min) && k <= (max - mid - 1)) {
            if (left[j] < right[k]) {
                arr[i] = left[j];
                j++;
            } else {
                arr[i] = right[k];
                k++;
            }
            i++;
        }
        while (j <= (mid - min)) {
            arr[i] = left[j];
            i++;
            j++;
        }
        while (k <= (max - mid - 1)) {
            arr[i] = right[k];
            i++;
            k++;
        }
    }
}

int main() {
    int i, goal, arr[1000];
    char c;

    srand(time(NULL));
    for (i = 0; i < 1000; i++) {
        arr[i] = random(0, 1000);
    }

    do {
        printf("1 for linear, 2 for binary, 3 for bubble, 4 for insertion, 5 for merge, 6 for show array, 7 for check order, 8 for re-randomize array\n");
        scanf(" %c", &c);
        switch (c) {
            case '1':
                if (inOrder(arr)) {
                    printf("Look for which number? (0-1000)\n");
                    scanf("%d", &goal);
                    validate(linearSearch(arr, goal));
                } else {
                    printf("Array must be sorted before search");
                }
                break;
            case '2':
                if (inOrder(arr)) {
                    printf("Look for which number? (0-1000)\n");
                    scanf("%d", &goal);
                    validate(binarySearch(arr, goal));
                } else {
                    printf("Array must be sorted before search");
                }
                break;
            case '3':
                bubbleSort(arr);
                printf("Sorted!");
                break;
            case '4':
                insertionSort(arr);
                printf("Sorted!");
                break;
            case '5':
                mergeSort(arr, 0, arraylen);
                printf("Sorted!");
                break;
            case '6':
                for (i = 0; i < arraylen; i++) {
                    printf("%d\t", arr[i]);
                }
                break;
            case '7':
                if (inOrder(arr)) {
                    printf("The array is in order\n");
                } else {
                    printf("The array is not in order\n");
                }
                break;
            case '8':
                for (i = 0; i < 1000; i++) {
                    arr[i] = random(0, 1000);
                }
                break;
            default:
                printf("invalid input\n");
        }
        Sleep(2000);
        printf("\n\n");
    } while(1);
        

}