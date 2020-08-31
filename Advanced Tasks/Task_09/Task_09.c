#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node { 
    int data; 
    struct node* next; 
}; 

/*function prototypes*/
int random(int a, int b);
struct node* find(int pos);
void insert(int data, int pos);
void remove(int pos);
int search(int data);
void printList();
void sort();

/*global variables*/
struct node *head = NULL;
int length = 0;

int random(int a, int b) {
    return rand() % (b - a) + a;
}

struct node* find(int pos) { // converts index to pointer to the item
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
    if (pos != length) { // assign pointer to next item
        link->next = find(pos);
    } else { // if at the end of the list, simply use NULL
        link->next = NULL;
    }
    if (pos == 0) {
        head = link; // assign new head
    } else { // assign new next pointer for previous item
        find(pos - 1)->next = link;
    }
}

void remove(int pos) {
    if (pos == 0) { // if removing first item, simply reassign the head
        head = find(pos + 1);
    } else { // assign new pointer to skip the removed item
        find(pos - 1)->next = find(pos)->next;
    }
}

int search(int data) { // search for item, return 1 if found, 0 if not
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void printList() { // print
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort() { // sorts list using bubble sort
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
    for (i = 0; i < 10; i++) { // generate a linked list with 10 random ints
        insert(random(0, 100), 0);
        length++;
    }

    while (1) {
        printf("1: insert\n2: remove\n3: search\n4: print list\n5: sort\n");
        scanf(" %c", &navi);
        switch (navi) {
            case '1': // insert a int
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
            case '2': // remove an item
                printf("Remove which? (enter index)\n");
                scanf("%d", &i);
                if (i < 0 || i >= length) {
                    printf("INVALID POSITION\n");
                } else {
                    remove(i);
                    length--;
                break;
                }
            case '3': // search for item
                printf("Looking for what? (enter int)\n");
                scanf("%d", &i);
                if (search(i)) {
                    printf("This item is in the list\n");
                } else {
                    printf("This item is not in the list\n");
                }
                break;
            case '4': // print
                printList();
                break;
            case '5': // bubble sort
                sort();
        }
        printf("\n\n");
    }
}