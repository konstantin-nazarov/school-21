/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linelen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:38:09 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 16:38:10 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_linelen(char *buf, int k)
{
	int	len;

	len = 0;
	while (buf[k] != '\n' && buf[k] != '\0')
	{
		k++;
		len++;
	}
	return (++len);
}
