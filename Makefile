# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharile <iharile@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 13:48:10 by iharile           #+#    #+#              #
#    Updated: 2022/02/24 15:51:11 by iharile          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c sort_tab.c check_inputs.c switch_a.c switch_b.c \
 under_five_stack.c push_element.c above_five_stack.c take_from_b.c
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
OBJ = $(SRC:.c=.o)

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
	rm -f $(OBJ)

fclean :
	@make fclean -C libft
	rm -f $(NAME)

re : fclean all
	
	