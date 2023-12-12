# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:14:11 by abkhairi          #+#    #+#              #
#    Updated: 2023/10/30 15:04:18 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker

SRCS = push_swap.c read_argv.c parsing.c func_helper.c put_argv.c sorting2_5.c rotate.c \
		swap.c push.c indexing.c big_sort.c rrab.c free_str_stack.c
OBJS = $(SRCS:.c=.o)

B_SRCS = bonus/checker_bonus.c bonus/freefree_bonus.c bonus/pa_pb_bonus.c bonus/parsing_bonus.c\
		bonus/put_argv_bonus.c bonus/ra_rb_rr_bonus.c bonus/read_argv_bonus.c bonus/rra_b_bonus.c\
		bonus/swap_bonus.c
B_OBJS = $(B_SRCS:.c=.o)

CC = cc 
CFLAGS = -Wall -Werror -Wextra 

LIBFT = libft/libft.a

all : $(NAME)
bonus: $(B_NAME)
	
%bonus.o: %bonus.c bonus/checker_bonus.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(B_NAME): $(B_OBJS)
	make -C libft/
	$(CC) $(B_OBJS) $(LIBFT) -o $(B_NAME)

%.o: %.c push_swap.h ./libft/*.c ./libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C libft/
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJS)
	rm -rf $(B_OBJS)
	
fclean:	clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)
	rm -rf $(LIBFT)
	rm -rf $(LIBGET)

re : fclean all