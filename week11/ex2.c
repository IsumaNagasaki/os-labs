#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define N_CHARS 100

int main()
{
    size_t buf_size = sizeof(char) * N_CHARS;
    char *buf = malloc(buf_size);
    setvbuf(stdout, buf, _IOLBF, buf_size);

    char hello_str[] = "Hello";

    for (int i = 0; i < strlen(hello_str); i++)
    {
        printf("%c", hello_str[i]);
        sleep(1);
    }

    printf("\n");

    free(buf);
}