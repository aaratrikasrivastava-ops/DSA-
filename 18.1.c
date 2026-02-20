#include <stdio.h>

int main() {
    int n, k;

    // Read size
    scanf("%d", &n);

    int arr[n], rotated[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read k
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    // Copy last k elements to beginning
    for(int i = 0; i < k; i++) {
        rotated[i] = arr[n - k + i];
    }

    // Copy remaining elements
    for(int i = k; i < n; i++) {
        rotated[i] = arr[i - k];
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}