/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:30:38 by krakharo          #+#    #+#             */
/*   Updated: 2019/07/06 19:09:49 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rtv1.h"

int			ft_start(char *s, int *fd)
{
	char	*tmp;

	if (BUFF_SIZE < 1)
	{
		ft_putendl("ERROR: BUFF_SIZE must be greater than 0");
		return (-1);
	}
	if ((*fd = open(s, O_RDONLY)) == -1)
	{
		tmp = ft_strjoinl("ERROR: ", strerror(errno), 'N');
		ft_putendl(tmp);
		free(tmp);
		return (-1);
	}
	return (1);
}

char		*ft_getbuf(char *s, int *nbl)
{
	int		fd;
	char	*buf;
	char	*line;

	buf = ft_strnew(0);
	if (ft_start(s, &fd) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0 && (*nbl)++ > -1)
		buf = ft_strjoinl(buf, ft_strjoinl(line, "\n", 'L'), 'B');
	if (close(fd) == -1)
	{
		line = ft_strjoinl("ERROR: ", strerror(errno), 'N');
		ft_putendl(line);
		free(line);
		return (NULL);
	}
	if (ft_check_buf(buf) == NULL)
	{
		free(buf);
		ft_pe("ERROR: Scene descriptor incorrect or incomplete");
		return (NULL);
	}
	buf = sort_stage_one(buf);
	return (buf);
}

char		**ft_getscene(char *buf, int nbl, int j)
{
	int		i;
	int		k;
	char	**scene;

	k = 0;
	if (!buf)
		return (NULL);
	if (!(scene = (char **)malloc(sizeof(char *) * (nbl + 1))))
		return (NULL);
	while (buf[k] != '\0' && j < nbl)
	{
		i = 0;
		if (!(scene[j] = (char *)malloc(sizeof(char) * \
				(ft_linelen(buf, k) + 1))))
			return (NULL);
		while (buf[k] != '\n' && buf[k] != '\0')
			scene[j][i++] = buf[k++];
		scene[j][i] = '\0';
		k++;
		j++;
	}
	free(buf);
	return (scene);
}

void		ft_init_control(t_mlx *mlx)
{
	mlx_mouse_hook(mlx->win, ft_mouse, mlx);
	mlx_hook(mlx->win, 17, (1L << 17), close_hook, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_hook, mlx);
}

int			ft_init(t_mlx *mlx, char *s)
{
	char	*buf;

	mlx->mlx = mlx_init();
	mlx->img = mlx_new_image(mlx->mlx, WIN_W, WIN_H);
	mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "Project: RTv1");
	mlx->d = mlx_get_data_addr(mlx->img, &mlx->bpp, \
								&mlx->size_line, &mlx->endian);
	mlx->nbl = 0;
	if ((buf = ft_getbuf(s, &(mlx->nbl))) == NULL)
		return (ft_free_arg(mlx, buf, 0));
	if ((mlx->scene = ft_getscene(buf, mlx->nbl, 0)) == NULL)
		return (ft_free_arg(mlx, NULL, 1));
	ft_init_mlx_var(mlx);
	if (ft_pars(mlx) == -1)
		return (ft_free_arg(mlx, NULL, 2));
	ft_init_control(mlx);
	return (0);
}
