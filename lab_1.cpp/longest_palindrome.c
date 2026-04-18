// to find the largest palindrome in the string array.
#include <stdio.h>

// function to check palindrome
int isPalindrome(int num) {
    int original = num;
    int rev = 0;

    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }

    return original == rev;
}

// function to count digits
int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

int main() {
    int arr[] = {121, 12321, 44, 789, 1221};
    int n = sizeof(arr) / sizeof(arr[0]);

    int longestPalindrome = -1;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        if (isPalindrome(arr[i])) {
            int len = countDigits(arr[i]);

            if (len > maxLength) {
                maxLength = len;
                longestPalindrome = arr[i];
            }
        }
    }

    printf("Longest Palindrome: %d", longestPalindrome);
    return 0;
}
