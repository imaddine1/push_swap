# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iharile <iharile@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 12:57:38 by iharile           #+#    #+#              #
#    Updated: 2022/02/06 14:26:59 by iharile          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -f



SRC = ft_atoi.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
	ft_lstnew_bonus.c ft_lstsize_bonus.c ft_strncmp.c

OBJ = $(SRC:.c=.o)
		
all : $(NAME) 

$(NAME) : $(OBJ)
	
%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
	ar rc $(NAME) $@

clean :
	$(RM) $(OBJ) 

fclean : clean
	$(RM) $(NAME)

re : fclean all bonus 