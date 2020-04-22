#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265358979323846

int main() {
    short num, i, j, amp, per;
    char again='Y';
    do {
        printf("Enter the number of rows [1-9]:\t");
        scanf("%hd", &num);
        printf("Enter amplitude [integer]:\t");
        scanf("%hd", &amp);
        printf("Enter period [integer]:\t");
        scanf("%hd", &per);

        printf("\nPattern #1\n\n"); //Pattern #1
        for (i = 1; i <= num; i++) {
            for (j = 1; j <= (num - i); j++) {
                printf(" ");
            }
            for (j = i; j > 0; j--) {
                printf("%d", j);
            }
            printf("\n");
        }

        printf("\nPattern #2\n\n"); //Pattern #2
        for (i = 1; i <= num; i++) {
            for (j = (i * (i + 1)) / 2 - i + 1; j <= (i * (i + 1)) / 2; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }

        printf("\nPattern #3\n\n"); //Pattern #3
        for (i = 1; i <= num; i++) {
            for (j = 1; j <= num; j++) {
                if (j == i || j == num - i + 1) {
                    printf("%d", j);
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        

        printf("\nPattern #4\n\n"); //Pattern #4
        for (i = 1; i <= num; i++) {
            for (j = 1; j <= num - i; j++) {
                printf(" ");
            }
            for (j = 1; j <= i; j++) {
                printf("%d", j);
            }
            for (j = i - 1; j > 0; j--) {
                printf("%d", j);
            }
            printf("\n");
        }

        printf("\nSine Curve\n\n"); //Sine Curve
        for (i = amp; i >= -amp; i--) {
            for (j = 0; j <= per; j++) {
                if (round(sin(j * PI * 2 / per) * amp) == i) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("Try again? [Y/N]\t");
        scanf(" %c", &again);
    } while (again == 'Y'||again == 'y');
    system("pause");
    return 0;
}