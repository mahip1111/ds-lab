// Circular Linked List
// Insertion – Beginning
// Insertion – Before a node
// Deletion – End
// Traversal
// Reversal

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertBefore(int key, int val) {
    struct Node *temp = head, *prev = NULL;

    do {
        if(temp->data == key)
            break;

        prev = temp;
        temp = temp->next;

    } while(temp != head);

    if(temp->data != key) {
        printf("Node not found\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    if(temp == head) {
        insertBeginning(val);
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
}

void deleteEnd() {
    struct Node *temp = head, *prev = NULL;

    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

void traversal() {
    struct Node* temp = head;

    if(head == NULL)
        return;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("\n");
}

void reverse() {
    struct Node *prev=NULL, *current=head, *next;
    struct Node *first = head;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while(current != head);

    head->next = prev;
    head = prev;
}

int main() {

    insertBeginning(10);
    insertBeginning(20);
    insertBeginning(30);

    traversal();

    insertBefore(20, 15);

    traversal();

    deleteEnd();

    traversal();

    reverse();

    traversal();

    return 0;
}