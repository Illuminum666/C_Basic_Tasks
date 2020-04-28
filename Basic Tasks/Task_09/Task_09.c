#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num[5];
    int length_of_array = 0;
    float sum, average, max, min;

    /* Print basic information about the array */
    printf("---------------------------------------\n");
    printf("Size of array num[]:\t%2d bytes\n", sizeof(num));
    printf("Size of each element:\t%2d bytes\n", sizeof(num[0]));

    length_of_array = sizeof(num)/sizeof(num[0]);
    printf("The array num[] has %d elements\n",length_of_array);
    printf("---------------------------------------\n\n");


    /* Print basic information about the array */
    printf("Getting numbers into the array...\n\n");

    int i;
    for (i=0; i<length_of_array; i++) {
        printf("num[%d] = ", i);
        scanf("%f", &num[i]);
    }

    printf("\nContent stored in the array...\n");
    printf("---------------------------------------\n");

    for (i = 0; i < length_of_array; i++) {
        printf("num[%d]\t", i);
    }
    printf("\n");
    for (i = 0; i < length_of_array; i++) {
        printf("%.2f\t", num[i]);
    } 

    printf("\n---------------------------------------\n");

    
   
   for (i = 0; i < length_of_array; i++) {
        if (i == 0) {
            max = num[i];
            min = num[i];
        } else {
            if (num[i] > max) {
                max = num[i];
            }
            if (num[i] < min) {
                min = num[i];
            }
        }
        sum += num[i];
    } 
    printf("Max\t= %.2f\n", max);
    printf("Min\t= %.2f\n", min);
    printf("Sum\t= %.2f\n", sum);
    printf("Average\t= %.2f\n", sum / length_of_array);


    system("pause");
    return 0;
}