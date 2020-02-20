# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bbremer <bbremer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/29 16:16:18 by bbremer        #+#    #+#                 #
#    Updated: 2020/01/29 16:39:49 by bbremer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

VM = corewar
ASM = asm
ASMPATH = assembler/
VMPATH = virtual_machine/
DISPATH = disassembler/

all: make  

make:
	@make -C $(ASMPATH)
	@make -C $(VMPATH)
	@make -C $(DISPATH)

clean:
	@make -C $(ASMPATH) clean
	@make -C $(VMPATH) clean
	@make -C $(DISPATH) clean

fclean: clean
	@make -C $(ASMPATH) fclean
	@make -C $(VMPATH) fclean
	@make -C $(DISPATH) fclean

re: fclean all