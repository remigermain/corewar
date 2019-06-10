# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/06/10 16:12:57 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/06/10 16:58:47 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

CC= gcc

CFLAGS= -Wall -Wextra -Werror -g3 

SRC = 					srcs/ft_atoi.c\
						srcs/ft_bzero.c\
						srcs/ft_isalnum.c\
						srcs/ft_isalpha.c\
						srcs/ft_isascii.c\
						srcs/ft_isdigit.c\
						srcs/ft_isprint.c\
						srcs/ft_itoa.c\
						srcs/ft_lstadd.c\
						srcs/ft_lstdel.c\
						srcs/ft_lstdelone.c\
						srcs/ft_lstiter.c\
						srcs/ft_lstmap.c\
						srcs/ft_lstnew.c\
						srcs/ft_memalloc.c\
						srcs/ft_memccpy.c\
						srcs/ft_memchr.c\
						srcs/ft_memcmp.c\
						srcs/ft_memcpy.c\
						srcs/ft_memdel.c\
						srcs/ft_memmove.c\
						srcs/ft_memset.c\
						srcs/ft_putchar.c\
						srcs/ft_putchar_fd.c\
						srcs/ft_putendl.c\
						srcs/ft_putendl_fd.c\
						srcs/ft_putnbr.c\
						srcs/ft_putnbr_fd.c\
						srcs/ft_putstr.c\
						srcs/ft_putstr_fd.c\
						srcs/ft_strcat.c\
						srcs/ft_strchr.c\
						srcs/ft_strchri.c\
						srcs/ft_strclr.c\
						srcs/ft_strcmp.c\
						srcs/ft_strcpy.c\
						srcs/ft_strdel.c\
						srcs/ft_strdup.c\
						srcs/ft_strequ.c\
						srcs/ft_striter.c\
						srcs/ft_striteri.c\
						srcs/ft_strjoin.c\
						srcs/ft_strlcat.c\
						srcs/ft_strlen.c\
						srcs/ft_strmap.c\
						srcs/ft_strmapi.c\
						srcs/ft_strncat.c\
						srcs/ft_strncmp.c\
						srcs/ft_strncpy.c\
						srcs/ft_strnequ.c\
						srcs/ft_strnew.c\
						srcs/ft_strnstr.c\
						srcs/ft_strrchr.c\
						srcs/ft_strsplit.c\
						srcs/ft_strstr.c\
						srcs/ft_strsub.c\
						srcs/ft_strtrim.c\
						srcs/ft_tolower.c\
						srcs/ft_toupper.c\
						srcs/ft_islower.c\
						srcs/ft_isupper.c\
						srcs/ft_strcountwords.c\
						srcs/ft_strndup.c\
						srcs/ft_dbstr_to_strlst.c\
						srcs/ft_lstcount.c\
						srcs/ft_putdbstr.c\
						srcs/ft_putstrlst.c\
						srcs/ft_putcolor.c\
						srcs/ft_strlst_to_dbstr.c\
						srcs/ft_sorttab.c\
						srcs/ft_puttab.c\
						srcs/ft_iswhitespace.c\
						srcs/ft_freedbtab.c\
						srcs/ft_strnjoin.c\
						srcs/ft_realloc.c\
						srcs/ft_strfsub.c\
						srcs/ft_getchar.c \
						srcs/ft_countchr.c \
						srcs/ft_pow.c \
						srcs/ft_strnrev.c \
						srcs/ft_strtol.c \
						srcs/get_next_line.c \
						srcs/ft_lltoa.c \
						srcs/ft_ulltoa.c \
						srcs/ft_strupcase.c\
						srcs/ft_lllen.c \
						srcs/ft_ulllen.c  \
						srcs/ft_options.c \
						srcs/ft_strspn.c \
						srcs/ft_strcspn.c \
						srcs/ft_reverse_uint_bytes.c \
						srcs/ft_strlastchr.c \
						srcs/ft_strrev.c \
						srcs/ft_strvalids.c \
						srcs/ft_abs.c \
						srcs/ft_str_is_digit.c

HEADER = ./includes/
INCLUDE = includes/libft.h $(ft_printf_PATH)includes/ft_printf.h

ft_printf_OBJECTS =   	srcs/ft_printf/srcs/conv_char.o \
						srcs/ft_printf/srcs/conv_double.o \
						srcs/ft_printf/srcs/conv_int.o \
						srcs/ft_printf/srcs/conv_other.o \
						srcs/ft_printf/srcs/conv_string.o \
						srcs/ft_printf/srcs/conv_tabstring.o \
						srcs/ft_printf/srcs/ft_printf.o \
						srcs/ft_printf/srcs/ft_stprintf.o \
						srcs/ft_printf/srcs/lst_putdouble.o \
						srcs/ft_printf/srcs/lst_putoption.o \
						srcs/ft_printf/srcs/put_string.o \
						srcs/ft_printf/srcs/utils.o \
						srcs/ft_printf/srcs/ft_countwchar.o \
						srcs/ft_printf/srcs/ft_strudup.o \
						srcs/ft_printf/srcs/ft_strlen4.o

.DEFAULT_GOAL := all
COUNT = "1"
SPACE = "                    "
ESC = $(shell printf '\033')

print_name :
	@echo "\n----------------------------------------------------------------------\n\033[37m"
	@echo " \033[47m  \033[0m\033[37m                    [    LIBFT     ]                     \033[0m  \033[47m  \033[0m"
	@echo "\n----------------------------------------------------------------------\n"

print_norme :
	@echo "\n----------------------------------------------------------------------\n\033[37m"
	@echo " \033[47m  \033[0m\033[37m                    [    LIBFT   NORME  ]                     \033[0m  \033[47m  \033[0m"
	@echo "\n----------------------------------------------------------------------\n"

all: print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

OBJECT = $(SRC:.c=.o)

ft_printf_PATH = srcs/ft_printf/

#TEXT

		RED = \033[1;31m
		WHITE = \033[0;29m
		YELLOW = \033[1;33m
		PINK = \033[1;35m
		GREEN = \033[1;32m

		RM_OBJ = "$(YELLOW)libft:\t\t$(RED)rm $(YELLOW)objects\t\t$(GREEN)[OK]\033[1m"
		RM_LIB = "$(YELLOW)libft:\t\t$(RED)rm $(YELLOW)libft.a\t\t$(GREEN)[OK]\033[1m"


$(NAME): $(OBJECT) $(HEADER)
	@$(eval COUNT = "0")
	@echo "\t\033[0;36m#########$(RED)ft_printf\033[0;36m#########"
	@(cd $(ft_printf_PATH) && make)
	@ar rc $(NAME) $(OBJECT) $(ft_printf_OBJECTS)
	@ranlib $(NAME)

%.o: %.c $(INCLUDE)
	@printf "\e[2K\r\033[0;36m>>>\tCompiling:$@ ...\t"
	@$(CC) -c $(CFLAGS) -I $(HEADER) $<
	@mv $(notdir $(basename $<)).o ./srcs/
	$(PRINT_OK)

clean : print_name
	@(cd $(ft_printf_PATH) && make clean)
	@rm -rf $(OBJECT)
	@echo $(RM_OBJ)

clean_exe:
	@rm -rf $(NAME)
	@echo $(RM_LIB)

fclean: clean clean_exe

re: fclean all
	@(cd $(ft_printf_PATH) && make re)

norme_printf :
	@make norme -C $(ft_printf_PATH)

norme : norme_printf print_norme
	@norminette $(SRC) $(HEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

.PHONY: clean fclean norme norme_printf re clean_exe
