# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchalard <mchalard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 17:53:40 by mchalard          #+#    #+#              #
#    Updated: 2022/03/03 16:33:57 by mchalard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAG = -Wall -Wextra -Werror 
NAME = so_long
SRC = src/main.c src/so_long.c src/map.c src/get_next_line_utils.c src/get_next_line.c src/ft_split.c src/validmap.c src/image.c src/key_event.c src/ft_printf.c src/ft_putchar.c src/ft_putnbr.c src/ft_putstr.c src/ft_itoa.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAG) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAG) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
