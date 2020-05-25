#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char seqQueue[500];

int isEmpty(void);
void enQueue(char);
char deQueue(void);
void printQueue(void);

int isEmpty(void) {
    return !(strlen(seqQueue));
}

void enQueue(char ch) {
    seqQueue[strlen(seqQueue)] = ch;
}

char deQueue(void) {
    if (!(isEmpty())) {
        int i;
        char temp = seqQueue[0];
        for (i = 0; i <= strlen(seqQueue); i++) {
            seqQueue[i] = seqQueue[i + 1];
        }
        return temp;
    } else {
        printf("Queue is empty");
        return NULL;
    }
    
}

void printQueue(void) {
    int i;
    for (i = 0; i < strlen(seqQueue); i++) {
        printf("%c", seqQueue[i]);
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
        }
    } while (1);
}