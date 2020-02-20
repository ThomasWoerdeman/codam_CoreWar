# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: twoerdem <twoerdem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/27 16:01:54 by twoerdem       #+#    #+#                 #
#    Updated: 2020/01/29 18:35:36 by twoerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar
FLAGS = -Wall -Werror -Wextra
SRC =	src/main.c\
		src/check_argument_validity.c\
		src/parse_players.c\
		src/initialise_players.c\
		src/introduction.c\
		src/initialise_cursors.c\
		src/manage_wait_cycles.c\
		src/battle.c\
		src/get_argument_types.c\
		src/get_direct_argument.c\
		src/get_indirect_argument.c\
		src/supporting_functions.c\
		src/live.c\
		src/add.c\
		src/and.c\
		src/aff.c\
		src/fork.c\
		src/ld.c\
		src/ldi.c\
		src/lfork.c\
		src/lld.c\
		src/lldi.c\
		src/or.c\
		src/xor.c\
		src/st.c\
		src/sti.c\
		src/sub.c\
		src/zjmp.c\
		src/visu.c\
		src/visu2.c\
		src/visu3.c\
		src/execute_operations.c
COLOR = \033[1;35m
OFF = \033[0m

INCLUDES = -Ilibft -Llibft -lft -I./includes -lncurses

all: $(NAME)

$(NAME):
	@echo "$(COLOR)Creating $(NAME)$(OFF)"
	@make -C libft/ fclean && make -C libft/
	@$(CC) -o $(NAME) $(FLAGS) $(SRC) $(INCLUDES)

clean:
	@echo "$(COLOR)Removing object files$(OFF)"
	@cd libft && make clean

fclean: clean
	@cd libft && make fclean
	@echo "$(COLOR)Removing binary and extraneous directories"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all
