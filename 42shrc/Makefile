##
## Makefile for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/history/
##
## Made by Guilhem Fulcrand
## Login   <guilhem.fulcrand@epitech.eu>
##
## Started on  Fri May  5 18:32:27 2017 Guilhem Fulcrand
## Last update Fri May 12 18:37:50 2017 Guilhem Fulcrand
##

CC			=		gcc

CFLAGS		=		-W -Wall -Werror -Wextra
CFLAGS		+=		-I../include
CFLAGS		+=		-g

SRC			=		main.c

OBJ			=		$(SRC:.c=.o)

NAME		=		42shrc

LIB			=		make -C ../

INCLUDE 	= 		-L../lib/my -lmy

all:				$(NAME)

$(NAME):			$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(INCLUDE)

clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)

re: 				fclean all
