# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rcepre <rcepre@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/07 09:01:58 by rcepre       #+#   ##    ##    #+#        #
#    Updated: 2019/06/10 16:41:38 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

GRAPHIC = no

CC= clang

CFLAGS= -Wall -Wextra -Werror -g

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

OBJECT = $(SRC:.c=.o)

LIBFT_PATH = ./libft/.

################################# RULES ########################################

all: $(NAME)

$(NAME): $(OBJECT) $(HEADER)


%.o: %.c
	@printf "\e[2K\r\033[0;36m>>>\tCompiling:$? ...\t"
	@$(CC) -c $(CFLAGS) -I $(HEADER) $?
	@mv $(notdir $(basename $?)).o ./srcs/


clean:
	$(PRINT_RM_OBJ)
	@rm -rf $(OBJECT)
	$(PRINT_OK)

clean_exe:
	@rm -rf $(NAME)

fclean: clean clean_exe

re: fclean all

.PHONY: clean fclean

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
