# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/06/19 18:32:39 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#
NAME_ASM = asm
NAME_VM = corewar
NAME_DSM = dsm

DVM = vm_dir/
DASM = asm_dir/
DDSM = dsm_dir/
DLIBFT = libft/

ASM = $(addprefix $(DASM),$(NAME_ASM))
VM = $(addprefix $(DVM), $(NAME_VM))
DSM = $(addprefix $(DDSM), $(NAME_DSM))

.DEFAULT_GOAL := all

###########################################################
##						bse								 ##
###########################################################

all: libft asm corewar dsm

clean: libft_clean corewar_clean dsm_clean asm_clean

fclean: libft_fclean asm_fclean corewar_fclean dsm_fclean
	@rm -rf $(NAME_ASM) $(NAME_VM) $(NAME_DSM)

re: fclean print_name all

norme : corewar_norme asm_norme dsm_norme

normeall : norme
	@make -C $(DLIBFT) norme

#############################################################


############################################################
##						external						 ##
############################################################

libft:
	@make -C $(DLIBFT)
asm:
	@make -C $(DASM)
	@cp $(ASM) .
corewar:
	@make -C $(DVM)
	@cp $(VM) .
dsm:
	@make -C $(DDSM)
	@cp $(DSM) .

############################################################

libft_clean:
	@make -C $(DLIBFT) clean
asm_clean:
	@make -C $(DASM) clean
corewar_clean:
	@make -C $(DVM) clean
dsm_clean:
	@make -C $(DDSM) clean

############################################################

libft_fclean:
	@make -C $(DLIBFT) fclean
asm_fclean:
	@make -C $(DASM) fclean
corewar_fclean:
	@make -C $(DVM) fclean
dsm_fclean:
	@make -C $(DDSM) fclean

############################################################

libft_re:
	@make -C $(DLIBFT) re
asm_re:
	@make -C $(DASM) re
corewar_re:
	@make -C $(DVM) re
dsm_re:
	@make -C $(DDSM) re

#############################################################

libft_norme:
	@make -C $(DLIBFT) norme
corewar_norme:
	@make -C $(DVM) norme
asm_norme:
	@make -C $(DASM) norme
dsm_norme:
	@make -C $(DDSM) norme

#############################################################
#############################################################

.PHONY: default all clean fclean re norme normeall print_norme print_name asm asm_clean asm_fclean asm_re corewar asm_clean corewar_fclean corewar_re dsm dsm_clean dsm_fclean corewar_norme asm_norme dsm_nome
