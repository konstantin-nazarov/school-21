/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorker <dhorker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:00:40 by dhorker           #+#    #+#             */
/*   Updated: 2019/06/08 18:34:54 by dhorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

/*
** Check
*/

int	check_sort(int *check);
int	*check_valid(int av, char **ac);
int	*valid_supp(int av, char **ac, int *check, int count);
int	*new_elem(int *old, int num, int size);
int	digit_number(int result);

#endif
