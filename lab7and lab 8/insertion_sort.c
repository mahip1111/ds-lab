// INSERTION SORT: 

#include <stdio.h>

int main() {
    int arr[] = {5, 3, 4, 1};
    int n = 4;

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// PRO TIP: 
// 👉 Har step me:
// Ek element uthate hain
// Left side me sorted part hota hai
// Usme correct position me insert karte hain

// 🔹 Insertion Sort – Super Easy Idea
// Socho tum cards khel rahe ho (playing cards) 🃏
// Tum ek-ek card uthate ho
// Aur apne haath me sahi jagah par insert karte ho
// Taaki tumhare cards hamesha sorted rahe
// 👉 Bas wahi insertion sort karta hai!

// DRY RUN: 
// 🔹 Step by Step Logic
// Maan lo array hai:
// [5, 3, 4, 1]

// 👉 Hum pehla element (5) ko sorted maan lete hain

// Step 1:
// 3 ko uthaya → compare kiya 5 se
// 👉 3 chhota hai → 5 ko right shift karo
// 👉 3 ko insert karo
// [3, 5, 4, 1]

// Step 2:
// 4 ko uthaya → compare 5 se → shift
// compare 3 se → ruk jao → insert
// [3, 4, 5, 1]

// Step 3:
// 1 ko uthaya → sabse chhota
// 👉 sabko shift karo → front me daalo
// [1, 3, 4, 5]


// 🔹 Code Explanation (Super Easy)
// 🔸 for(int i = 1; i < n; i++)

// First element already sorted hai

// Isliye i = 1 se start

// 🔸 int key = arr[i];

// Jo element insert karna hai → usko key bolte hain

// 🔸 int j = i - 1;

// Left side ka last element (sorted part ka end)

// 🔸 while(j >= 0 && arr[j] > key)

// 👉 Jab tak:

// left element bada hai

// tab tak shift karte raho

// 🔸 arr[j + 1] = arr[j];

// 👉 Element ko right shift kar diya

// 🔸 j--;

// 👉 Left move karte jao

// 🔸 arr[j + 1] = key;

// 👉 Correct position mil gayi
// 👉 Yaha insert kar diya

// 🔹 Short Summary (Exam Ready)

// Insertion sort me array ko do parts me divide karte hain:

// sorted part (left)

// unsorted part (right)

// Har step me ek element uthake correct position me insert karte hain