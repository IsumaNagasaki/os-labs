#include <stdio.h>

int main()
{
    char str[20];
    FILE *fp;
    char *filename = "/dev/random";
    fp = fopen(filename, "r");
    
    FILE *ans = fopen("ex1.txt", "w");

    for (int i = 0; i < 20; i++){
        fputc(fgetc(fp),ans);
    }


    fclose(fp);
    fclose(ans);
    return 0;
}