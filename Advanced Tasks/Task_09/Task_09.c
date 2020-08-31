#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node { 
    int data; 
    struct node* next; 
}; 

struct node *head = NULL;
int length = 0;

int random(int a, int b) {
    return rand() % (b - a) + a;
}

struct node* find(int pos) {
    int i;
    struct node *temp = head;
    for (i = 0; i < pos; i++) {
        temp = temp->next;
    }
    return temp;
}

void insert(int data, int pos) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    if (pos != length) {
        link->next = find(pos);
    } else {
        link->next = NULL;
    }
    if (pos == 0) {
        head = link;
    } else {
        find(pos - 1)->next = link;
    }
}

void remove(int pos) {
    if (pos == 0) {
        head = find(pos + 1);
    } else {
        find(pos - 1)->next = find(pos)->next;
    }
}

int search(int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printList() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort() {
    struct node *temp;
    int i, j, othertemp;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (find(j)->data > find(j + 1)->data) {
                othertemp = find(j)->data;
                remove(j);
                insert(othertemp, j + 1);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int i, j;
    char navi;
    for (i = 0; i < 10; i++) {
        insert(random(0, 100), 0);
        length++;
    }

    while (1) {
        printf("1: insert\n2: remove\n3: search\n4: print list\n5: sort\n");
        scanf(" %c", &navi);
        switch (navi) {
            case '1':
                printf("Insert what? (enter int)\n");
                scanf("%d", &i);
                printf("Insert where? (enter index)\n");
                scanf("%d", &j);
                if (j < 0 || j > length) {
                    printf("INVALID POSITION\n");
                } else {
                    insert(i, j);
                    length++;
                }
                break;
            case '2':
                printf("Remove which? (enter index)\n");
                scanf("%d", &i);
                if (i < 0 || i >= length) {
                    printf("INVALID POSITION\n");
                } else {
                    remove(i);
                    length--;
                break;
                }
            case '3':
                printf("Looking for what? (enter int)\n");
                scanf("%d", &i);
                if (search(i)) {
                    printf("This item is in the list\n");
                } else {
                    printf("This item is not in the list\n");
                }
                break;
            case '4':
                printList();
                break;
            case '5':
                sort();
        }
        printf("\n\n");
    }
}