# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/06/05 19:25:49 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME_ASM = asm
NAME_VM = corewar
NAME_DSM = dsm

DVM = vm_dir/
DASM = asm_dir/
DDSM = dsm_dir/
ASM = $(addprefix $(DASM),$(NAME_ASM))
VM = $(addprefix $(DVM), $(NAME_VM))
DSM = $(addprefix $(DDSM), $(NAME_DSM))

DLIBFT = libft/

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')

all:
	@make -C $(DLIBFT)
	@make -C $(DVM)
	@make -C $(DASM)
	@make -C $(DDSM)
	@cp $(ASM) .
	@cp $(VM) .
	@cp $(DSM) .

clean:
	@make -C $(DLIBFT) clean
	@make -C $(DVM) clean
	@make -C $(DASM) clean
	@make -C $(DDSM) clean
	@rm -rf $(NAME_ASM) $(NAME_VM) $(NAME_DSM)

fclean:
	@make -C $(DLIBFT) fclean
	@make -C $(DVM) fclean
	@make -C $(DASM) fclean
	@make -C $(DDSM) fclean
	@rm -rf $(NAME_ASM) $(NAME_VM) $(NAME_DSM)

re_clean:
	@rm -rf $(NAME_ASM) $(NAME_VM)
	@make -C $(DLIBFT) re
	@make -C $(DVM) re
	@make -C $(DASM) re
	@make -C $(DDSM) re

re: fclean print_name all

norme :
	@make -C $(DVM) norme
	@make -C $(DASM) norme
	@make -C $(DDSM) norme

normeall : norme
	@make -C $(DLIBFT) norme

.PHONY: default all fclean clean_f fclean re re_clean norme normeall print_norme print_name
