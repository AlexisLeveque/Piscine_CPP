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

NAME =	ex02
CC =	clang++
FLAGS =	-Wall -Wextra -Werror


OBJ_DIR =	.obj
SRC =	main.cpp
OBJ =	$(sort $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC)))
INC = Array.hpp
INCLUDE =	$(sort $(patsubst %.hpp, %.hpp, $(INC)))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: %.cpp $(INCLUDE) | $(OBJ_DIR)
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	echo $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
