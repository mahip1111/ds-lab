#include <stdio.h>

int main(){
    int r1 = 5, c1 = 5, r2 = 5, c2 = 5;

    int arr1[r1][c1], arr2[r2][c2], ans[r1][c2];

    printf("Enter elements of first matrix:\n");
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            scanf("%d", &arr2[i][j]);
        }
    }

    // Initialize ans matrix with 0
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            ans[i][j] = 0;   // reason of this told below
        }
    }

    // Matrix multiplication
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            for(int k = 0; k < c1; k++){
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// why it is important to initalize the ans array:
// 🔹 C me local variables ka rule

// Jab tum ye likhte ho:

// int ans[5][5];


// Toh C kuch bhi guarantee nahi deta ki iske andar kya value hogi.

// ➡️ ans ke har cell me garbage value hoti hai
// (jo pehle memory me pada hua tha)

// Example:

// ans[0][0] = 32767
// ans[0][1] = -12456
// ans[0][2] = 890


// Random. Totally unpredictable 😬

// 🔹 Tumhara loop kya kar raha hai?
// ans[i][j] += arr1[i][k] * arr2[k][j];


// Important word: +=

// Matlab:

// ans[i][j] = ans[i][j] + (arr1[i][k] * arr2[k][j])


// Agar ans[i][j] pehle se garbage hai, toh:

// garbage + correct value = WRONG ANSWER ❌