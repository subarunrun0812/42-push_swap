/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:54:43 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 23:05:01 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_check(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->bottom)
	{
		if (stack->data[i] < stack->data[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	reverse_sort_check(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->bottom)
	{
		if (stack->data[i] > stack->data[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}
