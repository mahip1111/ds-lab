// SELECTION SORT:
#include <stdio.h>

int main() {
    int arr[] = {5, 3, 8, 2, 1};
    int n = 5;

    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // print array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// PRO TIP:
// 👉 Selection sort = har round me smallest element uthao aur front me rakh do

// DRY RUN:
// 🧠 Step-by-step:
// ✅ Round 1:
// List: 5 3 8 2 1
// 👉 Sabse chhota = 1
// 👉 Swap with first element
// ➡️ 1 3 8 2 5

// ✅ Round 2:
// List: 1 | 3 8 2 5
// 👉 (1 already sorted hai)
// 👉 Remaining me smallest = 2
// 👉 Swap with 3
// ➡️ 1 2 8 3 5

// ✅ Round 3:
// List: 1 2 | 8 3 5
// 👉 Smallest = 3
// ➡️ 1 2 3 8 5

// ✅ Round 4:
// List: 1 2 3 | 8 5
// 👉 Smallest = 5
// ➡️ 1 2 3 5 8

// 🎯 Final Output:
// 👉 1 2 3 5 8