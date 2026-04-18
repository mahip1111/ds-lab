#include <stdio.h>

// partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // last element as pivot
    int i = low - 1;
    int temp;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;

            // swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // place pivot at correct position
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// quick sort function
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // left side
        quickSort(arr, pi + 1, high); // right side
    }
}

// main function
int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}