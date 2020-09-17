# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 16:14:45 by lmittie           #+#    #+#              #
#    Updated: 2020/03/09 20:38:32 by lmittie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visualazier

SRCS = $(addprefix sources/, board_manipulation.cpp calculations.cpp handle_events.cpp main.cpp)

OBJ = $(SRCS:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -O2 -std=c++11

SDL_LIB = -L ~/.brew/lib -lSDL2

INCLUDES = -I includes/ -I ~/.brew/include

all: $(NAME)

$(OBJ): %.o: %.cpp includes/visualizer.h
	g++ -c $(CFLAGS) $< -o $@ $(INCLUDES)

$(NAME): $(OBJ)
	g++ $(CFLAGS) $(OBJ) $(SDL_LIB) $(INCLUDES) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all