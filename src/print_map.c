//
// Created by Akinfemi Akin-Aluko on 6/2/17.
//
#include <fdf.h>
void        test_print_map(int **map, int size)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    printf("Size:%d\n", size);
    while (i < size)
    {
        while (j < size)
        {
            printf("% d",(map[i][j]));
            j++;
        }
        printf("\n");
        i++;
        j = 0;
    }
}