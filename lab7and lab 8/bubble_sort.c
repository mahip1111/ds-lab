// BUBBLE SORT:
#include <stdio.h>

int main() {
    int arr[] = {5, 3, 8, 2};
    int n = 4;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // print sorted array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Pro tip:
// 👉 Bubble sort =
// "Compare → Swap → Repeat → Largest goes to end"


// DRY RUN: 
// 🔁 Step-by-step:

// Pass 1:
// Compare 5 & 3 → swap → 3 5 8 2
// Compare 5 & 8 → no swap → 3 5 8 2
// Compare 8 & 2 → swap → 3 5 2 8
// 👉 Sabse bada element (8) end pe aa gaya

// Pass 2:
// Compare 3 & 5 → no swap
// Compare 5 & 2 → swap → 3 2 5 8

// Pass 3:
// Compare 3 & 2 → swap → 2 3 5 8

// 👉 Final sorted array: 2 3 5 8