/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 17:47:32 by dhorker           #+#    #+#             */
/*   Updated: 2019/03/12 18:52:41 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("test1", O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	close(fd1);
	fd1 = open("test1", O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);
	return (0);
}
