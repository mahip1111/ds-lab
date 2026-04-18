// Create a linear linkedlist.perform the following operations:
// a.count no of nodes
// b.search an element
// c.insert at beginning
// d. Insert at end
// e. Insert before a location
// f. Insert after a location
// g. Delete operation

#include <stdio.h>
#include <stdlib.h>

// node constructor
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 🔥 Create node (new function)
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// a. Count nodes
void countNodes(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("Total nodes = %d\n", count);
}

// b. Search element
void searchElement(Node* head, int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element not found\n");
}

// c. Insert at beginning
Node* insertBeginning(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// d. Insert at end
Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// e. Insert before position
Node* insertBefore(Node* head, int pos, int value) {
    if (pos == 1)
        return insertBeginning(head, value);

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// f. Insert after position
Node* insertAfter(Node* head, int pos, int value) {
    Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// g. Delete node by value
Node* deleteNode(Node* head, int key) {
    Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    return head;
}

// display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    head = insertBeginning(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    display(head);

    head = insertBefore(head, 2, 15);
    display(head);

    head = insertAfter(head, 3, 25);
    display(head);

    head = deleteNode(head, 20);
    display(head);

    countNodes(head);
    searchElement(head, 25);

    return 0;
}