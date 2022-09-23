# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adinari <adinari@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 01:20:12 by adinari           #+#    #+#              #
#    Updated: 2022/09/22 23:34:59 by adinari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = test
# SRC = main.c
# OBJ = $(SRC:.c=.o)
# LIBS =  codam_MLX/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
# $(NAME):
# 		cc -Wall -Werror -Wextra $(SRC) $(LIBS) -o $(NAME)
# .c.o:
# 	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $< -o $(<:.c=.o)
# clean:
# 	rm -f $(OBJ)
# fclean: clean
# 	rm -f $(NAME)
# all: $(NAME)
# re: fclean all

NAME = so_long

FILES = src/main.c\
		src/gnl/get_next_line.c\
		src/gnl/get_next_line_utils.c\
		src/dimensions.c\
		src/map_stuff.c\
		src/key_hook.c\
		src/path_find.c\
		src/utils.c\
		src/printf/ft_printf.c\
		src/printf/ft_puthex.c\
		src/printf/ft_putnbr.c\
		src/printf/ft_putptr.c\
		src/printf/ft_putunsigned.c\

OBJECTS = $(FILES:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	
%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
LIBS =  codam_MLX/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
$(NAME): $(OBJECTS)
	export LD_LIBRARY_PATH=/usr/lib/swift/
	$(CC) $(OBJECTS) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	

fclean: clean
	rm -rf $(NAME) *.o

re: fclean all