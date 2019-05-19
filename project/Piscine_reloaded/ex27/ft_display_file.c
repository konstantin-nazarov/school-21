/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:57:40 by dhorker           #+#    #+#             */
/*   Updated: 2018/11/27 21:43:17 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		file;
	char	c;

	if (ac == 2)
	{
		file = open(av[1], O_RDONLY);
		if (file < 0)
			return (0);
		while (read(file, &c, 1))
			write(1, &c, 1);
		close(file);
	}
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
		write(2, "File name missing.\n", 19);
	return (0);
}
