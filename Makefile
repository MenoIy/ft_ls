# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 14:23:55 by kdaou             #+#    #+#              #
#    Updated: 2019/03/16 20:41:03 by kdaou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAG = -Wall -Wextra -Werror
SRC = srcs_ft_ls/ft_gestion_ls.c \
		srcs_ft_ls/ft_get_info.c \
		srcs_ft_ls/ft_new_struct_ls.c \
		srcs_ft_ls/ft_printing_tools.c \
		srcs_ft_ls/ft_sorting_ls.c \
		srcs_ft_ls/ft_traitement_ls.c \
		srcs_ft_ls/main.c \
		srcs_ft_ls/tools.c
LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) $(LIBFT) $(SRC) -o $(NAME)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

