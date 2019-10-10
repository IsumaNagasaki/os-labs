#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

void main()
{
    void* pointers [10];
    for (int i = 0; i < 10; i++)
    {
        int size = pow(2, 20) * 10;
        pointers[i] = malloc(size);
        memset(pointers[i], 0, size);
        sleep(1);
    }
    for (int i = 0; i < 10; i++)
    {
        free(pointers[i]);
    }
}