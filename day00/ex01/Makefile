NAME = phonebook

SRC = phonebook.cpp Contact_class.cpp

OBJ = $(SRC:.cpp=.opp)

all: $(NAME)

re: fclean all

%.opp: %.cpp
	@echo "\033[1;34mcompiling object"
	@g++ -c -o $@ $^

$(NAME): $(OBJ)
	@echo "\033[1;34mcompiling exec"
	@g++ -o $@ $^

clean:
	@echo "\033[1;31mcleaning obj"
	@rm -rf $(OBJ)

fclean: clean
	@echo "\033[1;31mcleaning exec"
	@rm -rf $(NAME)