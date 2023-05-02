/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_count_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:27:07 by susasaki          #+#    #+#             */
/*   Updated: 2023/02/15 23:02:57 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//stack_bでpivotを決める時
static int	tmp_demand_top_b_bottom(t_stack *stack_b, t_stack stack_copy)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < stack_copy.bottom)
	{
		j = -1;
		while (j++ < stack_b->bottom)
		{
			if (stack_copy.data[i] <= stack_b->data[j])
			{
				stack_copy.top_b = i;
			}
		}
	}
	return (stack_copy.top_b);
}

//スタックのpivotとなる真ん中の値を求める
void	tmp_search_pivot(t_stack *stack, t_stack stack_copy, int flag)
{
	int	c_val;
	int	i;
	int	top_b;

	if (flag == 0)
	{
		c_val = stack_copy.data[(stack_copy.bottom / 2)];
	}
	else
	{
		top_b = tmp_demand_top_b_bottom(stack, stack_copy);
		c_val = stack_copy.data[((top_b / 2) - 1)];
	}
	i = -1;
	while (i++ < stack->bottom)
	{
		if (stack->data[i] == c_val)
		{
			stack->pivot = stack->data[i];
			return ;
		}
	}
}

// 分割後のpushする回数を求める。
int	tmp_count_push(t_stack *stack, int flag)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	while (i++ < stack->bottom)
	{
		if ((stack->pivot >= stack->data[i]) && flag == 0)
			res++;
		if ((stack->pivot <= stack->data[i]) && flag == 1)
			res++;
	}
	return (res);
}
