# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 10:55:07 by pribault          #+#    #+#              #
#    Updated: 2018/06/03 14:01:29 by pribault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_retro
CC =	clang++
FLAGS =	-Wall -Wextra -Werror

SRC_DIR =	src
OBJ_DIR =	.obj
INC_DIR =	include
SRC =	ft_retro.cpp Screen.cpp Log.cpp inputs.cpp Window.cpp Element.cpp\
		Bullet.cpp Character.cpp draw.cpp Enemy.cpp collision.cpp Obstacle.cpp\
		PowerUp.cpp
OBJ =	$(sort $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC)))
INC =	ft_retro.hpp Screen.hpp Log.hpp Window.hpp Element.hpp Bullet.hpp\
		Character.hpp Enemy.hpp Obstacle.hpp PowerUp.hpp
INCLUDE =	$(sort $(patsubst %.hpp, $(INC_DIR)/%.hpp, $(INC)))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE) | $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	echo $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
