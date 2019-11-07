#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a_flag = (argc > 1) && (strcmp(argv[1], "-a") == 0);
    if (!a_flag)
    {
        for (int i = 0; i < argc; i++)
        {
            FILE *fp;
            fp = fopen(argv[i], "w");
            fclose(fp);
        }
    }

    char c = getchar();
    putchar(c);
    while (c != EOF)
    {
        for (int i = a_flag ? 2 : 1; i < argc; i++)
        {
            FILE *fp;
            fp = fopen(argv[i], "a");
            fputc(c, fp);
            fclose(fp);
        }
        c = getchar();
        putchar(c);
    }
}