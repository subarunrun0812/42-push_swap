/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:26:49 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 00:33:16 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ranking_small_val(int argc, t_stack *stack_a)
{
	int	i;
	int	j;
	int	order;

	i = 0;
	while (i <= stack_a->bottom)
	{
		j = 0;
		order = 0;
		while (j <= stack_a->bottom)
		{
			if (stack_a->data[i] > stack_a->data[j])
				order++;
			j++;
		}
		if (order < argc - 4)
			stack_a->sm_rank[order] = stack_a->data[i];
		i++;
	}
	return ;
}

static void	reverse_sort_a(t_stack *stack_a, int num)
{
	if (stack_a->data[stack_a->bottom] == stack_a->sm_rank[0] && num == 0)
		ft_rra(stack_a);
	else if (stack_a->data[stack_a->bottom - 1] == stack_a->sm_rank[0]
		&& num == 0)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (stack_a->data[stack_a->bottom] == stack_a->sm_rank[1] && num == 1)
		ft_rra(stack_a);
	else if (stack_a->data[stack_a->bottom - 1] == stack_a->sm_rank[1]
		&& num == 1)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	else if (stack_a->data[stack_a->bottom] == stack_a->sm_rank[2] && num == 2)
		ft_rra(stack_a);
	else
		ft_ra(stack_a);
}

static int	order_three_push(t_stack *stack_a, t_stack *stack_b, int num)
{
	while (stack_a->bottom > 2 && num < 3)
	{
		if (stack_a->data[stack_a->top] == stack_a->sm_rank[0] && num == 0)
		{
			ft_pb(stack_a, stack_b);
			num++;
		}
		else if (stack_a->data[stack_a->top] == stack_a->sm_rank[1] && num == 1)
		{
			ft_pb(stack_a, stack_b);
			num++;
		}
		else if (stack_a->data[stack_a->top] == stack_a->sm_rank[2] && num == 2)
		{
			ft_pb(stack_a, stack_b);
			num++;
		}
		else
			reverse_sort_a(stack_a, num);
	}
	return (num);
}

void	less_than_six_a(int argc, t_info *info)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	ranking_small_val(argc, info->stack_a);
	num = order_three_push(info->stack_a, info->stack_b, num);
	less_than_three_ele(4, info, 0);
	less_than_three_ele(num + 1, info, 2);
	while (i++ < argc - 4)
		ft_pa(info->stack_a, info->stack_b);
}
