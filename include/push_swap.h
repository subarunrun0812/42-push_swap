/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:06:49 by susasaki          #+#    #+#             */
/*   Updated: 2023/02/16 01:14:09 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/header/ft_printf.h"
# include "../printf/libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// 536870911
# define ARGSIZE 10000
# define MAX_BIT 32

# define MISSINGARG_ERR 0
# define NOTINT_ERR 1
# define OUTOFINTRANGE_ERR 2
# define OUTOFARGRANGE_ERR 3
# define DUPLICATION_ERR 4
# define MALLOC_ERR 4

typedef struct s_stack
{
	int		data[ARGSIZE];
	int		top;
	int		bottom;
	int		top_b;
	int		pivot;
	int		pivot_index;
	int		size;
	int		push_count;
	int		split;
	int		sorted;
	int		sm_rank[6];
}			t_stack;

typedef struct s_info
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	stack_copy;
}			t_info;

typedef struct s_tool
{
	int		i;
	int		flag;
}			t_tool;

//Debugging Code
// void		show_stack(t_stack *stack);
// void		show_stack_c(t_stack stack);
// void		show_all(t_info *info);

//====== cmd ======
//push.c
void		ft_pb(t_stack *stack_a, t_stack *stack_b);
void		ft_pa(t_stack *stack_a, t_stack *stack_b);

//reverse_rotate.c
void		ft_rra(t_stack *stack);
void		ft_rrb(t_stack *stack);

//rotate.c
void		ft_ra(t_stack *stack);
void		ft_rb(t_stack *stack);

//swap.c
void		ft_sa(t_stack *stack);
void		ft_sb(t_stack *stack);
void		ft_ss(t_stack *stack_a, t_stack *stack_b);

//====== largest_group ======
// check_copy_contains_a.c
int			check_copy_contains_a_top_next(t_info *info);
int			check_copy_contains_a_top(t_info *info);
int			check_copy_contains_a_bottom(t_info *info);

//count_push.c
int			count_push(t_info *info, int flag);

// del_stack_copy_ele.c
t_stack		del_stack_copy_ele(t_stack stack_copy, int num);

//largest_value_group.c
void		largest_value_group(t_info *info);

//quick_sort_push_a.c
void		quick_sort_push_a(t_info *info, int tmp_num);

//quick_sort_push_b.c
void		quick_sort_push_b(t_info *info);

//====== less_than_forty ======
//less_than_forty
void		less_than_forty(t_info *info);

//quick_sort_push.c
void		tmp_quick_sort_push_a(t_info *info);
void		tmp_quick_sort_push_b(t_info *info);

//tmp_count_push.c
void		tmp_search_pivot(t_stack *stack, t_stack stack_copy, int flag);
int			tmp_count_push(t_stack *stack, int flag);
//====== done/ ======

// check_arg.c
void		check_duplicate(int argc, char **argv);
void		check_argv(int argc, char **argv);

//coordinate_compression.c
void		coordinate_compression(t_info *info);

//error.c
void		ft_error(int err_num);
void		error_mapdata(t_stack *stack, int err_num);

//handle_arg.c
void		handle_arg(int argc, char **argv, t_info *info);

//init.c
void		init_info(t_stack *stack_a, t_stack *stack_b, t_info *info,
				t_stack tmp_stack_a);
void		init(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);

//libft_imprmt.c
int			ps_atoi(const char *str);

//less_than_six_a
void		less_than_six_a(int argc, t_info *info);
//less_than_six_b
void		less_than_six_b(int argc, t_info *info, int flag);

//less_than_three_ele.c
void		less_than_three_ele(int argc, t_info *info, int flag);

//less_than_three_stack_b.c
void		less_than_three_stack_b(int argc, t_stack *stack_a,
				t_stack *stack_b, t_info *info);

//sort_check.c
int			sort_check(t_stack *stack);
int			reverse_sort_check(t_stack *stack);

#endif
