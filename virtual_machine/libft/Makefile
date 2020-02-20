# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dfreire <dfreire@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/20 09:51:27 by dfreire        #+#    #+#                 #
#    Updated: 2020/01/29 16:11:45 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = -I./includes

FT_PRINTF = ft_printf.c initialise_varargs.c getting_flags.c\
	print_parsed_values.c ctostr.c handling_o.c handling_x.c handling_u.c\
	handling_f.c handling_di.c handling_p.c handling_c.c print_null.c\
	getting_fmt.c handling_flags.c support_functions.c\
	handling_precision_width.c

LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c\
	ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
	ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
	ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_memdup.c\
	ft_whitespace.c ft_swap.c ft_caesarcipher.c ft_caesarcipher_decrypt.c\
	ft_sqrt.c ft_count_if.c ft_writeincolours.c ft_strndup.c ft_numlen.c\
	ft_numlen_base.c ft_itoa_base.c ft_ftoa.c ft_putchar_int.c ft_putnbr_base.c\
	ft_put_pointer.c ft_putstr_int.c ft_int_to_array.c ft_put_binary.c\
	ft_atof.c get_next_line.c ft_strarrdel.c ft_isprime.c ft_isnumber.c\
	ft_strlchr.c

.PHONY: all clean fclean re

COLOR = \033[1;34m
OFF = \033[0m

OBJDIR = objects

FT_PRINTF_SRCS = $(addprefix srcs/ft_printf/,$(FT_PRINTF))

LIBFT_SRCS = $(addprefix srcs/,$(LIBFT))

SRCS = $(LIBFT_SRCS) $(FT_PRINTF_SRCS)

OBJECTS = $(LIBFT:.c=.o) $(FT_PRINTF:.c=.o)

OBJS = $(addprefix $(OBJDIR)/, $(OBJECTS))

VPATH = srcs:srcs/ft_printf

all: $(NAME)

$(NAME): $(OBJS)
		@echo "$(COLOR)Creating $(NAME)$(OFF)"
		@ar src $@ $(OBJS)
		@ranlib $@

$(OBJDIR):
		@mkdir $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
		@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
		@echo "$(COLOR)Removing vm library objects$(OFF)"
		@/bin/rm -f $(OBJS)
		@rm -rf $(OBJDIR)

fclean: clean
		@echo "$(COLOR)Removing $(NAME)$(OFF)"
		@/bin/rm -f $(NAME)

re: fclean all
