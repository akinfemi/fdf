/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 23:49:50 by aakin-al          #+#    #+#             */
/*   Updated: 2017/06/03 21:43:41 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				usage(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" <filename>");
		return (1);
	}
	return (0);
}

int				keyboard_hook(int keycode, t_env *e)
{
	if (!(e->win))
		return (0);
	if (keycode == 53)
		exit(0);
	return (0);
}

static int		*ft_toint(char *str, int width)
{
	int		len;
	int		*res;
	int		j;

	len = ft_strlen(str);
	j = 0;
	res = (int *)malloc(sizeof(int) * (width) + 1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9')
				&& *str != ' ' && *str != '\n' && *str != '\0')
			exit(0);
		if (*str >= '0' && *str <= '9')
		{
			res[j] = ft_atoi(str);
			while (*str >= '0' && *str <= '9')
				str++;
			j++;
		}
		else
			str++;
	}
	return (res);
}

static int		num_count(char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			count++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
		else
			str++;
	}
	return (count);
}

int				file_init(t_file **file, char *path)
{
	int		arr[2];
	char	*buf;
	t_file	*f;

	f = *file;
	arr[0] = open(path, O_RDONLY);
	if (arr[0] > 0 && get_next_line(arr[0], &buf) != 0)
		f->width = num_count(buf);
	else
		return (0);
	f->height = 1;
	while (get_next_line(arr[0], &buf))
		f->height++;
	f->coords = (int **)malloc(sizeof(int *) * (f->height + 1));
	close(arr[0]);
	arr[0] = open(path, O_RDONLY);
	arr[1] = -1;
	while (++arr[1] < f->height)
	{
		get_next_line(arr[0], &buf);
		f->coords[arr[1]] = ft_toint(buf, f->width);
	}
	close(arr[0]);
	f->points = make_map(f->coords, f->width, f->height);
	return (1);
}
