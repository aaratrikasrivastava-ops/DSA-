#include <stdio.h>
#define MAX 1000
int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;
    int sum[MAX * 2];
    int index[MAX * 2];
    int size = 0;
    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];
        if(prefixSum == 0) {
            maxLen = i + 1;
        }

        int found = -1;
        for(int j = 0; j < size; j++) {
            if(sum[j] == prefixSum) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            int length = i - index[found];
            if(length > maxLen) {
                maxLen = length;
            }
        } else {
            sum[size] = prefixSum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}