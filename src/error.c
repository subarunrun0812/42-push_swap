/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:38:51 by susasaki          #+#    #+#             */
/*   Updated: 2023/02/16 11:32:02 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(int err_num)
{
	if (err_num == NOTINT_ERR)
		ft_printf("\x1b[31mError: not an intenger\x1b[0m\n");
	else if (err_num == OUTOFINTRANGE_ERR)
		ft_printf("\x1b[31mError: out of range int range\x1b[0m\n");
	else if (err_num == OUTOFARGRANGE_ERR)
		ft_printf("\x1b[31mError: out of argument int range\x1b[0m\n");
	else if (err_num == DUPLICATION_ERR)
		ft_printf("\x1b[31mError: duplication\x1b[0m\n");
	else if (err_num == MALLOC_ERR)
		ft_printf("\x1b[31mError: malloc\x1b[0m\n");
	exit(0);
}

// if (err_num == MISSINGARG_ERR)