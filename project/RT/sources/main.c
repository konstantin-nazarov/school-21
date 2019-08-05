/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:39:33 by dhorker           #+#    #+#             */
/*   Updated: 2019/07/28 18:03:19 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define STB_IMAGE_IMPLEMENTATION
#include "headlines.h"
#include "libft.h"

void	create_img(t_scene *scene)
{
	int		x;
	int		y;

	y = -1;
	while (++y < F_H)
	{
		x = -1;
		while (++x < F_W)
		{
			direction_camera(scene, x, y);
			scene->img_rw[y * F_W + x] = ft_vec3_color(ray_trace(*scene));
		}
	}
}

int	main()
{
	t_scene		scene;
	void		*img;
	int			width = 1280;
	int			height = 720;
	int			channels = 3;

	create_scene(&scene);
	stbi_set_flip_vertically_on_load(0);
	// stbi_info("texture/test_1.jpg", &width, &height, &channels);
	// printf("%d - %d - %d", width, height, channels);
	unsigned char *texture = stbi_load("texture/test_1.jpg", &width, &height, &channels, 3);
	// create_img(&scene);
	ft_memcpy(scene.texture, texture, 1280 * 720 * 3);
	mlx_put_image_to_window(scene.mlx, scene.win, scene.img, 0, 0);
	stbi_image_free(texture);
	mlx_hook(scene.win, 2, 0, key_press, &scene);
	mlx_hook(scene.win, 4, 0, mouse_press, &scene);
	mlx_hook(scene.win, 17, 0, ft_close, 0);
	mlx_loop(scene.mlx);
	return (0);
}
