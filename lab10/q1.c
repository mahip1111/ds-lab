// For a given set of integers 50, 30, 70, 20, 40, 60, 80
// construct the bst and display its inorder, preorder and postorder traversal
// wap to insert and delete a node in this bst 

#include <stdio.h>
#include <stdlib.h>

// Node structure using typedef
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find minimum node
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Traversals
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main
int main() {
    Node* root = NULL;

    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    int insertVal;
    printf("\n\nEnter value to insert: ");
    scanf("%d", &insertVal);
    root = insert(root, insertVal);

    printf("Inorder after insertion: ");
    inorder(root);

    int deleteVal;
    printf("\nEnter value to delete: ");
    scanf("%d", &deleteVal);
    root = deleteNode(root, deleteVal);

    printf("Inorder after deletion: ");
    inorder(root);

    return 0;
}
