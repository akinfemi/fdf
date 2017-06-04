/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:36:55 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/03 21:35:01 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw(t_env *e)
{
	t_file      *f;
	int         i;
	int         len;
	t_points    **map;
	int		    off[2];

	f = e->file;
	i = -1;
	len = f->width * f->height;
	map = f->points;
	off[0] = (e->scale < 2) ? (e->win_width / 2) - (f->width * 50 / 2) : 100;
	off[1] = (e->scale < 2) ? (e->win_height / 2) - (f->height * 50 / 2) : 100;
	while (++i < len - 1)
	{
		if ((i + 1) % f->width != 0)
			draw_line(e, map[i]->x + 100, map[i]->y + 100,
					  map[i+1]->x + 100, map[i+1]->y + 100);
	}
	i = -1;
	while (++i < len - f->width)
	{
		draw_line(e, map[i]->x + 100, map[i]->y + 100,
				  map[i+f->width]->x + 100, map[i+f->width]->y + 100);
	}
}

//void	draw(t_env *e)
//{
//	t_file		*f;
//	int			i;
//	int			len;
//	t_points	**map;
//
//	f = e->file;
//	i = -1;
//	len = f->width * f->height;
//	map = f->points;
//	while (++i < len - 1)
//	{
//		if ((i + 1) % f->width != 0)
//			draw_line(e, map[i], map[i + 1]);
//	}
//	i = -1;
//	while (++i < len - f->width)
//		draw_line(e, map[i], map[i + f->width]);
//}

//void	draw_line(t_env *e, t_points *a, t_points *b)
//{
//	int		arr[6];
//
//	arr[0] = abs(b->x - a->x);
//	arr[1] = a->x < b->x ? 1 : -1;
//	arr[2] = abs(b->y - a->y);
//	arr[3] = a->y < b->y ? 1 : -1;
//	arr[4] = (arr[0] > arr[2] ? arr[0] : -arr[2]) / 2;
//	while (1)
//	{
//		mlx_pixel_put(e->mlx, e->win, a->x + 100, a->y + 100, 0x008000);
//		if (a->x == b->x && a->y == b->y)
//			break ;
//		arr[5] = arr[4];
//		if (arr[5] > -arr[0])
//		{
//			arr[4] -= arr[2];
//			a->x += arr[1];
//		}
//		if (arr[5] < arr[2])
//		{
//			arr[4] += arr[0];
//			a->y += arr[3];
//		}
//	}
//}

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
