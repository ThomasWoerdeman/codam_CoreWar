# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bbremer <bbremer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/29 16:38:45 by bbremer        #+#    #+#                 #
#    Updated: 2020/01/29 16:46:06 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources

BINARY = ../disasm
HEADER = -I include/ -I ../libft/ -I ../resources/
SRC_PATH = src/
OBJ = $(SRCS:%.c=%.o)
SRCS :=${addprefix $(SRC_PATH), $(SRCS)}
FLAGS = -o $(BINARY)
ERRFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBPATH = ../assembler/libft/
PRINTFPATH = $(LIBPATH)ft_printf/
LIBS =  $(LIBPATH)libft.a $(PRINTFPATH)libftprintf.a
COLOR = \033[1;34m
OFF = \033[0m

all: $(BINARY)

%.o: %.c
	@$(CC) $(HEADER) -c $(ERRFLAGS) -o $@ $<

$(BINARY): $(OBJ)
	@$(CC) $(HEADER) $(SRCS) $(ERRFLAGS) -o $(BINARY) $(LIBS)
	@echo "$(COLOR)Done\$(OFF)"

clean:
	@echo "$(COLOR)Removing object files$(OFF)"
	@make -C $(PRINTFPATH) clean
	@rm -rf $(OBJ)
	@echo "$(COLOR)Done$(OFF)"

fclean: clean
	@make -C $(PRINTFPATH) fclean
	@echo "$(COLOR)Removing binary and extraneous directories"
	@rm -rf $(BINARY)
	@echo "Done"

re: fclean all
