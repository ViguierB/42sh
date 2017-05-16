##
## Makefile for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/history/
##
## Made by Guilhem Fulcrand
## Login   <guilhem.fulcrand@epitech.eu>
##
## Started on  Fri May  5 18:32:27 2017 Guilhem Fulcrand
## Last update Mon May 15 17:59:49 2017 Guilhem Fulcrand
##

CC			=		gcc

CFLAGS		=		-W -Wall -Werror -Wextra
CFLAGS		+=		-I../include
CFLAGS		+=		-g

SRC			=		main.c 				\
					tools.c

OBJ			=		$(SRC:.c=.o)

NAME		=		42shrc

LIB			=		make -C ../

INCLUDE 	= 		-L../lib/my -lmy

all:				$(NAME)

$(NAME):			$(OBJ)
					$(LIB)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

clean:
					$(LIB) clean
					rm -f $(OBJ)

fclean:				clean
					$(LIB) fclean
					rm -f $(NAME)

re: 				fclean all
