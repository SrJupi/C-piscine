# This is our MAKEFILE for bsq #

NAME = bsq
CC = gcc
RM = rm -f
COMPILE_FLAGS =	-Wall -Wextra -Werror
SRC = buf_to_map.c check_map.c copy_map_to_buf.c get_map_size.c main.c solve_map.c try_not_cry.c

all: compile

compile:
	@rm -f $(NAME)
	@$(CC) $(COMPILE_FLAGS) $(SRC) -o $(NAME)

re: fclean all

fclean: clean
	@$(RM) *.o

clean:
	@$(RM) a.out
	@$(RM) *.log
	@$(RM) $(NAME)