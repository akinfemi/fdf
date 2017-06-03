//
// Created by Akinfemi Akin-Aluko on 6/2/17.
//
#include <fdf.h>

t_points       *new_point(int x, int y, int z)
{
    t_points   *point;

    point = (t_points *)malloc(sizeof(t_points));
    if (!point)
        return (0);
    point->x = x;
    point->y = y;
    point->z = z;
    return (point);
}

int        conv(int i, int j, int width)
{
    return (i * width + j);
}

t_points        **make_map(int **coords, int width, int height)
{
    t_points    **map;
    int         i;
    int         j;

    i = 0;
    j = 0;
    map = (t_points **)malloc(sizeof(t_points *) * (width * height));
    printf("Len: %d\n", width * height);
    while (i < height)
    {
        while (j < width)
        {
            map[conv(i, j, width)] = new_point(i, j, coords[i][j]);
//            printf("Conv: %d\n", conv(i,j,width));
            printf("Map:%d,%d,%d\n", map[conv(i,j,width)]->x, map[conv(i,j,width)]->y, map[conv(i,j,width)]->z);
            j++;
        }
        i++;
        j = 0;
    }
    printf("Done\n");
    return (map);
}
