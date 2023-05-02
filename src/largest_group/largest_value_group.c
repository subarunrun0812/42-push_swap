/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_value_group.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:11:46 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 00:38:02 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	control_quick_sort(t_info *info)
{
	if (info->stack_copy.bottom > 0)
	{
		info->stack_copy = del_stack_copy_ele(info->stack_copy,
				info->stack_b->bottom + 1);
		info->stack_a->split *= 2;
	}
	while (info->stack_b->bottom >= 0)
	{
		ft_pa(info->stack_a, info->stack_b);
		ft_ra(info->stack_a);
		info->stack_a->sorted++;
	}
	if (info->stack_copy.bottom == 0)
	{
		ft_ra(info->stack_a);
		if (sort_check(info->stack_a) == 0)
			return ;
	}
}

static void	ft_sort_b(t_info *info)
{
	if (sort_check(info->stack_b) == 1 && info->stack_copy.bottom > 0)
	{
		while (info->stack_b->bottom >= 6)
			quick_sort_push_b(info);
		if (info->stack_b->bottom < 3)
			less_than_three_ele(info->stack_b->bottom + 2, info, 1);
		else if (info->stack_b->bottom < 6)
			less_than_six_b(info->stack_b->bottom + 2, info, 1);
	}
}

void	largest_value_group(t_info *info)
{
	int	tmp_num;
	int	flag;

	flag = 0;
	tmp_num = -1;
	while (sort_check(info->stack_a) == 1)
	{
		tmp_num++;
		if (sort_check(info->stack_a) == 0)
			exit(0);
		quick_sort_push_a(info, tmp_num);
		ft_sort_b(info);
		control_quick_sort(info);
		if (info->stack_copy.size / 2 + 5 > info->stack_copy.bottom
			&& flag == 0)
		{
			info->stack_a->split = 2;
			flag = 1;
		}
	}
}
