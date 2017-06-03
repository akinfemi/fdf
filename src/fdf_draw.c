/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 13:36:55 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/25 14:08:59 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		to_x(int nb, int width)
{
	return ((nb >= width) ? nb / width : 0);
}

int		to_y(int nb, int width)
{
	return ((nb < width) ? nb : nb % width);
}

void	draw(t_env *e)
{
	t_file	*f;
//	int		x;
//	int		y;
	int		i;
	int		len;

	f = e->file;
//	x = 0;
//	y = 0;
	i = 0;
	len = f->width * f->height;
//	while (x < f->height - 1)
//	{
//		while (y < f->width - 1)
//		{
//			printf("x1:%d,y1:%d,x2:%d,y2%d\n",  conv(x, y, f->width), conv(x, y, f->width), conv(x, y+1, f->width),
//					  conv(x+1, y, f->width));
//			draw_line(e, conv(x, y, f->width) * 10 + 100, conv(x, y, f->width) * 10 + 100, conv(x, y+1, f->width) * 10 + 100,
//					  conv(x+1, y, f->width) * 10 + 100);
//			draw_line(e, conv(x, y, f->width) * 10 + 100, conv(x, y, f->width) * 10 + 100, conv(x+1, y, f->width) * 10 + 100,
//					  conv(x, y+1, f->width) * 10 + 100);
//			y++;
//		}
//		x++;
//	}
	while (i < len - 1)
	{
		draw_line(e, to_x(i, f->width) * 10 + 100, to_y(i, f->width) * 10 + 100, to_x(i+1, f->width) * 10 + 100, to_y(i+1, f->width) * 10 + 100);
		i++;
	}
	i = 0;
	while (i < len - f->width)
	{
		draw_line(e, to_x(i, f->width) * 10 + 100, to_y(i, f->width) * 10 + 100, to_x(i+f->width, f->width) * 10 + 100, to_y(i+f->width, f->width) * 10 + 100);
		i++;
	}
}
