// print all the non repeating elements
#include <stdio.h>

int main(){
    int arr[5]={1,2,2,3,4};
    for(int i=0; i<5; i++){
        int count=0;
        for(int j=0; j<5; j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            printf("%d",arr[i]);
        }
    }

    return 0;
}
