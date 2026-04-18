// Doubly Linked List
// Insertion – End
// Insertion – After a node
// Deletion – Beginning

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int val) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfter(int key, int val) {

    struct Node* temp = head;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL) {
        printf("Node not found\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteBeginning() {

    if(head == NULL)
        return;

    struct Node* temp = head;

    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

void display() {

    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    display();

    insertAfter(20, 25);

    display();

    deleteBeginning();

    display();

    return 0;
}