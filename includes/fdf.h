/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:32:46 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/04 00:50:30 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <libft.h>
# include <stdlib.h>
# include <get_next_line.h>
# include <math.h>

typedef struct		s_points
{
	int				x;
	int				y;
	int				z;
}					t_points;
typedef struct		s_file
{
	int				**coords;
	int				height;
	int				width;
	struct s_points	**points;
}					t_file;
typedef struct		s_env
{
	void			*mlx;
	void			*win;
	struct s_file	*file;
	int				win_width;
	int				win_height;
	int				scale;
}					t_env;
int					usage(int ac, char **ag);
int					keyboard_hook(int keycode, t_env *e);
int					file_init(t_file **file, char *path);
void				draw(t_env *e);
t_points			**make_map(int **coords, int width, int height);
int					conv(int i, int j, int width);
void				draw_line(t_env *env, t_points src0, t_points src1);

#endif
