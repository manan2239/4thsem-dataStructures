#include <stdio.h>
#include <string.h>

void rev(char *str) {
    int n = strlen(str);
    for (int i=0; i<n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    }
int main () {
    char str[] = "computer science";
    printf("Original: %s\n", str);
    rev(str);
    printf("Reversed: %s\n", str);
    return 0;
}