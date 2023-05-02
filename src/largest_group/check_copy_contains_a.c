/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_copy_contains_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:28:47 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 00:37:22 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

//stack_aにstack_copyの値が入っているか確認する
int	check_copy_contains_a_top_next(t_info *info)
{
	int	i;

	i = -1;
	while (i++ < info->stack_copy.bottom)
	{
		if (info->stack_a->data[1] == info->stack_copy.data[i])
			return (0);
	}
	return (1);
}

//stack_aにstack_copyの値が入っているか確認する
int	check_copy_contains_a_top(t_info *info)
{
	int	i;

	i = -1;
	while (i++ < info->stack_copy.bottom)
	{
		if (info->stack_a->data[0] == info->stack_copy.data[i])
			return (0);
	}
	return (1);
}

//stack_aにstack_copyの値が入っているか確認する
int	check_copy_contains_a_bottom(t_info *info)
{
	int	i;

	i = -1;
	while (i++ < info->stack_copy.bottom)
	{
		if (info->stack_a->data[info->stack_a->bottom]
			== info->stack_copy.data[i])
			return (0);
	}
	return (1);
}
