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
    point->z = z * 7;
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
        tx = sqrt(2) * map[i]->x + sqrt(2) * map[i]->y + sqrt(2) * map[i]->z;
        ty = sqrt(3) * map[i]->x - sqrt(3) * map[i]->z;
        map[i]->y = ty / sqrt(6);
        map[i]->x = tx / sqrt(6);
        i++;
    }
    return (map);
}

t_points        **make_map(int **coords, int width, int height)
{
    t_points    **map;
    int         i;
    int         j;

    i = 0;
    j = 0;
    map = (t_points **)malloc(sizeof(t_points *) * (width * height));
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
    map = iso_map(map, width * height);
    return (map);
}
