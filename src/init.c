/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:15:32 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 23:03:15 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_stack_a(char **argv, t_stack *stack)
{
	int	len;
	int	num;

	len = 0;
	while (len <= stack->bottom)
	{
		num = ps_atoi(argv[len + 1]);
		if (num <= INT_MIN && INT_MAX < num)
			ft_error(OUTOFINTRANGE_ERR);
		stack->data[len] = num;
		len++;
	}
	return ;
}

static void	init_structure(t_stack *stack)
{
	int	i;

	i = -1;
	stack->top_b = 0;
	stack->top = 0;
	stack->pivot = 0;
	stack->pivot_index = 0;
	stack->push_count = 0;
	stack->sorted = 0;
	stack->split = 2;
	stack->size = 0;
	while (i++ < ARGSIZE)
		stack->data[i] = 0;
	i = -1;
	while (i++ < 3)
		stack->sm_rank[i] = 0;
	i = -1;
}

void	init_info(t_stack *stack_a, t_stack *stack_b, t_info *info,
		t_stack tmp_stack_a)
{
	info->stack_a = stack_a;
	info->stack_b = stack_b;
	info->stack_copy = tmp_stack_a;
	info->stack_copy.size = tmp_stack_a.size;
}

void	init(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	init_structure(stack_a);
	init_structure(stack_b);
	stack_a->bottom = argc - 2;
	stack_a->size = stack_a->bottom;
	stack_a->push_count = stack_a->bottom;
	stack_b->bottom = -1;
	init_stack_a(argv, stack_a);
}
