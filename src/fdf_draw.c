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
	int		i;
	int		len;

	f = e->file;
	i = 0;
	len = f->width * f->height;
	while (i < len - 1)
	{
		draw_line(e, to_x(i, f->width) * 10 + 100, to_y(i, f->width) * 10 + 100,
                  to_x(i+1, f->width) * 10 + 100, to_y(i+1, f->width) * 10 + 100);
		i++;
	}
	i = 0;
	while (i < len - f->width)
	{
		draw_line(e, to_x(i, f->width) * 10 + 100, to_y(i, f->width) * 10 + 100,
                  to_x(i+f->width, f->width) * 10 + 100, to_y(i+f->width, f->width) * 10 + 100);
		i++;
	}
}
