#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char cirQueue[500];

int isEmpty(void);
int isFull(void);
char deQueue(void);
void enQueue(char);
void printQueue(void);

int isEmpty(void) {
    return !(strlen(cirQueue));
}

int isFull(void) {
    return (strlen(cirQueue) > 15);
}

char deQueue(void) {
    if (!(isEmpty())) {
        int i;
        char temp = cirQueue[0];
        for (i = 0; i <= strlen(cirQueue); i++) {
            cirQueue[i] = cirQueue[i + 1];
        }
        return temp;
    } else {
        printf("Queue is empty");
        return NULL;
    }
}

void enQueue(char ch) {
    if (isFull()) {
        deQueue();
    }
    cirQueue[strlen(cirQueue)] = ch;
}


void printQueue(void) {
    int i;
    for (i = 0; i < strlen(cirQueue); i++) {
        printf("%c", cirQueue[i]);
    }
    printf("\n");
}

int main() { // code used for testing
    char C, p;
    do {
        printf("input: ");
        scanf(" %c", &C);
        switch (C) {
            case '1': // tests isEmpty(), enter 1 to use
                if (isEmpty()) { 
                    printf("Is empty\n");
                } else {
                    printf("not empty\n");
                }
                break;
            case '2': // tests enQueue(), enter 2 to use
                printf("push what? ");
                scanf(" %c", &p);
                enQueue(p);
                break;
            case '3': // tests deQueue(), enter 3 to use
                printf("%c\n", deQueue());
                break;
            case '4': // tests printQueue(), enter 4 to use
                printQueue();
                break;
            case '5': // tests isFull(), enter 5 to use
                if (isFull()) { 
                    printf("Is full\n");
                } else {
                    printf("not full\n");
                }
        }
    } while (1);
}