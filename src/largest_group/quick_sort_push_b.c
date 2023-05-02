/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_push_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:22:57 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 23:02:38 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	make_sorted_definite_sort(t_info *info)
{
	ft_pa(info->stack_a, info->stack_b);
	ft_ra(info->stack_a);
	info->stack_copy = del_stack_copy_ele(info->stack_copy, 1);
	info->stack_a->sorted++;
	if (info->stack_b->bottom >= 6)
		return (1);
	return (0);
}

void	quick_sort_push_b(t_info *info)
{
	int	i;
	int	push_num;

	i = 0;
	push_num = count_push(info, 1);
	info->stack_a->push_count++;
	while (i < push_num)
	{
		if (info->stack_b->data[info->stack_b->top] == info->stack_copy.data[0]
			&& info->stack_b->bottom > 2)
			if (make_sorted_definite_sort(info) == 1)
				return ;
		if (info->stack_b->bottom >= 0)
		{
			if (info->stack_b->pivot <= info->stack_b->data[info->stack_b->top])
			{
				ft_pa(info->stack_a, info->stack_b);
				i++;
			}
			else
				ft_rb(info->stack_b);
		}
		else
			return ;
	}
}
