#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end) {
    // Base case
    if (start >= end)
        return;

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    reverse(str, start + 1, end - 1);
}

int main() {
    char str[100];

    scanf("%s", str);

    int length = strlen(str);

    reverse(str, 0, length - 1);

    printf("%s", str);

    return 0;
}
