#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// a. Count nodes
void countNodes() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total nodes = " << count << endl;
}

// b. Search element
void searchElement(int key) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Element found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Element not found\n";
}

// c. Insert at beginning
void insertBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// d. Insert at end
void insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// e. Insert before a location (position)
void insertBefore(int pos, int value) {
    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// f. Insert after a location
void insertAfter(int pos, int value) {
    Node* temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// g. Delete operation (by value)
void deleteNode(int key) {
    if (head == NULL) return;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        cout << "Element not found\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// display list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertBeginning(10);
    insertEnd(20);
    insertEnd(30);
    display();

    insertBefore(2, 15);
    display();

    insertAfter(3, 25);
    display();

    deleteNode(20);
    display();

    countNodes();
    searchElement(25);

    return 0;
}
