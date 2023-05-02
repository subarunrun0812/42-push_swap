/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:14:08 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/06 23:02:46 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	radix_sort(t_stack stack_copy)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (i++ < stack_copy.bottom)
	{
		j = -1;
		while (j++ < stack_copy.bottom)
		{
			if (stack_copy.data[i] < stack_copy.data[j])
			{
				tmp = stack_copy.data[i];
				stack_copy.data[i] = stack_copy.data[j];
				stack_copy.data[j] = tmp;
			}
		}
	}
	return (stack_copy);
}

void	coordinate_compression(t_info *info)
{
	info->stack_copy = radix_sort(info->stack_copy);
}
