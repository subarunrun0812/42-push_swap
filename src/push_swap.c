/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:14:26 by subarunrun        #+#    #+#             */
/*   Updated: 2023/02/16 01:32:50 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_info	info;

	if (argc < 2)
		ft_error(MISSINGARG_ERR);
	check_argv(argc, argv);
	check_duplicate(argc, argv);
	if (argc - 2 > ARGSIZE)
		ft_error(OUTOFARGRANGE_ERR);
	init(argc, argv, &stack_a, &stack_b);
	init_info(&stack_a, &stack_b, &info, stack_a);
	coordinate_compression(&info);
	handle_arg(argc, argv, &info);
	exit(1);
}

// Debugging Code
// void	show_stack(t_stack *stack)
// {
// 	printf("\x1b[36mstack:");
// 	for (int i = 0; i <= stack->bottom; i++)
// 		printf("  %d", stack->data[i]);
// 	printf("\x1b[0m\n");
// }

// void	show_stack_c(t_stack stack)
// {
// 	printf("\x1b[36mstack_copy:");
// 	for (int i = 0; i <= stack.bottom; i++)
// 		printf("  %d", stack.data[i]);
// 	printf("\x1b[0m\n");
// }

// void	show_all(t_info *info)
// {
// 	printf("\n\x1b[36m~~~ stack_copy ~~~\n");
// 	show_stack_c(info->stack_copy);
// 	printf(" ~~~ stack_a ~~~\n");
// 	show_stack(info->stack_a);
// 	printf(" ~~~ stack_b ~~~\n");
// 	show_stack(info->stack_b);
// 	printf("\n\x1b[0m");
// }