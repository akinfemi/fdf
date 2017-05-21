/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:31:52 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/21 00:12:36 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int main(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env *));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "Title");
//	mlx_expose_hook(e->win, expose_hook, &e);	
	mlx_key_hook(e->win, keyboard_hook, &e);
	mlx_loop(e->mlx);
	return (0);
}
