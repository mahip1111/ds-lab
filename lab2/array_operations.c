// wap to reverse, traverse, insert, delete array

#include <stdio.h>

void traverse(int arr[], int n) {
    printf("Array elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int n) {
    int temp;
    for(int i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

// pos means konsa index par dalna hai element
int insert(int arr[], int n, int element, int pos) {
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    return n + 1;
}

int delete(int arr[], int n, int pos) {
    for(int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    return n - 1;
}

int main() {
    int arr[100], n, element, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nTraverse:\n");
    traverse(arr, n);

    printf("\nReverse:\n");
    reverse(arr, n);
    traverse(arr, n);

    printf("\nInsert:\n");
    printf("Enter position and element: ");
    scanf("%d %d", &pos, &element);
    n = insert(arr, n, element, pos);
    traverse(arr, n);

    printf("\nDelete:\n");
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    n = delete(arr, n, pos);
    traverse(arr, n);

    return 0;
}

// NOTE: 
// just remember all these things means the same:
// void func(int arr[], int n)
// void func(int arr[100], int n)
// void func(int *arr, int n)