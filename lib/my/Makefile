##
## EPITECH PROJECT, 2019
## my_rpg
## File description:
## Libmy Makefile
##

CC 			= 	gcc

SRC			=	my_strcmp.c \
				my_strlen.c \
				my_atoi.c \
				my_strtol.c \
				my_strarr_len.c \
				my_strarr_free.c \
				my_count_char.c \
				my_count_until_sep.c \
				my_str_to_word_array.c \
				my_strdup.c \
				my_strdupcat.c \
				my_puterr.c \
				my_sdup.c \
				my_str_ends.c \
				my_str_isnum.c \
				my_strarr_dup.c \

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror

DBFLAGS		=	-g -g3 -ggdb

HEADER		=	my.h

NAME		=	libmy.a

all:		$(OBJ)
			ar rc $(NAME) $(OBJ)
			cp $(NAME) ../
			cp $(HEADER) ../../include

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)
			rm -f ../$(NAME)
			rm -f ../../include/$(HEADER)

re:			fclean all

.phony:		re fclean clean
