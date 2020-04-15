#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int x, num, i=0;
    printf("Number:\t");
    scanf("%d", &num);
    while (num > 1) {
        if (num % 2 == 1) {
            x = num * 3 + 1;
        }
        else {
            x = num / 2;
        }
        i++;
        num = x;
        printf("%d\t%d\n", i, num);
    }
    system("pause");
    return 0;
}