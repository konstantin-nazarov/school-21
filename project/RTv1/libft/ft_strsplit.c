/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:23:32 by krakharo          #+#    #+#             */
/*   Updated: 2018/11/23 15:23:33 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c)
{
	int		count;
	int		i;
	int		word;

	count = 0;
	i = 0;
	word = 0;
	if (s)
		while (*s)
			if (*s++ != c)
			{
				while (*s && *s != c)
					s++;
				count++;
			}
	return (count);
}

static char		*ft_get_word(char const *s, char c)
{
	char	*res;
	int		i;
	int		len;
	int		j;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
		len = len + 1 + (i++) * 0;
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	j = 0;
	while (j < len)
	{
		res[j] = s[j];
		j++;
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	int		count;
	int		word;

	res = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1));
	if (!res || !s || !(res[ft_word_count(s, c)] = (char*)malloc(sizeof(char))))
		return (NULL);
	i = -1;
	word = 0;
	count = 0;
	while (s[++i] != '\0')
		if (s[i] != c && word == 0 && (word = 1))
		{
			res[count] = ft_get_word(s + i, c);
			while (s[i] != c && s[i] != '\0')
				i++;
			count = count + 1 + (i--) * 0;
		}
		else if (s[i] == c)
			word = 0;
	res[ft_word_count(s, c)] = (char*)'\0';
	return (res);
}
