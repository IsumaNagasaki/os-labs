#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NAME_MAX 255

int main(int argc, char const *argv[])
{
    char *directory = "tmp";
    size_t directory_length = strlen(directory);
    char *path = malloc(directory_length + 1 + NAME_MAX);
    strcpy(path, directory);
    path[directory_length] = '/';
    DIR *dirp = opendir(directory);
    if (dirp == 0)
    {
        return (1);
    }

    struct dirent *dp = malloc(sizeof(struct dirent));
    struct stat *st = malloc(sizeof(struct stat));
    __ino_t *search_files = NULL;
    int i = 0;
    while ((dp = readdir(dirp)) != NULL)
    {
        int found = 0;
        for (int j = 0; j < i; j++)
        {
            if (search_files[j] == dp->d_ino)
            {
                found = 1;
                printf("%s\n", dp->d_name);
                break;
            }
        }
        if (found)
            continue;
        strcpy(path + directory_length + 1, dp->d_name);
        int success = stat(path, st);
        if (st->st_nlink >= 2)
        {
            search_files = realloc(search_files, (i + 1) * sizeof(__ino_t));
            search_files[i++] = dp->d_ino;
            printf("%s\n", dp->d_name);
        }
    }

    (void)closedir(dirp);
}
