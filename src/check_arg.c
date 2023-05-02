/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:08:24 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 01:38:59 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_duplicate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ps_atoi(argv[i]) == ps_atoi(argv[j]))
				ft_error(DUPLICATION_ERR);
			j++;
		}
		i++;
	}
	return ;
}

void	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][0] == '-')
				j++;
			else if ('0' <= argv[i][j] && argv[i][j] <= '9')
				j++;
			else
				ft_error(OUTOFARGRANGE_ERR);
		}
		i++;
	}
	i = 1;
	return ;
}
