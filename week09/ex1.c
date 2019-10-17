#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_smallest_ind(char *arr, int size)
{
    int smallest_ind = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < arr[smallest_ind])
        {
            smallest_ind = i;
        }
    }
    return smallest_ind;
}

int get_ind(int *arr, int size, int ell)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ell)
        {
            return i;
        }
    }
    return -1;
}

void main(int argc, char **argv)
{
    int frame_count = atoi(argv[1]);

    FILE *f = fopen("input.txt", "r");

    int page;
    int res_code = fscanf(f, "%d", &page);

    int ram_arr_size = frame_count * sizeof(int);
    int *ram = malloc(ram_arr_size);
    memset(ram, -1, frame_count * sizeof(int));

    unsigned char *page_counter = calloc(frame_count, sizeof(char));

    int n_miss = 0;
    int n_hit = 0;

    while (res_code != EOF)
    {
        int page_ind = get_ind(ram, frame_count, page);
        for (int i = 0; i < frame_count; i++)
            page_counter[i] >>= 1; //decrement all
        if (page_ind >= 0)
        {
            page_counter[page_ind] = page_counter[page_ind] | (1 << 7); //increment if found
            n_hit++;
        }
        else
        {
            int new_page_ind = get_smallest_ind(page_counter, frame_count);
            page_counter[new_page_ind] = 1 << 7;
            ram[new_page_ind] = page;
            n_miss++;
        }
        res_code = fscanf(f, "%d", &page);
    }

    if (n_miss > 0)
    {
        printf("Hit to miss ratio: %f\n", (float)n_hit / (float)n_miss);
    }
    else
    {
        printf("Error: miss = 0\n");
    }

    free(ram);
    free(page_counter);
    fclose(f);
}