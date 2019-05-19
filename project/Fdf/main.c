/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolemon <ccolemon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:21:14 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/09 17:47:01 by ccolemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void			create_map(t_system win, t_fdf *map)
{
	float		rad;

	rad = 3.1415926535 / 180;
	map->tx = -(0 * rad);
	map->ty = -(0 * rad);
	map->tz = -(0 * rad);
	map->gap = (P_W - 500) / (map->x - 1);
	if (map->gap > (P_H - 100) / (map->y - 1))
		map->gap = (P_H - 100) / (map->y - 1);
	map->sx = win.x / 2 - (map->gap * (map->x - 1) / 2) + 200;
	map->sy = win.y / 2 - (map->gap * (map->y - 1) / 2);
}

int				fdf(t_system *w, t_fdf *map, t_inp *inp)
{
	inp->point = fill(map, -1);
	w->bit = 32;
	w->endian = 0;
	w->size_l = P_W;
	w->img = mlx_new_image(w->mlx, w->size_l, P_H);
	w->rem_i = mlx_get_data_addr(w->img, &w->bit, &w->size_l, &w->endian);
	create_grid(w, map, inp->point, 0);
	return (0);
}

int				calc(int fd, t_fdf *map, int check)
{
	char		*line;
	char		*tmp;

	map->y = 0;
	if ((check = get_next_line(fd, &map->mtx)) == 1)
		map->x = ft_countwords(map->mtx, ' ');
	else
		F_ERR("ERROR: invalid file\n", -1, 0, 0, 0);
	while ((++map->y) && (check = get_next_line(fd, &line)) == 1)
	{
		tmp = map->mtx;
		map->mtx = ft_strjoin_space(map->mtx, line);
		if (map->x != (ft_countwords(line, ' ')))
			F_ERR("ERROR: invalid matrix\n", -1, map->mtx, line, tmp);
		F_FREE(line, tmp, 0);
	}
	if (valid(*map, 0, 0))
		F_ERR("ERROR: invalid matrix\n", -1, map->mtx, 0, 0);
	if (check != 0)
		F_ERR("ERROR: problem reader file\n", -1, map->mtx, line, 0);
	return (check);
}

int				main(int fd, char **av)
{
	t_system	win;
	t_fdf		map;
	t_inp		inp;

	if (fd != 2)
		USAGE;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		MESSAGE_ERR;
	CHECK_ERROR(calc(fd, &map, 0));
	ft_bzero(&inp, sizeof(inp));
	inp.map = &map;
	inp.win = &win;
	win.x = P_W;
	win.y = P_H;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.x, win.y, "fdf");
	create_map(win, &map);
	fdf(&win, &map, &inp);
	mlx_hook(win.win, 2, 0, key_press, &inp);
	mlx_hook(win.win, 4, 0, mouse_press, &inp);
	mlx_hook(win.win, 5, 0, mouse_unpress, &inp);
	mlx_hook(win.win, 6, 0, move_map, &inp);
	mlx_hook(win.win, 17, 0, ft_close, 0);
	mlx_loop(win.mlx);
	return (0);
}
