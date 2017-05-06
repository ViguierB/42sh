##
## Makefile for tetris in /home/benji_epitech/C_Graph_Prog/wolf3d
##
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
##
## Started on  Wed Dec  7 12:45:32 2016 Benjamin Viguier
## Last update Sat May  6 23:44:28 2017 Alexandre Chamard-bois
##

include ./include/depend.mk

SRC	= 	main.c		\
		build_tree.c	\
		parser.c	\
		error.c		\
		env.c		\
		env_ext.c	\
		op_and.c	\
		redir_parser.c	\
		parse_argv.c	\
		execute.c	\
		utils.c		\
		globbing1.c		\
		globbing2.c		\
		get_path.c

MKLIB	=	make -C ./lib/my/

CFLAGS	+=	-I./include/

LDFLAGS	=	-L./lib/my/ -lmy

_OBJ	=	$(SRC:.c=.o)

OBJ	=	$(patsubst %,$(ODIR)/%,$(_OBJ))

NAME	=	42sh

all		:	$(NAME)

$(ODIR)/%.o	:	$(SDIR)/%.c
	$(CC) $(CFLAGS)	-c -o $@ $<

mkobj		:
	./tools/verif_objdir

$(NAME)		:	mkobj mlib $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean		:
	rm -f $(OBJ)

fclean		:	clean
	rm -f $(NAME)

ffclean		:	fclib fclean

re		:	fclib fclean all

full		:	fclean all

fclib		:
	$(MKLIB) fclean

mlib		:
	$(MKLIB)
