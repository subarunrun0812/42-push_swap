/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_three_stack_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:34:06 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 23:03:44 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	four_ele(t_stack *stack_a, t_stack *stack_b, t_info *info)
{
	while (sort_check(stack_b) == 1)
	{
		if (stack_b->data[stack_b->top] > stack_b->data[stack_b->top + 1]
			&& stack_b->data[stack_b->top] > stack_b->data[stack_b->bottom])
			ft_rb(stack_b);
		else if (stack_b->data[stack_b->top] > stack_b->data[stack_b->top + 1])
		{
			if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top + 1]
				&& check_copy_contains_a_top_next(info) == 0)
				ft_ss(stack_a, stack_b);
			else
				ft_sb(stack_b);
		}
		else
			ft_rrb(stack_b);
	}
}

void	less_than_three_stack_b(int argc, t_stack *stack_a, t_stack *stack_b,
		t_info *info)
{
	if (argc == 3)
	{
		if (stack_b->data[0] > stack_b->data[1])
			ft_sb(stack_b);
	}
	else if (argc == 4)
	{
		four_ele(stack_a, stack_b, info);
	}
	if (sort_check(stack_b) == 1)
		return ;
}
