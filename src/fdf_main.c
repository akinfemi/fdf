/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:31:52 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/23 15:09:23 by aakin-al         ###   ########.fr       */
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
	e->win = mlx_new_window(e->mlx, f->width * 100, f->height*100, "Title");
	mlx_expose_hook(e->win, expose_hook, &e);	
	mlx_key_hook(e->win, keyboard_hook, &e);
	mlx_loop(e->mlx);

//	free(e);
	return (0);
}
