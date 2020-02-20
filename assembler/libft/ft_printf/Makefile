# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/30 10:51:20 by lvan-vlo       #+#    #+#                 #
#    Updated: 2020/01/29 15:46:38 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include sources
include ../sources

NAME = libftprintf.a
ERRFLAGS = -Wall -Werror -Wextra
OBJS := ${SRC:.c=.o}
LNAMES = $(SRCS)
LSRCS :=${addprefix ../, $(LNAMES)}
LOBJS := ${LNAMES:.c=.o}
LOBJS :=${addprefix ../, $(LOBJS)}
COLOR = \033[1;36m
OFF = \033[0m

all: $(NAME)

%.o: %.c
	@gcc -c $(ERRFLAGS) -o $@ $<


$(NAME): $(LOBJS) $(OBJS)
	@echo "$(COLOR)Creating $(NAME)$(OFF)"
	@ar rc $(NAME) $(OBJS) $(LOBJS)

clean:
	@echo "$(COLOR)Removing printflibrary objects$(OFF)"
	@rm -f $(OBJS) $(LOBJS)

fclean: clean
	@echo "$(COLOR)Removing $(NAME)$(OFF)"
	@rm -f $(NAME)

re: fclean all