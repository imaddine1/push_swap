# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharile <iharile@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 13:48:10 by iharile           #+#    #+#              #
#    Updated: 2022/02/27 16:54:08 by iharile          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c sort_tab.c check_inputs.c switch_a.c switch_b.c \
 under_five_stack.c push_element.c above_five_stack.c take_from_b.c

SRCB = checker_bonus.c sort_tab.c check_inputs.c switch_a.c switch_b.c \
 under_five_stack.c push_element.c above_five_stack.c take_from_b.c  \
 get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c

CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAME_BONUS = checker
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@make bonus -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
#*.o : *.c 
#	$(CC) $(CFLAGS) -c $< -o $@	
#	$(CC) $(CFLAGS) -c $(OBJ) -o $(NAME)

clean :
	@make clean -C libft
	rm -f $(OBJ) $(OBJB)

fclean : clean
	@make fclean -C libft
	rm -f $(NAME) $(NAME_BONUS)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJB)
	@make -C libft
	@make bonus -C libft
	$(CC) $(CFLAGS) $(OBJB) libft/libft.a -o $(NAME_BONUS)

re : fclean all
	
	