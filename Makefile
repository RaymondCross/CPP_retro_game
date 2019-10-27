# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcross <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 15:11:15 by valeriiamur       #+#    #+#              #
#    Updated: 2019/10/27 04:28:56 by rcross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_retro

SRC		=  Window.Class.cpp main.cpp GameEntity.Class.cpp Player.Class.cpp \
	Game.Class.cpp Projectile.Class.cpp
HDRS     = Window.Class.hpp GameEntity.Class.hpp Player.Class.hpp
OBJS     = $(SRC:.cpp=.o)
FLAGS 	 = -Wall -Wextra -Werror -lncurses

all: $(NAME)

$(NAME):
	g++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "All Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) also removed!"

re:     fclean all
