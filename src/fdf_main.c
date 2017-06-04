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

	e = (t_env *)malloc(sizeof(t_env));
	f = (t_file *)malloc(sizeof(t_file));
    printf("alloc\n");
	if (usage(ac, ag) || open(ag[1], O_RDONLY) < 0)
		return (0);
	e->mlx = mlx_init();
    printf("mlx_init\n");
    if(!(file_init(&f, ag[1])))
        return (0);
    printf("file_init\n");
	e->file = f;
    e->win_height = (f->height < 100) ? f->height * 100 : f->height * 50;
    e->win_width = (f->width < 100) ? f->width * 100 : f->width * 50;
	e->win = mlx_new_window(e->mlx, e->win_width, e->win_height, "F.D.F");
	draw(e);
	mlx_key_hook(e->win, keyboard_hook, &e);
	mlx_loop(e->mlx);
	return (0);
}
