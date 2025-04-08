##
## EPITECH PROJECT, 2025
## makefile
## File description:
## root makefile
##

CC ?= gcc

SRC = 	$(addprefix src/, main.c			\
		mysh.c								\
		\
		built-in/cd/change_for_home.c		\
		built-in/cd/do_cd.c					\
		built-in/exit/do_exit.c				\
		built-in/env/do_env.c				\
		built-in/env/do_setenv.c			\
		built-in/env/do_unsetenv.c			\
		built-in/env/get_env_var.c			\
		built-in/env/is_env_var.c			\
		\
		parsing/wich_path.c					\
		parsing/make_tree.c					\
		parsing/get_input.c					\
		parsing/check_tree.c				\
		parsing/format_cmd.c				\
		\
		operators/exec_rr_r.c				\
		operators/exec_rr_r2.c				\
		operators/error_branch.c			\
		operators/exec_pipe.c				\
		operators/exec_pipe2.c				\
		operators/exec_r.c					\
		operators/exec_rr.c					\
		operators/exec_l.c					\
		operators/exec_ll.c					\
		\
		execution/do_existing_command.c		\
		execution/exec_proper_function.c	\
		execution/exec_command_no_fork.c	\
		execution/exec_command.c			\
		execution/exec_operator.c			)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

CPPFLAGS = -iquote include

LIB = -L lib/linked_list/ -llinked_list -L lib/my -lmy

NAME = mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make -C lib/linked_list/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

debug: CFLAGS += -g3
debug: fclean $(OBJ)
	make -C lib/my/ CFLAGS+=-g3
	make -C lib/linked_list/ CFLAGS+=-g3
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	make -C lib/my/ clean
	make -C lib/linked_list/ clean
	$(RM) $(OBJ)

fclean:	clean
	make -C lib/my/ fclean
	make -C lib/linked_list/ fclean
	$(RM) $(NAME)

re: fclean all

tester: re
	./tests/test.sh

.PHONY: all debug clean fclean re tester
