#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *arr, int n, int max) {

    int *sorted = malloc(sizeof(int)*n);
    int *count = calloc(sizeof(int), max+1);

    for(int i=0; i<n; i++) {
        count[arr[i]] += 1;
    }

    for(int i=1; i<=max; i++) {
        count[i] += count[i-1];
    }

    for(int i=0; i<n; i++) {
        sorted[count[arr[i]]-1] = arr[i];
        count[arr[i]] -= 1;
    }

    memcpy(arr, sorted, n*sizeof(int));
    free(sorted);
    free(count);
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;

    printf("Sorted: \n");
    sort(arr, 5, 9);

    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}