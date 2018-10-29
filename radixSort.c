#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int *arr, int n, int max, int exp) {

    int *sorted = malloc(sizeof(int)*n);
    int *count = calloc(sizeof(int), max+1);

    for(int i=0; i<n; i++) {
        count[(arr[i]/exp)%10] += 1;
    }

    for(int i=1; i<=max; i++) {
        count[i] += count[i-1];
    }

    for(int i=0; i<n; i++) {
        sorted[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10] -= 1;
    }

    memcpy(arr, sorted, n*sizeof(int));
    free(sorted);
    free(count);
}

int getMax(int *arr, int n){

    int max = arr[0];
    for(int i=1;i<n;i++) {
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void sort(int *arr, int n, int max) {
    
    int mx = getMax(arr, n);

    for(int exp=1 ; mx/exp>0; exp*=10) {
        countingSort(arr, n, max, exp);
    }
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