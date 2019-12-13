# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 09:53:11 by kdaou             #+#    #+#              #
#    Updated: 2019/02/18 14:43:08 by kdaou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = *.c ft_printf/*.c

OBJS = *.o

FLAGS = -Wall -Wextra -Werror

INC = -I ft_printf/ -I .

all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) $(SRCS)
		ar cr $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
