// wap to print the normalized frequency and total occurence of the characetrs in the string enter by the user
#include <stdio.h>

int main() {
    char str[100];
    int freq[26] = {0};
    int total = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);   // this is the safest way here to take the string 
    // gets(str);
    // scanf("%[^/n]",str);

    // Count frequency and total characters
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]-'a']++;
        total++;
    }

    // Print normalized frequency
    printf("\nCharacter   Normalized Frequency\n");
    for (int i = 0; i < 26; i++) {
        if(freq[i]!=0){
        printf("frequency of %c is %.2f\n", ('a'+ i), (float)freq[i]/total);}
    }
    printf("Thus the total no. of characters in the give string is: %d", total);

    return 0;
}


// IMPORVEMENTS: 
// 1. use of gets is risky
