# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bbremer <bbremer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/29 15:52:00 by bbremer        #+#    #+#                 #
#    Updated: 2020/01/29 15:52:02 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources

BINARY = ../asm
HEADER = -I include/ -I ../libft/ -I ../resources/
SRC_PATH = src/
OBJ = $(SRCS:%.c=%.o)
SRCS :=${addprefix $(SRC_PATH), $(SRCS)}
FLAGS = -o $(BINARY)
ERRFLAGS = -Wall -Wextra -Werror -Wno-missing-braces
CC = gcc
LIBPATH = libft/
PRINTFPATH = $(LIBPATH)ft_printf/
LIBS =  $(LIBPATH)libft.a $(PRINTFPATH)libftprintf.a
COLOR = \033[1;34m
OFF = \033[0m

all: $(BINARY)

%.o: %.c
	@$(CC) $(HEADER) -c $(ERRFLAGS) -o $@ $<

$(BINARY): $(OBJ)
	@echo "$(COLOR)Make libft$(OFF)"
	@make -C $(LIBPATH)
	@echo "$(COLOR)Make libftprintf$(OFF)"
	@make -C $(PRINTFPATH)
	@$(CC) $(HEADER) $(SRCS) $(ERRFLAGS) -o $(BINARY) $(LIBS)
	@echo "$(COLOR)Done\$(OFF)"

clean:
	@echo "$(COLOR)Removing object files$(OFF)"
	@make -C $(LIBPATH) clean
	@make -C $(PRINTFPATH) clean
	@rm -rf $(OBJ)
	@echo "$(COLOR)Done$(OFF)"

fclean: clean
	@make -C $(LIBPATH) fclean
	@make -C $(PRINTFPATH) fclean
	@echo "$(COLOR)Removing binary and extraneous directories"
	@rm -rf $(BINARY)
	@echo "Done"

re: fclean all
