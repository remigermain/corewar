# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/07 13:02:13 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/06/10 18:58:42 by rgermain    ###    #+. /#+    ###.fr      #
#    Updated: 2019/06/10 16:16:03 by rcepre      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = corewar
TYPE = "de l'executable"

LIBFT_M :
	@make -C ../libft/ all

CFLAGS = -Wall -Werror -Wextra -O3
NCURSES = -L $(HOME)/.brew/lib/ -lSDL2 -lSDL2_ttf -lSDL2_mixer

INCLUDE = -Iincludes -I../libft/includes -I../shared_includes -I$(HOME)/.brew/include

HEADER = corewar.h corewar_enum.h

LIBFT = ../libft/libft.a

CC = clang

OBJ = $(SRC:.c=.o)

DSRC = srcs/
DOBJ = obj/
MDOBJ = obj/ obj/tools
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

SRC =	main.c \
		cw_flags.c \
		cw_flags2.c \
		cw_read_player.c \
		cw_check_define.c \
		cw_vm.c \
	  	utils_get_op_tab.c \
		cw_display_instruction.c  \
	 	cw_process.c \
		cw_initplayer.c \
		cw_read_instructions.c \
		cw_execute_instructions.c \
		cw_instructions1.c \
		cw_instructions2.c \
		cw_instructions3.c \
		cw_instructions_tools.c \
		tools/utils.c  \
		tools/verbo_funct.c \
		tools/tools_bits.c \
		tools/cw_error.c \
		tools/cw_error_2.c \
		cw_sdl.c \
		cw_sdl_events.c \
		cw_sdl_put.c \
		cw_sdl_utils.c \
		cw_sdl_put_info_gl.c \
		cw_sdl_put_info_players.c \
		cw_sdl_responsive.c \
		cw_sdl_put_bytes.c \
		cw_sdl_commodore.c \
		cw_sdl_alphabet.c \
		cw_sdl_animation.c \
		cw_sdl_intro_outro.c \

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
 ESC = $(shell printf '\033')

print_name :
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf " \033[47m  \033[0m\033[37m                    [    VM_CORE    ]            "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf "\n----------------------------------------------------------------------\n\n"

print_norme :
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf " \033[47m  \033[0m\033[37m                 [   VM_CORE NORME     ]          "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf "\n----------------------------------------------------------------------\n\n"

all: LIBFT_M print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

$(NAME): $(COBJ) $(LIBFT)
	@echo $(SPACE)"\033[JCompilation is \033[38;5;326m finish\033[0m"
	@echo $(SPACE)"Compilation" $(TYPE) "\033[34m" $(NAME) "\033[0m"
	@$(CC) $(COBJ) $(CFLAGS) $(NCURSES) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) $(LIBFT)
	@$(eval COUNT = "0")
	@mkdir -p $(MDOBJ)
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
