/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_push_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:07:36 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 00:38:38 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	check_sort(t_info *info)
{
	if (info->stack_copy.bottom > ((info->stack_copy.size / 2) + 1))
		while (check_copy_contains_a_top(info) == 1)
			ft_ra(info->stack_a);
	else
		while (check_copy_contains_a_bottom(info) == 0)
			ft_rra(info->stack_a);
}

static int	sort_as_is(t_info *info, int i)
{
	if (info->stack_b->data[info->stack_b->bottom] == info->stack_copy.data[0])
	{
		ft_rrb(info->stack_b);
		ft_pa(info->stack_a, info->stack_b);
		ft_ra(info->stack_a);
		info->stack_copy = del_stack_copy_ele(info->stack_copy, 1);
		info->stack_a->sorted++;
	}
	while (info->stack_copy.data[0] == info->stack_a->data[0])
	{
		info->stack_copy = del_stack_copy_ele(info->stack_copy, 1);
		ft_ra(info->stack_a);
		info->stack_a->sorted++;
		i++;
	}
	if (info->stack_copy.bottom <= -1 || sort_check(info->stack_a) == 0)
	{
		exit(1);
	}
	return (i);
}

static void	push_b(t_info *info, int tmp_num, t_tool *tool, int push_num)
{
	if (info->stack_a->pivot >= info->stack_a->data[info->stack_a->top])
	{
		ft_pb(info->stack_a, info->stack_b);
		tool->i++;
	}
	else if (info->stack_a->pivot >= info->stack_a->data[info->stack_a->top + 1]
		&& tmp_num > 0 && check_copy_contains_a_top_next(info) == 0
		&& push_num - 7 < tool->i)
	{
		if (info->stack_b->data[info->stack_b->top]
			< info->stack_b->data[info->stack_b->top + 1])
			ft_ss(info->stack_a, info->stack_b);
		else
			ft_sa(info->stack_a);
	}
	else if (tool->i < push_num)
	{
		ft_ra(info->stack_a);
		tool->flag = 1;
	}
}

static void	sub_quick_sort_push_a(t_info *info, int tmp_num, int push_num,
		t_tool *tool)
{
	while (tool->i < push_num)
	{
		if (check_copy_contains_a_top(info) == 0)
		{
			if (tmp_num > 0 && tool->flag == 0)
				tool->i = sort_as_is(info, tool->i);
			push_b(info, tmp_num, tool, push_num);
			if (tool->i == push_num && tmp_num > 0)
			{
				while (info->stack_a->pivot
					< info->stack_a->data[info->stack_a->bottom])
					ft_rra(info->stack_a);
				tool->i++;
			}
		}
		else
			check_sort(info);
	}
}

void	quick_sort_push_a(t_info *info, int tmp_num)
{
	t_tool	tool;
	int		push_num;

	tool.i = 0;
	tool.flag = 0;
	push_num = count_push(info, 0);
	sub_quick_sort_push_a(info, tmp_num, push_num, &tool);
	if (info->stack_b->bottom < 6 && info->stack_a->split > 2)
		info->stack_a->split /= 2;
	else if (info->stack_b->bottom > 6 && info->stack_a->split > 2)
		info->stack_a->split *= 2;
}
