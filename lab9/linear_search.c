#include <stdio.h>

int linear_Search(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i;
    }
    return -1;
}

int main(){
    printf("Enter the size of the array: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the key you want to search in the array: ");
    scanf("%d",&key);
    printf("Index of the key in the array is: %d", linear_Search(arr, n, key));
    return 0;
}

// some of the mistakes you make while writing the code:

// scanf ma space de di thi %d ma 