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
    point->x = x * 50;
    point->y = y * 50;
    point->z = z * 50;
    return (point);
}

int        conv(int i, int j, int width)
{
    return (i * width + j);
}

t_points        **iso_map(t_points **map, int size)
{
    int     i;
    int     tx = 0;
    int     ty = 0;

    i = 0;
    while (i < size)
    {
        ty = map[i]->x + 2 * map[i]->y + map[i]->z;
        tx = sqrt(3) * map[i]->x - sqrt(3) * map[i]->z;
        printf("nx: %d, ny:%d\n", tx, ty);
        map[i]->y = ty / sqrt(6);
        map[i]->x = tx / sqrt(6);
//        map[i]->y = map[i]->x + 2 * map[i]->y + map[i]->z;
//        map[i]->x = sqrt(3) * map[i]->x - sqrt(3) * map[i]->z;
        i++;
    }
    return (map);
}

t_points        **make_map(int **coords, int width, int height)
{
    t_points    **map;
    int         i;
    int         j;
//    t_points    **temp;

    i = 0;
    j = 0;
    map = (t_points **)malloc(sizeof(t_points) * (width * height));
    printf("Len: %d\n", width * height);
    while (i < height)
    {
        while (j < width)
        {
            map[conv(i, j, width)] = new_point(i, j, coords[i][j]);
            j++;
        }
        i++;
        j = 0;
    }
//    temp = map;
    map = iso_map(map, width * height);
//    free (temp);
    return (map);
}
