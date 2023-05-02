/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 02:04:57 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 23:05:05 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_printf("pa\n");
	stack_a->bottom++;
	i = stack_a->bottom;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[stack_a->top] = stack_b->data[stack_b->top];
	i = 0;
	while (i < stack_b->bottom)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->bottom--;
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_printf("pb\n");
	stack_b->bottom++;
	i = stack_b->bottom;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[stack_b->top] = stack_a->data[stack_a->top];
	i = 0;
	while (i < stack_a->bottom)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->bottom--;
}
