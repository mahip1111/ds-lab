// polynomial addition and polynomial multiplication

#include <stdio.h>
#include <stdlib.h>

/* Node structure for polynomial */
typedef struct Node {
    int coeff;
    int power;
    struct Node* next;
} Node;

/* Create a new node */
Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

/* Insert node at end */
void insert(Node** head, int coeff, int power) {
    Node* newNode = createNode(coeff, power);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

/* Display polynomial */
void display(const Node* head) {
    if (!head) {
        printf("Empty Polynomial\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

/* Add two polynomials */
Node* addPolynomials(const Node* p1, const Node* p2) {
    Node* result = NULL;

    while (p1 && p2) {
        if (p1->power == p2->power) {
            insert(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->power > p2->power) {
            insert(&result, p1->coeff, p1->power);
            p1 = p1->next;
        } 
        else {
            insert(&result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    /* Remaining terms */
    while (p1) {
        insert(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        insert(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

/* Free memory */
void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    /* Polynomial 1 */
    insert(&poly1, 1, 4);
    insert(&poly1, 6, 3);
    insert(&poly1, 54, 2);
    insert(&poly1, -17, 1);
    insert(&poly1, 1, 0);

    /* Polynomial 2 */
    insert(&poly2, 1, 9);
    insert(&poly2, 3, 7);
    insert(&poly2, -25, 5);
    insert(&poly2, -2, 3);
    insert(&poly2, 1, 1);
    insert(&poly2,-12,0);

    printf("Polynomial 1:\n");
    display(poly1);

    printf("Polynomial 2:\n");
    display(poly2);

    result = addPolynomials(poly1, poly2);

    printf("Result:\n");
    display(result);

    /* Free memory */
    freeList(poly1);
    freeList(poly2);
    freeList(result);

    return 0;
}