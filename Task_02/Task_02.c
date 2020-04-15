#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592654

int main()
{
    printf("Radius?\t");
    double radius;
    scanf("%lf", &radius);
    printf("Area:\t%.4f\n", PI*radius*radius);
    system("pause");
    return 0;
}