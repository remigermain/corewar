# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/06/13 13:49:34 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = dsm
TYPE = "of the executable"

LIBFT_M :
	@make -C ../libft/ all

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes -I../libft/includes -I../shared_includes

HEADER = dsm.h dsm_enum.h

LIBFT = ../libft/libft.a

OBJ = $(SRC:.c=.o)

DSRC = srcs/
DOBJ = obj/
MDOBJ = obj/ obj/tools obj/visu
ALL_D = $(DSRC)

DHEADER = includes/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER =	$(addprefix $(DHEADER),$(HEADER)) \
			../libft/includes/libft.h \
			../libft/srcs/ft_printf/includes/ft_printf.h \
			../shared_includes/op.h \
			../shared_includes/cw_colors.h \

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

SRC =	main.c \
		dsm_main.c \
	  	utils_get_op_tab.c \
		dsm_read_instructions.c \
		dsm_convert_labels.c \
		dsm_put_file.c \
		tools_bits.c \
		dsm_error.c 

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')

print_name : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                    [    DSM_CORE    ]           "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"

print_norme : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                    [   DSM NORME     ]          "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"


all: LIBFT_M print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

$(NAME): $(COBJ) $(LIBFT)
	@echo $(SPACE)"\033[JCompilation\033[38;5;326m completed\033[0m"
	@echo $(SPACE)"Compilation" $(TYPE) "\033[34m" $(NAME) "\033[0m"
	@clang $(COBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) $(LIBFT)
	@$(eval COUNT = "0")
	@mkdir -p $(MDOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@clang $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(SPACE)"Compilation from fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean: print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Deleting \033[38;5;265mobjects\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo $(SPACE)"Deleting \033[38;5;265m"$(NAME) "\033[0m"

re: print_name
	@rm -f $(NAME)
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Deleting \033[38;5;265m"$(NAME) "\033[0m"
	@echo $(SPACE)"Deleting \033[38;5;265mobjects\033[0m"
	@make all

norme : print_norme
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

normeall : norme

.PHONY: default all fclean clean_f fclean re re_clean norme normeall print_norme print_name
