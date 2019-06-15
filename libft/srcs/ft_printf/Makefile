# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2019/06/11 13:31:24 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

GRAPHIC = no

CC= clang

CFLAGS= -Wall -Wextra -Werror

SRC =   srcs/conv_char.c \
		srcs/conv_double.c \
		srcs/conv_int.c \
		srcs/conv_other.c \
		srcs/conv_string.c \
		srcs/conv_tabstring.c \
		srcs/ft_printf.c \
		srcs/ft_stprintf.c \
		srcs/lst_putdouble.c \
		srcs/lst_putoption.c \
		srcs/put_string.c \
		srcs/utils.c \
		srcs/ft_countwchar.c \
		srcs/ft_strudup.c \
		srcs/ft_strlen4.c 


HEADER = ./includes/.

INCLUDE = includes/ft_printf.h

OBJECT = $(SRC:.c=.o)

LIBFT_PATH = ./libft/.
.DEFAULT_GOAL := all
COUNT = "1"
ESC = $(shell printf '\033')

################################# RULES ########################################
print_name :
	@echo "\033[0m\n----------------------------------------------------------------------\n\033[37m"
	@echo " \033[47m  \033[0m\033[37m                    [    FT_PRINTF     ]                      \033[0m  \033[47m  \033[0m"
	@echo "\n----------------------------------------------------------------------\n"

all: print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

$(NAME): $(OBJECT) $(HEADER)
	@echo ""

%.o: %.c $(INCLUDE)
	@$(eval COUNT = "0")
	@printf "\e[2K\r\033[0;36m>>>\tCompiling:$@ ...\t"
	@$(CC) -c $(CFLAGS) -I $(HEADER) $<
	@mv $(notdir $(basename $<)).o ./srcs/


clean:
	$(PRINT_RM_OBJ)
	@rm -rf $(OBJECT)
	$(PRINT_OK)

clean_exe:
	@rm -rf $(NAME)

fclean: clean clean_exe

re: fclean all

norme :
	@norminette $(SRC) $(HEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

.PHONY: clean fclean norme

	################################# TEXT  ########################################

RED = \033[1;31m
WHITE = \033[0;29m
YELLOW = \033[1;33m
PINK = \033[1;35m
PRINT_OK  = @printf "\033[1;32m[OK]$(WHITE)\n"
PRINT_MAKE_LIB = @printf "\t$(YELLOW)create libft ...\t\t"
PRINT_MAKE_libftprintf = @printf "\t$(YELLOW)create libftprintf ...\t\t"
PRINT_RM_OBJ = @printf "\033[1;33mprintf:\t\t$(RED)rm $(YELLOW)objects\t\t$(WHITE)"
PRINT_RM_LIB_OBJ = @printf "\t$(RED)rm $(YELLOW)libft objects\t\t$(WHITE)"
PRINT_RM_LIBFT = @printf "\t$(RED)rm $(YELLOW)libft.a\t\t\t$(WHITE)"
PRINT_RM_EXEC = @printf "\t$(RED)rm $(YELLOW)libftprintf.a\t\t$(WHITE)"
