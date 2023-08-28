# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdussoye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 16:36:50 by tdussoye          #+#    #+#              #
#    Updated: 2022/11/24 16:37:16 by tdussoye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

SRC = ft_printf.c putstr.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)
clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)
