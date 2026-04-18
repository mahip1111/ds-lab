// create an avl tree for the follwing sequence [50,40,35,58,48,42,60,30,33,25]
// delete 58 from the tree

#include <stdio.h>
#include <stdlib.h>

// Node definition using typedef
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Height
int height(Node *n)
{
    return (n == NULL) ? 0 : n->height;
}

// Max
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Create node
Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Balance factor
int getBalance(Node *n)
{
    return (n == NULL) ? 0 : height(n->left) - height(n->right);
}

// Insert
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // LL
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // RR
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // LR
    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Min value node
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete
Node *deleteNode(Node *root, int key)
{

    // 1. Normal BST delete
    if (root == NULL)
        return NULL;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node mil gaya

        // Case 1: 0 child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: 1 child

        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        // Case 3: 2 children
        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // 2. Height update
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Balance check
    int balance = getBalance(root);

    // 4. Rotations

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// Inorder
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    int arr[] = {50, 40, 35, 58, 48, 42, 60, 30, 33, 25};

    for (int i = 0; i < 10; i++)
        root = insert(root, arr[i]);

    printf("Before deletion:\n");
    inorder(root);

    root = deleteNode(root, 58);

    printf("\nAfter deleting 58:\n");
    inorder(root);

    return 0;
}