/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:48:04 by dhorker           #+#    #+#             */
/*   Updated: 2018/11/27 22:16:15 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i + 1] && !s2[i + 1])
			return (0);
		i++;
	}
	if (s1[i] > s2[i])
		return (1);
	return (-1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

int		main(int ac, char **av)
{
	int		i;
	int		min;
	char	*swp;

	i = 0;
	min = 1;
	while (++i <= ac - 1 && min != ac - 1)
	{
		if (0 > ft_strcmp(*(av + i), *(av + min)))
		{
			swp = *(av + i);
			*(av + i) = *(av + min);
			*(av + min) = swp;
		}
		if (i == ac - 1 && min != ac - 1)
			i = min++;
	}
	i = 0;
	while (++i <= ac - 1)
	{
		ft_putstr(*(av + i));
		ft_putchar('\n');
	}
}
