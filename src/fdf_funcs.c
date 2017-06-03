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

int			*ft_toint(char *str)
{
	int		len;
	int		i;
	int		*res;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	res = (int *)ft_memalloc(sizeof(int) * (len / 2 + 1) + 1);
	while (i < len)
	{
		res[j] = ft_atoi(str + i);
		i+=2;
		j++;
	}
	return (res);
}

void		file_init(t_file **file, char *path)
{
	int		fd;
	char 	*buf;
	int		i;
	t_file	*f;

	f = *file;
	fd = open(path, O_RDONLY);
	f->height = 0;
	i = 0;
	while (get_next_line(fd, &buf))
	{
		free(buf);
		f->height++;
	}
	f->coords = (int **)ft_memalloc(sizeof(int *) * (f->height + 1));
	close(fd);
	fd = open(path, O_RDONLY);
	while (i < f->height)
	{
		get_next_line(fd, &buf);
		f->coords[i] = ft_toint(buf);
		free(buf);
		i++;
	}
	f->width = f->height; //check if this is a valid assumption
	close (fd);
	test_print_map(f->coords, f->height);
}

void		draw_line (t_env *e, int x0, int y0, int x1, int y1)
{
	int dx;
	int	sx;
	int dy; 
	int err;
	int	e2;
	int sy;

	printf("x: %d, y: %d, x2: %d, y2: %d\n", x0,y0,x1,y1);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs (y1 - y0);
	dx =  abs (x1 - x0);
	sy = y0 < y1 ? 1 : -1; 
	err = dx + dy;
	while (!((x0 == x1) && (y0 == y1)))
	{  
		mlx_pixel_put(e->mlx, e->win, x0, y0, 0x008000);
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		} 
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
