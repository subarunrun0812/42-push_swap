/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:18:38 by susasaki          #+#    #+#             */
/*   Updated: 2023/02/15 23:02:47 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//既にソート済みの値かどうかをチェックする
static void	tmp_sorted_rotate(t_info *info)
{
	if (info->stack_copy.bottom > ((info->stack_copy.size / 2) + 1))
	{
		while (check_copy_contains_a_top(info) == 1)
			ft_ra(info->stack_a);
	}
	else
	{
		while (check_copy_contains_a_bottom(info) == 0)
			ft_rra(info->stack_a);
	}
}

void	tmp_quick_sort_push_a(t_info *info)
{
	int	i;
	int	p_num;

	i = 0;
	tmp_search_pivot(info->stack_a, info->stack_copy, 0);
	p_num = tmp_count_push(info->stack_a, 0);
	while (i < p_num)
	{
		if (check_copy_contains_a_top(info) == 0)
		{
			if (info->stack_a->pivot >= info->stack_a->data[info->stack_a->top])
			{
				ft_pb(info->stack_a, info->stack_b);
				i++;
			}
			else
				ft_ra(info->stack_a);
		}
		else
		{
			tmp_sorted_rotate(info);
			return ;
		}
	}
}

void	tmp_quick_sort_push_b(t_info *info)
{
	int	i;
	int	p_num;

	i = 0;
	tmp_search_pivot(info->stack_b, info->stack_copy, 1);
	p_num = tmp_count_push(info->stack_b, 1);
	while (i < p_num)
	{
		if (info->stack_b->pivot <= info->stack_b->data[info->stack_b->top])
		{
			ft_pa(info->stack_a, info->stack_b);
			i++;
		}
		else
			ft_rb(info->stack_b);
	}
}
