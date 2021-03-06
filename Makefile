# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/28 17:54:25 by lmittie           #+#    #+#              #
#    Updated: 2020/03/09 20:40:26 by lmittie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lmittie.filler

SRCS = $(addprefix sources/, fill_heat_map.c filler.c main.c parse_board.c \
	parse_player_number.c parse_token.c read_board.c delete.c error.c print_position.c)

OBJ = $(SRCS:.c=.o)

LIBDIR = libft/

LIBNAME = libft/libft.a

CFLAGS = -Wall -Wextra -Werror -O2

INCLUDES = -I includes/ -I libft/

all: $(NAME)

$(OBJ): %.o: %.c libft/libft.h includes/filler.h
	gcc -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(LIBNAME):
	@make -C $(LIBDIR)

$(NAME): $(LIBNAME) $(OBJ)
	gcc $(CFLAGS) $(OBJ) -L $(LIBDIR) -lft -o $(NAME) $(INCLUDES)

clean:
	@/bin/rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean fclean re all
