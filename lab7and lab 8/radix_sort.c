#include <stdio.h>

// function to get maximum number
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// counting sort (digit wise)
void countingSort(int arr[], int n, int exp) {
    int output[n];   // result array
    int count[10] = {0}; // 0-9 digits

    // count occurrences
    for(int i = 0; i < n; i++)
        count[(arr[i]/exp) % 10]++;

    // cumulative count
    for(int i = 1; i < 10; i++)
        count[i] += count[i-1];

    // build output array
    for(int i = n-1; i >= 0; i--) {
        int index = (arr[i]/exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // copy back
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

// main radix sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for(int exp = 1; max/exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;

    radixSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}