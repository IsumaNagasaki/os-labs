#include <stdio.h>
#include <stdlib.h>

#include <string.h>

/* maximum size of an input line : adapt to your needs */
#define SIZE 256
#define MAX_RESOURCES 10

void main()
{
    char line[SIZE];
    int existingRes[MAX_RESOURCES];
    int availableRes[MAX_RESOURCES];
    int ** allocationMatrix;
    int ** requestMatrix;
    int matrix_size = 0;

    fgets(line, SIZE, stdin);
    readIntsInLine(line, existingRes);

    fgets(line, SIZE, stdin);

    fgets(line, SIZE, stdin);
    readIntsInLine(line, availableRes);

    fgets(line, SIZE, stdin);


}

int readMatrix(int ** matrix, int row_length){
    int matrix_height = 0;
    int i = 0;

    matrix = malloc((++matrix_height)*sizeof(int*));
    char line[SIZE];

    matrix[i] = malloc(MAX_RESOURCES * sizeof(int));

    fgets(line, SIZE, stdin);
    readIntsInLine(line, matrix[i]);
}

int readIntsInLine(char * line, int nums[]){
    char line[SIZE], *val;
    char delims[] = " \t\r\n";

    val = strtok(line, delims);
    int i = 0;

    int valsRead = sscanf(val, "%d", &nums[i]);

    if(valsRead <= 0) return 0;

    
    while(valsRead>0)
    {
        val = strtok(NULL, delims);
        valsRead = (val == NULL) ? 0 : sscanf(val, "%d", &nums[++i]);
    }
    
    return 1;
}

void vecSub(int v1[], int v2[], int size){
    for(int i = 0; i < size; i++){
        v1[i] -= v2[i];
    }
}

void vecAdd(int v1[], int v2[], int size){
    for(int i = 0; i < size; i++){
        v1[i] += v2[i];
    }
}

int vecLessEqual(int v1[], int v2[], int size){
    for(int i = 0; i < size; i++){
        if(v1[i] > v2[i]) return 0;
    }
    return 1;
}