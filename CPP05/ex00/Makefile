#! Variables

NAME	= a.out
OBJ_DIR	= obj/
CC		= c++
CFLAGS	= -g -Wshadow -Wall -Wextra -Werror -std=c++98

#! Sources

SRCS		= main.cpp Bureaucrat.cpp
OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

#! Rules

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compilation complete: $(NAME)"

$(OBJ_DIR)%.o: %.cpp | obj_mkdir
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned up object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up executable"

obj_mkdir:
	@mkdir -p $(OBJ_DIR)

re: fclean all
	@echo "Recompiled everything"

.PHONY: all clean fclean re
