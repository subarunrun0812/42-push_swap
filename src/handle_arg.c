/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:06:10 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/15 23:03:12 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_arg(int argc, char **argv, t_info *info)
{
	if (sort_check(info->stack_a) == 0)
		exit(0);
	if (argc == 2)
	{
		ft_printf(argv[1]);
		exit(0);
	}
	else if (argc <= 4)
		less_than_three_ele(argc, info, 0);
	else if (argc <= 7)
		less_than_six_a(argc, info);
	else if (argc < 41)
		less_than_forty(info);
	else if (argc >= 41)
		largest_value_group(info);
	return ;
}
