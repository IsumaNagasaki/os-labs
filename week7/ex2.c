#include "stdio.h"
#include "stdlib.h"

void main()
{
    printf("Input the array size N: ");

    int n = 0;
    scanf("%d", &n);
    
    int *arr = calloc(n, sizeof(int));

    printf("Array: ");
    for(int i = 0; i < n; i++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}