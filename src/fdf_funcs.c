/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 23:49:50 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/25 14:12:14 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fdf.h>

int			usage(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" <filename>");
		return (1);
	}
	return (0);
}

int			keyboard_hook(int keycode, t_env *e)
{
	if (!(e->win))
		return (0);
	if (keycode == 53)
		exit(0);
	return (0);
}

int			*ft_toint(char *str, int width)
{
	int		len;
	int		*res;
	int		j;

	len = ft_strlen(str);
	j = 0;
	res = (int *)malloc(sizeof(int) * (width) + 1);
	while (*str)
	{
        if (!(*str >= '0' && *str <= '9') && *str != ' ' && *str != '\n' && *str != '\0')
            exit(0);
		if (*str >= '0' && *str <= '9')
		{
			res[j] = ft_atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
			j++;
		}
		else
			str++;
	}
	return (res);
}

static int         num_count(char  *str)
{
    int     count;

    count = 0;
    while (*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            count++;
            while (*str >= '0' && *str <= '9')
                str++;
        }
        else
            str++;
    }
    return (count);
}


int		file_init(t_file **file, char *path)
{
	int		fd;
	char 	*buf;
	int		i;
	t_file	*f;

	f = *file;
	fd = open(path, O_RDONLY);
	f->height = 1;
	i = 0;
    if(fd > 0 && get_next_line(fd, &buf) != 0)
        f->width = num_count(buf);
    else
        return (0);
	while (get_next_line(fd, &buf))
		f->height++;
	f->coords = (int **)malloc(sizeof(int *) * (f->height + 1));
	fd = open(path, O_RDONLY);
	while (i < f->height)
	{
		get_next_line(fd, &buf);
		f->coords[i] = ft_toint(buf, f->width);
        i++;
	}
	close (fd);
//	print_coords(f->coords, f->width, f->height);
	f->points = make_map(f->coords, f->width, f->height);
    return (1);
}

void draw_line(t_env *e, int x0, int y0, int x1, int y1) {

    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    while (1){
        mlx_pixel_put(e->mlx, e->win, x0, y0, 0x008000);
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}