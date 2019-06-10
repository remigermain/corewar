# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/06/10 17:24:20 by rcepre      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = asm
TYPE = "de l'executable"

CFLAGS = -Wall -Werror -Wextra -g3

INCLUDE = -Iincludes -I../libft/includes -I../shared_includes

HEADER = asm.h asm_errors_str.h colors.h

CC = clang
LIBFT = ../libft/libft.a

LIBFT_M : 
		@make -C ../libft all

OBJ = $(SRC:.c=.o)

DSRC = srcs/
DOBJ = obj/
ALL_D = $(DSRC)

DHEADER = includes/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER = $(addprefix $(DHEADER),$(HEADER)) \
			../libft/includes/libft.h \
			../libft/srcs/ft_printf/includes/ft_printf.h \
			../shared_includes/op.h \
			../shared_includes/cw_colors.h \

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

SRC =	display.c \
		asm.c \
		get_header.c \
		parsing_errors.c \
		parsing_ins.c \
		parsing_ins_arguments.c \
		parsing_ins_arguments_value.c \
		parsing_ins_arguments_value_check.c \
		parsing_ins_get_opcode.c \
		parsing_labels.c \
		parsing_labels_utils.c \
		parsing_labels_check.c \
		parsing_labels_name.c \
		pasing_memory.c \
		read_file.c \
		t_linelst.c \
		utils.c \
		utils_get_op_tab.c \
		output.c \
		output_prog.c \
		input.c \
		input_utils.c \

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')

print_name : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                    [    ASM      ]              "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"

print_norme : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                 [   ASM NORME     ]          "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"


all: LIBFT_M print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

$(NAME): $(COBJ)
	@echo $(SPACE)"\033[JCompilation des Objects \033[38;5;326mterminée.\033[0m"
	@echo $(SPACE)"Compilation" $(TYPE) "\033[34m" $(NAME) "\033[0m"
	@$(CC) $(COBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) $(LIBFT_R)
	@$(eval COUNT = "0")
	@mkdir -p $(DOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(SPACE)"compilation de la fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean: print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo $(SPACE)"Suppresion "$(TYPE) "\033[38;5;265m"$(NAME) "\033[0m"

re: fclean print_name $(NAME)

norme : print_norme
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

normeall : norme

.PHONY: default all fclean clean_f fclean re re_clean norme normeall print_norme print_name
