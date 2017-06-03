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

void	draw(t_env *e, int start_x, int start_y)
{
	t_file	*f;
	int		x;
	int		y;

	f = e->file;
	x = 0;
	y = 0;
	while (x < f->width-1)
	{
		while (y < f->height-1)
		{
			if (f->coords[x][y] == 0)
				draw_line(e, start_x + (x * 10), start_y, start_x, start_y+(y+1)*10);
			else
				draw_line(e, start_x + (x * 10), start_y, start_x, start_y+(y+1)*10);
				//draw_line(e, 100 + (x * 10), 100 + (y * 10), 100+(x+1)*10, 100+(y+1)*10);
			y++;
		}
		x++;
	}
}
