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
	off[0] = (e->win_width / 2) - (f->width * 50 / 2);
    off[1] = (e->win_height / 2) - (f->height * 50 / 2);
    while (++i < len - 1)
	{
        if ((i + 1) % f->width != 0)
            draw_line(e, map[i]->x + off[0], map[i]->y + off[1],
                  map[i+1]->x + off[0], map[i+1]->y + off[1]);
	}
    i = -1;
    while (++i < len - f->width)
    {
        draw_line(e, map[i]->x + off[0], map[i]->y + off[1],
                  map[i+f->width]->x + off[0], map[i+f->width]->y + off[1]);
    }
}
