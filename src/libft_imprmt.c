/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_imprmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:51:35 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/17 15:01:03 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ps_atoi(const char *str)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || ('\t' <= str[i] && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	res *= neg;
	if (res < INT_MIN || INT_MAX < res)
		ft_error(OUTOFINTRANGE_ERR);
	return ((int)(res));
}
