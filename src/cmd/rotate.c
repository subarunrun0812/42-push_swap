/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:22:23 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 22:58:09 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_ra(t_stack *stack)
{
	int	tmp;
	int	i;

	ft_printf("ra\n");
	tmp = stack->data[0];
	i = 0;
	while (i < stack->bottom)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = tmp;
}

void	ft_rb(t_stack *stack)
{
	int	tmp;
	int	i;

	ft_printf("rb\n");
	tmp = stack->data[0];
	i = 0;
	while (i < stack->bottom)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = tmp;
}
