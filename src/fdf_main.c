/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:31:52 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/12 14:43:59 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int main(void)
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");

	mlx_loop(mlx);
	return (0);
}
/*
int main(void)
{
	printf("%s\n", "asd");
	return (0);
}*/
