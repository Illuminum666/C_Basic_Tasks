#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, num, value1=1, value2=0, temp;
    printf("Number of values (max 46):\t");
    scanf("%d", &num);
    for (i = 1; i <= num; i++) {
        printf("%d\t%d\n", i, value1);
        temp = value1;
        value1 = value1 + value2;
        value2 = temp;
    }
    system("pause");
    return 0;
}