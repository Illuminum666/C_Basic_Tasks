#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b;
    char op;

    printf("Enter a simple math expression with two operands (Example: 3 + 2)\nSeparate them with a space\n");
    printf("(Operator supported: +  -  *  / ^)\n\n");

    //input
    scanf("%f %c %f", &a, &op, &b);

    //process and output
    printf("Result:\t");
    switch (op) {
        case '+': 
            printf("%.2f + %.2f = %.2f\n", a, b, a + b);
            break;
        case '-': 
            printf("%.2f - %.2f = %.2f\n", a, b, a - b);
            break;
        case '*': 
            printf("%.2f * %.2f = %.2f\n", a, b, a * b);
            break;
        case '/': 
            printf("%.2f / %.2f = %.2f\n", a, b, a / b);
            break;
        case '^': 
            printf("%.2f ^ %.2f = %.2f\n", a, b, pow(a, b));
            break;
        default:
            printf("Invalid operator!\n");
    }

    system("pause");
    return 0;
}