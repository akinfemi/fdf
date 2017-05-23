/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 23:49:50 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/23 15:10:45 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	f->coords = (char **)ft_memalloc(sizeof(char *) * (f->height + 1));
	close(fd);
	fd = open(path, O_RDONLY);
	while (i < f->height)
	{
		get_next_line(fd, &buf);
		f->coords[i] = ft_strdup(buf);
		free(buf);
		i++;
	}
	f->width = ft_strlen(f->coords[0]); //note spaces and new line
	close (fd);
}

void		draw_line(t_env *e, int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		e;
	int		s;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	e = (dx > dy ? dx : -dy) / 2;
	while (x0 <= x2 - 1)
	{
		mlx_pixel_put(e->mlx, e->win, x0, y0, 0xFFFFFF);
		if (e >= 0)
		{
			y0++;;
			e -= dx;
		}
		x0++;
		e += dy;
	}
}

int			expose_hook(int keycode, t_env *e)
{
	//
}
