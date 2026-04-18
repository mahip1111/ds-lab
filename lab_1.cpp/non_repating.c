// print all the non-repeating elements in the array:

#include <stdio.h>

int main(){
    int arr[5] = {1,2,2,3,4};
    int freq[10] = {0};    // here we are assuming the elements in the array is from 0-9 but you can change it according to the constraints
    int n = sizeof(arr)/ sizeof(arr[0]);

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    printf("All the non-repeating elements of the array are:\n");
    for(int i=0;i<10;i++){
        if(freq[i]==1){
            printf("%d\n",i);
        }
    }
    return 0;
}

// general method to solve the problem wehre number in the array can be in any range

// #include <stdio.h>

// int main(){

//     int arr[] = {1,2,2,3,4};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     printf("Non-repeating elements are:\n");

//     for(int i=0;i<n;i++){
//         int count = 0;

//         for(int j=0;j<n;j++){
//             if(arr[i] == arr[j]){
//                 count++;
//             }
//         }

//         if(count == 1){
//             printf("%d\n", arr[i]);
//         }
//     }

//     return 0;
// }