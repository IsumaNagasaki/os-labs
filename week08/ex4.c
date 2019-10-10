#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

void main()
{
    void *pointers[10];
    struct rusage usage;
    
    for (int i = 0; i < 10; i++)
    {
        int size = pow(2, 20) * 10;
        pointers[i] = malloc(size);
        memset(pointers[i], 0, size);
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory: %ld\n", usage.ru_maxrss);
        sleep(1);
    }
    for (int i = 0; i < 10; i++)
    {
        free(pointers[i]);
    }
}