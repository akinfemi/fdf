/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:36:55 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/04 00:46:23 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#define BREAK(a) if(1){if(a){break;};}

void	draw(t_env *e)
{
	t_file		*f;
	int			i;
	int			len;
	t_points	**map;

	f = e->file;
	i = -1;
	len = f->width * f->height;
	map = f->points;
	while (++i < len - 1)
	{
		if ((i + 1) % f->width != 0)
			draw_line(e, *map[i], *map[i + 1]);
	}
	i = -1;
	while (++i < len - f->width)
		draw_line(e, *map[i], *map[i + f->width]);
}

void	draw_line(t_env *env, t_points src0, t_points src1)
{
	t_points	d;
	t_points	inc;
	int			err[2];

	d.x = abs(src1.x - src0.x);
	d.y = -abs(src1.y - src0.y);
	inc.x = (src0.x < src1.x) ? 1 : -1;
	inc.y = (src0.y < src1.y) ? 1 : -1;
	err[0] = d.x + d.y;
	while (1)
	{
		mlx_pixel_put(env->mlx, env->win, src0.x + 100, src0.y + 100, 0x008000);
		BREAK(src0.x == src1.x && src0.y == src1.y);
		err[1] = 2 * err[0];
		if (err[1] >= d.y)
		{
			err[0] += d.y;
			src0.x += inc.x;
		}
		if (err[1] <= d.x)
		{
			err[0] += d.x;
			src0.y += inc.y;
		}
	}
}
