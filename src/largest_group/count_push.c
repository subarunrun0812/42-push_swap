/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:32:53 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 13:59:13 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	search_pivot_a(t_stack *stack_a, t_stack stack_copy)
{
	int	c_val;
	int	i;

	if (((stack_a->bottom - stack_a->sorted) / stack_a->split) < 7)
	{
		stack_a->split /= 2;
	}
	c_val = stack_copy.data[((stack_copy.bottom) / stack_a->split)];
	i = -1;
	while (i++ <= stack_a->bottom)
	{
		if (stack_a->data[i] == c_val)
		{
			stack_a->pivot = stack_a->data[i];
			return ;
		}
	}
}

static void	search_pivot_b(t_stack *stack_b, t_stack stack_copy)
{
	int	c_val;
	int	i;

	c_val = stack_copy.data[((stack_b->bottom / 2) - 1)];
	i = -1;
	while (i++ <= stack_b->bottom)
	{
		if (stack_b->data[i] == c_val)
		{
			stack_b->pivot = stack_b->data[i];
			return ;
		}
	}
}

static void	search_pivot(t_stack *stack_a, t_stack *stack_b, t_stack stack_copy,
		int flag)
{
	if (flag == 0)
	{
		search_pivot_a(stack_a, stack_copy);
	}
	else
	{
		search_pivot_b(stack_b, stack_copy);
	}
}

int	count_push(t_info *info, int flag)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	search_pivot(info->stack_a, info->stack_b, info->stack_copy, flag);
	while (i < info->stack_copy.bottom && flag == 0)
	{
		if (info->stack_a->pivot == info->stack_copy.data[i])
			return (i + 1);
		i++;
	}
	while (i <= info->stack_b->bottom && flag == 1)
	{
		if ((info->stack_b->pivot <= info->stack_b->data[i]))
			res++;
		i++;
	}
	return (res);
}
