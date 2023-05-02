/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:03:17 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 23:07:15 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	del_stack_copy_ele(t_stack stack_copy, int num)
{
	int	i;

	i = -1;
	while (i++ < stack_copy.bottom - num)
		stack_copy.data[i] = stack_copy.data[i + num];
	stack_copy.bottom -= num;
	return (stack_copy);
}
