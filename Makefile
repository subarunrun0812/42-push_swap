# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 11:14:32 by subarunrun        #+#    #+#              #
#    Updated: 2023/02/15 23:07:10 by susasaki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SOURCES_DIR = ./src
CMD_DIR = /cmd
LARGEST_DIR = /largest_group
LESS_THAN_FORTY = /less_than_forty


SOURCES = $(SOURCES_DIR)$(CMD_DIR)/push.c\
		  $(SOURCES_DIR)$(CMD_DIR)/reverse_rotate.c\
		  $(SOURCES_DIR)$(CMD_DIR)/rotate.c\
		  $(SOURCES_DIR)$(CMD_DIR)/swap.c\
		  $(SOURCES_DIR)$(LARGEST_DIR)/check_copy_contains_a.c\
		  $(SOURCES_DIR)$(LARGEST_DIR)/count_push.c\
		  $(SOURCES_DIR)$(LARGEST_DIR)/del_stack.c\
		  $(SOURCES_DIR)$(LARGEST_DIR)/largest_value_group.c\
		  $(SOURCES_DIR)$(LARGEST_DIR)/quick_sort_push_a.c\
		  $(SOURCES_DIR)$(LARGEST_DIR)/quick_sort_push_b.c\
		  $(SOURCES_DIR)$(LESS_THAN_FORTY)/less_than_forty.c\
		  $(SOURCES_DIR)$(LESS_THAN_FORTY)/quick_sort_push.c\
		  $(SOURCES_DIR)$(LESS_THAN_FORTY)/tmp_count_push.c\
		  $(SOURCES_DIR)/check_arg.c\
		  $(SOURCES_DIR)/coordinate_compression.c\
		  $(SOURCES_DIR)/error.c\
		  $(SOURCES_DIR)/handle_arg.c\
		  $(SOURCES_DIR)/init.c\
		  $(SOURCES_DIR)/libft_imprmt.c\
		  $(SOURCES_DIR)/less_than_six_a.c\
		  $(SOURCES_DIR)/less_than_six_b.c\
		  $(SOURCES_DIR)/less_than_three_ele.c\
		  $(SOURCES_DIR)/less_than_three_stack_b.c\
		  $(SOURCES_DIR)/push_swap.c\
		  $(SOURCES_DIR)/sort_check.c\

PRINTF_DIR	= ./printf
PRINTF 		= $(PRINTF_DIR)/libftprintf.a

INCLUDE = -I printf -I include

OBJS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(PRINTF)
	$(CC) $(OBJS) $(PRINTF) $(INCLUDE) -o $(NAME)

$(PRINTF) :
	make -C $(PRINTF_DIR)
clean:
	make -C $(PRINTF_DIR) 
	rm -f $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all