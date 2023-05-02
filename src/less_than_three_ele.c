/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_three_ele.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:32:18 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 00:34:52 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	less_than_three_stack_a(int argc, t_stack *stack)
{
	if (argc == 3)
	{
		if (stack->data[0] > stack->data[1])
			ft_sa(stack);
	}
	else if (argc == 4)
	{
		while (sort_check(stack) == 1)
		{
			if (stack->data[stack->top] > stack->data[stack->top + 1])
				ft_sa(stack);
			else
				ft_rra(stack);
		}
	}
	if (sort_check(stack) == 1)
		return ;
}

static void	less_than_six_a_three_stack_b(int argc, t_stack *stack)
{
	if (argc == 3)
	{
		if (stack->data[0] < stack->data[1])
			ft_sb(stack);
	}
	else if (argc == 4)
	{
		while (reverse_sort_check(stack) == 1)
		{
			if (stack->data[stack->top] > stack->data[stack->top + 1]
				&& stack->data[stack->top] > stack->data[stack->bottom])
			{
				ft_rb(stack);
			}
			else if (stack->data[stack->top] < stack->data[stack->top + 1])
			{
				ft_sb(stack);
			}
			else
				ft_rrb(stack);
		}
	}
	if (reverse_sort_check(stack) == 1)
		return ;
}

void	less_than_three_ele(int argc, t_info *info, int flag)
{
	if (flag == 0)
		less_than_three_stack_a(argc, info->stack_a);
	else if (flag == 1)
		less_than_three_stack_b(argc, info->stack_a, info->stack_b, info);
	else if (flag == 2)
		less_than_six_a_three_stack_b(argc, info->stack_b);
}
