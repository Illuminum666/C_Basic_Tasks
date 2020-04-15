#include <stdio.h>
#include <stdlib.h>

int main() {
    short int begin, column, row, i, j; //data input
    printf("Starting from? [1-90]\t");
    scanf("%hd", &begin);
    printf("No. of columns? [1-10]\t");
    scanf("%hd", &column);
    printf("Multiples up to? [1-99]\t");
    scanf("%hd", &row);

    printf("Result:\n"); //print result
    for (i=1; i<=row; i++) { //expand vert
        for (j=1; j<=column; j++) { //expand hori
            printf("%2dx%2d=%4d\t|", (begin + j - 1), i, ((begin + j - 1) * i));
        }
        printf("\n"); //new line
    }
    system("pause");
    return 0;
}