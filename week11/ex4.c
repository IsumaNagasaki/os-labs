#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
    char * source_file_name = "ex1.txt";
    char * dest_file_name = "ex1.memcpy.txt";
    int source_file = open(source_file_name, O_RDWR |  O_CREAT, (mode_t)0600);
    int dest_file = open(dest_file_name, O_RDWR |  O_CREAT, (mode_t)0600);

    struct stat st;
    stat(source_file_name, &st);
    size_t source_size = st.st_size;

    ftruncate(dest_file, source_size);

    char *source_map = mmap(0, source_size, PROT_READ, MAP_SHARED, source_file, 0);
    char *dest_map = mmap(0, source_size, PROT_WRITE, MAP_SHARED, dest_file, 0);
    memcpy(dest_map, source_map, source_size);

    close(source_file);
    close(dest_file);

    return 0;
}