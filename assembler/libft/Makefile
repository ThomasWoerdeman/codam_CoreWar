# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 17:42:27 by fblom          #+#    #+#                 #
#    Updated: 2020/01/29 16:07:50 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources
NAME = libft.a
ERRFLAGS = -Wall -Werror -Wextra
INCL = libft.h
OBJ = $(SRCS:%.c=%.o)
HEADER = -I./
COLOR = \033[1;35m
OFF = \033[0m

all: $(NAME)

%.o: %.c
	@gcc -c $(ERRFLAGS) $(HEADER) -o $@ $<

$(NAME): $(OBJ)
	@echo "$(COLOR)Creating $(NAME)$(OFF)"
	@ar -rc $(NAME) $(OBJ)

clean:
	@echo "$(COLOR)Removing asm library objects$(OFF)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(COLOR)Removing $(NAME)$(OFF)"
	@rm -f $(NAME)

re: fclean all
