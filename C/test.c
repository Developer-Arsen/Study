#include <stdio.h>
#include <stdlib.h>

int main() {
    long count = 100000000;
    long *arr = malloc(count * sizeof(long));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (long i = 0; i < count; ++i) {
        arr[i] = i;  // Initialize array elements
        printf("%ld ", arr[i]);
    }

    free(arr);  // Free allocated memory
    return 0;
}
