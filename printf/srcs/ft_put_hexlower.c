/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexlower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:50:21 by susasaki          #+#    #+#             */
/*   Updated: 2023/02/16 00:40:46 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_hexlower(unsigned int n)
{
	size_t	count;
	char	*str;

	str = ft_tolower_all(ft_point_base(n, 16));
	count = ft_put_string(str);
	free(str);
	return (count);
}
