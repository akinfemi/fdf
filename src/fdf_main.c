/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:31:52 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/03 21:44:41 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int		main(int ac, char **ag)
{
	t_env	*e;
	t_file	*f;
	int		fd;

	e = (t_env *)malloc(sizeof(t_env));
	f = (t_file *)malloc(sizeof(t_file));
	fd = open(ag[1], O_RDONLY);
	if (usage(ac, ag) || fd < 0)
		return (0);
	e->mlx = mlx_init();
	if (!(file_init(&f, ag[1])))
		return (0);
	e->file = f;
	e->win_height = 1000;
	e->win_width = 2000;
	e->scale = (f->width > 60) ? 1 : 2;
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "F.D.F");
	draw(e);
	mlx_key_hook(e->win, keyboard_hook, &e);
	mlx_loop(e->mlx);
	return (0);
}
