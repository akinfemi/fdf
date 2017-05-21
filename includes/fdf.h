/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:32:46 by aakin-al          #+#    #+#             */
/*   Updated: 2017/05/21 00:12:30 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdio.h>
#include <libft.h>
#include <stdlib.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

int					keyboard_hook(int keycode, t_env *e);
//int					mouse_hook(int button, int x, int y, t_env *e);

#endif
