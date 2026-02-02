// wap to tell the number of similar and dissimilar elements in the 2 arrays enterd by the user

#include <stdio.h>

int main(){
    int arr1[100] = {1,2,6,3,4};  // size=5
    int arr2[100]= {5,2,2,3};     // size=4
    int common =0;
    int visited[100]={0};  // this will set all the elments of this array to 0.
    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            if(arr1[i]==arr2[j] && visited[j]==0){
                common++;
                visited[j]=1; 
                break;
            }
        }
    }
    printf("common elements=%d\n",common);
    printf("dissimilar elements=%d", (5+4) - 2*common);  // this is the simple logic to calculate the dissimilar elements
    return 0;
}

// visited[j]=1; and visited wala array huma isliya bnana padha taki hum duplicate wala elements hat jaya and common ma bar bar count na ho jaya