/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:27:42 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 00:34:44 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ranking_small_val(int argc, t_stack *stack_b)
{
	int	i;
	int	j;
	int	order;

	i = 0;
	while (i <= stack_b->bottom)
	{
		j = 0;
		order = 0;
		while (j <= stack_b->bottom)
		{
			if (stack_b->data[i] > stack_b->data[j])
			{
				order++;
			}
			j++;
		}
		if (order < argc - 2)
			stack_b->sm_rank[order] = stack_b->data[i];
		i++;
	}
	return ;
}

static void	order_three_push(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->bottom > 2)
	{
		if (stack_b->data[stack_b->top] != stack_b->sm_rank[0]
			&& stack_b->data[stack_b->top] != stack_b->sm_rank[1]
			&& stack_b->data[stack_b->top] != stack_b->sm_rank[2])
		{
			ft_pa(stack_a, stack_b);
		}
		else if (stack_b->data[stack_b->bottom] != stack_b->sm_rank[0]
			&& stack_b->data[stack_b->bottom] != stack_b->sm_rank[1]
			&& stack_b->data[stack_b->bottom] != stack_b->sm_rank[2])
		{
			ft_rrb(stack_b);
		}
		else
			ft_rb(stack_b);
	}
}

void	less_than_six_b(int argc, t_info *info, int flag)
{
	ranking_small_val(argc, info->stack_b);
	order_three_push(info->stack_a, info->stack_b);
	less_than_three_ele(4, info, flag);
	if (sort_check(info->stack_b) == 1)
		return ;
}
