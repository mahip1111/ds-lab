#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int total = 0;

    printf("Enter a string: ");
    gets(str);

    // Count frequency and total characters
    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i]]++;
        total++;
    }

    // Print normalized frequency
    printf("\nCharacter   Normalized Frequency\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("   %c\t\t%.2f\n", i, (float)freq[i] / total);
        }
    }

    return 0;
}
