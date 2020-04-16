#include <stdio.h>
#include <stdlib.h>

void TempSwap(int a, int b);
void PlusMinusSwap(int a, int b);
void XORSwap(int a, int b);

int main(void) {
    int a,b;
    printf("Input a and b: \n");
    scanf("%d %d", &a, &b);
    printf("Before swapping:\t a=%d b=%d \n", a, b);
    TempSwap(a,b);      //Swap using a temp variable
    PlusMinusSwap(a,b); //Swap using + and - operators only
    XORSwap(a,b);       //Swap using XOR operator only

    system("pause");
    return 0;
}

void TempSwap(int a, int b) {
    int temp = a;    
    a = b;
    b = temp;
    printf("Using 'temp' swap:\t a=%d b=%d \n", a, b);
}

void PlusMinusSwap(int a, int b) {
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Using 'Plus-Minus' swap: a=%d b=%d \n", a, b);
}

void XORSwap(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("Using 'XOR' swap:\t a=%d b=%d \n", a, b);
}