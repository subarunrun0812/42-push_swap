/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:41:12 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 22:57:55 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rra(t_stack *stack)
{
	int	tmp;
	int	i;

	ft_printf("rra\n");
	i = stack->bottom;
	tmp = stack->data[stack->bottom];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}

void	ft_rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	ft_printf("rrb\n");
	i = stack->bottom;
	tmp = stack->data[stack->bottom];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
}
