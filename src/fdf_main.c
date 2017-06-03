/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:31:52 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/25 13:36:36 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int main(int ac, char **ag)
{
	t_env	*e;
	t_file	*f;

	e = (t_env *)malloc(sizeof(t_env *));
	f = (t_file *)malloc(sizeof(t_file *));
	if (usage(ac, ag))
		return (0);
	e->mlx = mlx_init();
	file_init(&f, ag[1]);
	printf("After\n");
	e->file = f;
	e->win = mlx_new_window(e->mlx, f->width * 100, f->height*100, "Title");
//	draw(e, 100, 100);
	/*where x,y starting are coords*/
/*	plot_line(e, 100, 100, 300, 300);
	plot_line(e, 200, 10, 10, 200);*/
	mlx_key_hook(e->win, keyboard_hook, &e);
	mlx_loop(e->mlx);

//	free(e);
	return (0);
}
