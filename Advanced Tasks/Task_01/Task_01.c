#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char myStack[10001];  //a stack of 500 elements
int top = -1;       //index pointing to the topmost element, -1 means an empty stack


/*FUNCTION PROTOTYPES*/
int isEmpty(void);
void push(char ch);
char pop(void);
void printStack(void);


int isEmpty(void) {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(char ch) {
    myStack[top + 1] = ch;
    top += 1;
}

char pop(void) {
    if (!(isEmpty())) {
        char temp = myStack[top];
        myStack[top] = myStack[top + 1];
        top = top - 1;
        return temp;
    } else {
        printf("Stack is empty\n");
        return NULL;
    }
}

void printStack(void) {
    int i;
    for (i = 0; i < strlen(myStack); i++) {
        printf("%c", myStack[i]);
    }
    printf("\n");
}

/*
int main() {
    char C, p;
    do {
        printf("input: ");
        scanf(" %c", &C);
        switch (C) {
            case '1':
                if (isEmpty()) {
                    printf("Is empty\n");
                } else {
                    printf("not empty\n");
                }
                break;
            case '2':
                printf("push what? ");
                scanf(" %c", &p);
                push(p);
                break;
            case '3':
                printf("%c\n", pop());
                break;
            case '4':
                printStack();
                break;
            case '5':
                printf("%d\n", top);
        }
    } while (1);
} */

int main() {
    char *p, a, string[10001];
    if (fgets(string, sizeof(string), stdin) != NULL) {
        if ((p = strchr(string, '\n')) != NULL) {
            *p = '\0';  // the \n will be replaced by the NULL character
        }
    }

    int i;
    for (i = 0; i < strlen(string); i++) {
        a = string[i];
        if (a == '(' || a == '[' || a == '{') {
            push(a);
        } else if (a == ')' || a == ']' || a == '}') {
            if (isEmpty()) {
                printf("No\n");
                return 0;
            }
            switch (a) {
                case ')':
                    if (pop() != '(') {
                        printf("No\n");
                        return 0;
                    }
                    break;
                case ']':
                    if (pop() != '[') {
                        printf("No\n");
                        return 0;
                    }
                    break;
                case '}':
                    if (pop() != '{') {
                        printf("No\n");
                        return 0;
                    } 
                    break;
            }
        }
    }

    if (isEmpty()) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}