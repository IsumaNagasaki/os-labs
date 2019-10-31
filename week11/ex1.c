#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(void)
{
    int text_file = open("ex1.txt", O_RDWR, (mode_t)0600);

    const char *text = "This is a nice day";
    size_t textsize = strlen(text) + 1;

    lseek(text_file, textsize - 1, SEEK_SET);
    write(text_file, "", 1);

    char *map = mmap(0, textsize, PROT_READ | PROT_WRITE, MAP_SHARED, text_file, 0);

    memcpy(map, text, strlen(text));
    msync(map, textsize, MS_SYNC);
    munmap(map, textsize);

    close(text_file);

    return 0;
}
