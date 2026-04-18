// wap to find the largest palindrome in the string given by the user
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0, maxLen = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    int n = strlen(str);

    for(int i = 0; i < n; i++) {

        // Odd length palindrome
        int left = i, right = i;

        while(left >= 0 && right < n && str[left] == str[right]) {
            if(right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        // Even length palindrome
        left = i;
        right = i + 1;

        while(left >= 0 && right < n && str[left] == str[right]) {
            if(right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    printf("Largest Palindrome Substring: ");

    for(int i = start; i < start + maxLen; i++) {
        printf("%c", str[i]);
    }

    return 0;
}