# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 15:11:15 by valeriiamur       #+#    #+#              #
#    Updated: 2019/10/26 15:58:09 by valeriiamur      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_retro

SRC		=  Window.Class.cpp main.cpp GameEntity.Class.cpp
HDRS     = Window.Class.hpp GameEntity.Class.hpp
OBJS     = $(SRC:.cpp=.o)
FLAGS 	 = -lncurses

all: $(NAME)
$(NAME): $(OBJS) $(HDRS)
	g++ $(FLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "All Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) also removed!"

re:     fclean all