#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int binarySearch(int *arr, int arraylen, int goal);

int binarySearch(int *arr, int arraylen, int goal) {
   int min = 0, max = arraylen - 1, mid;
   do {
      mid = floor(min + (min + max) / 2);
      if (arr[mid] == goal) {
         break;
      } else if (arr[mid] > goal) {
         max = mid - 1;
      } else {
         min = min + 1;
      }
   } while (1);
   return mid;
}

int main() {
   int arr[] = {0,1,8,12,12,18,18,45,55,99};
   int n = 45;
   printf("%d is found at Index %d \n", n, binarySearch(arr, 10, n));
   system("pause");
   return 0;
}