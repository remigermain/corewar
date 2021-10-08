# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/06/19 20:14:48 by rcepre      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = asm
TYPE = "of the executable"

CFLAGS = -Wall -Werror 

INCLUDE = -Iincludes -I../libft/includes -I../shared_includes

HEADER = asm.h asm_str.h

CC = gcc
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
			../shared_includes/op.h \
			../shared_includes/cw_colors.h \

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

SRC =	display.c \
		display2.c \
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
		g_str.c \

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')

print_name : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                    [    ASM_CORE    ]           "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"

print_norme : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                    [   ASM NORME     ]          "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"


all: LIBFT_M print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
	echo -e $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

$(NAME): $(COBJ)
	@echo -e $(SPACE)"\033[JCompilation\033[38;5;326m completed\033[0m"
	@echo -e $(SPACE)"Compilation" $(TYPE) "\033[34m" $(NAME) "\033[0m"
	@$(CC) $(COBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) $(LIBFT)
	@$(eval COUNT = "0")
	@mkdir -p $(DOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo -e $(SPACE)"Compilation from function\033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean: print_name
	@rm -rf $(DOBJ)
	@echo -e $(SPACE)"Deleting \033[38;5;265mobjects\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo -e $(SPACE)"Deleting \033[38;5;265m"$(NAME) "\033[0m"

re: print_name
	@rm -f $(NAME)
	@rm -rf $(DOBJ)
	@echo -e $(SPACE)"Deleting \033[38;5;265m"$(NAME) "\033[0m"
	@echo -e $(SPACE)"Deleting \033[38;5;265mobjects\033[0m"
	@make all

norme : print_norme
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

normeall : norme

.PHONY: default all fclean clean_f fclean re re_clean norme normeall print_norme print_name
