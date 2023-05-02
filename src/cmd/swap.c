/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:42:46 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 22:58:25 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sa(t_stack *stack)
{
	int	tmp;

	ft_printf("sa\n");
	if (stack->bottom == 0)
		return ;
	tmp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top + 1];
	stack->data[stack->top + 1] = tmp;
}

void	ft_sb(t_stack *stack)
{
	int	tmp;

	ft_printf("sb\n");
	if (stack->bottom == 0)
		return ;
	tmp = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top + 1];
	stack->data[stack->top + 1] = tmp;
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;

	ft_printf("ss\n");
	if (stack_a->bottom == 0)
		return ;
	tmp = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top + 1];
	stack_a->data[stack_a->top + 1] = tmp;
	if (stack_b->bottom == 0)
		return ;
	tmp = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top + 1];
	stack_b->data[stack_b->top + 1] = tmp;
}
