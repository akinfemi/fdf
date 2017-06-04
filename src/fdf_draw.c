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
//
//int		to_x(int nb, int width)
//{
//	return ((nb >= width) ? nb / width : 0);
//}
//
//int		to_y(int nb, int width)
//{
//	return ((nb < width) ? nb : nb % width);
//}

void	draw(t_env *e)
{
	t_file	*f;
	int		i;
	int		len;
    t_points    **map;
	int		offset;

	f = e->file;
	i = 0;
	len = f->width * f->height;
    map = f->points;
	offset = (f->width * 80 / 2) - (f->width * 50 / 2);
    while (i < len - 1)
	{
        if ((i + 1) % f->width != 0)
            draw_line(e, map[i]->x + offset, map[i]->y + offset,
                  map[i+1]->x + offset, map[i+1]->y + offset);
		i++;
	}
    i = 0;
    while (i < len - f->width)
    {
        draw_line(e, map[i]->x + offset, map[i]->y + offset,
                  map[i+f->width]->x + offset, map[i+f->width]->y + offset);
        i++;
    }
}
