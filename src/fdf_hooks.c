/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 23:49:50 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/21 00:12:16 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			keyboard_hook(int keycode, t_env *e)
{
	if (e->win)
	{
	//	return (0);
	}
	if (keycode == 53)
		exit(0);
	printf("Key: %d\n", keycode);
	return (0);
}

/*
int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (e->win)
	{
//		return (0);
	}
	printf("Mouse: %d Coord: (%d,%d)\n", button, x, y);
	return (0);
}
*/
