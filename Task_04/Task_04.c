#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    float a,b,c;
    double dis;
    printf("Solving quadratic equation: ax^2 +bx +c\n");
    printf("What's a, b and c? (seperated by spaces)\ne.g. 1 2 1\n");
    scanf("%f %f %f", &a, &b, &c);
    
    dis = b * b - 4 * a * c;

    if (a == 0) {
        printf("a = 0, not quadratic!");
    }
    else if (dis < 0) {
        printf("No real roots!\n");
    } 
    else if (dis == 0) {
        printf("Double roots:\n%.4f\n", (-b + sqrt(dis)) / (2 * a));
    }
    else {
        printf("Two real roots:\n%.4f and %.4f\n", (-b + sqrt(dis)) / (2 * a), (-b - sqrt(dis)) / (2 * a));
    }
    system("pause");
    return 0;
}