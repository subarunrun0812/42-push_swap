/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_forty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:58:04 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 00:39:49 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack	tmp_del_stack_copy_ele(t_stack stack_copy, int num)
{
	int	i;

	i = -1;
	while (i++ < stack_copy.bottom - num)
	{
		stack_copy.data[i] = stack_copy.data[i + num];
	}
	stack_copy.bottom -= num;
	return (stack_copy);
}

static void	control_quick_sort(t_info *info)
{
	int	ra_count;

	if (reverse_sort_check(info->stack_b) == 1)
	{
		while (info->stack_b->bottom >= 6)
			tmp_quick_sort_push_b(info);
		if (info->stack_b->bottom < 3)
			less_than_three_ele(info->stack_b->bottom + 2, info, 2);
		else if (info->stack_b->bottom < 6)
			less_than_six_b(info->stack_b->bottom + 2, info, 2);
	}
	if (info->stack_copy.bottom > 0)
	{
		ra_count = info->stack_b->bottom + 1;
		info->stack_copy = tmp_del_stack_copy_ele(info->stack_copy,
				ra_count);
	}
	while (info->stack_b->bottom >= 0)
		ft_pa(info->stack_a, info->stack_b);
	while (ra_count-- > 0)
		ft_ra(info->stack_a);
}

void	less_than_forty(t_info *info)
{
	while (sort_check(info->stack_a) == 1)
	{
		if (sort_check(info->stack_a) == 0)
			exit(0);
		tmp_quick_sort_push_a(info);
		control_quick_sort(info);
		if (info->stack_copy.bottom <= 0)
		{
			ft_ra(info->stack_a);
			if (sort_check(info->stack_a) == 0)
				return ;
		}
	}
}
