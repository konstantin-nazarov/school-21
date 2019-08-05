/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_func.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krakharo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:24:24 by krakharo          #+#    #+#             */
/*   Updated: 2019/06/17 17:24:26 by krakharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELP_FUNC_H
# define FT_HELP_FUNC_H
# define BUFF_SIZE 100

int			ft_atoin(char *str, int *k);
char		*ft_strjoin(char *s1, char *s2, char type);
int			get_next_line(int const fd, char **line);
char		*ft_ftoa(double nb);
double		ft_clamp(double value, double min, double max);
void		ft_fzero(double *s, int n);
char		*ft_strjoinl(char *s1, char *s2, char type);
char		*ft_check_buf(char *scn);
void		ft_pe(char *err);

#endif
