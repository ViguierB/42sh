##
## Makefile for tetris in /home/benji_epitech/C_Graph_Prog/wolf3d
##
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
##
## Started on  Wed Dec  7 12:45:32 2016 Benjamin Viguier
<<<<<<< HEAD
## Last update Tue May 16 16:11:01 2017 Guilhem Fulcrand
=======
## Last update Tue May 16 13:47:08 2017 Alexandre Chamard-bois
>>>>>>> 8cf660bff9ce7d947ab5d456c793d433a99a7fc6
##

include ./include/depend.mk

SRC	= 	main.c		\
		build_tree.c	\
		parser.c	\
		alias.c		\
		my_source.c	\
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
		get_path.c	\
		builtins.c	\
		builtin_crochet.c	\
		crochet_flags1.c	\
		crochet_flags2.c	\
		my_echo.c	\
		my_cd.c	\
		my_exit.c	\

MKLIB	=	make -C ./lib/my/

CFLAGS	+=	-I./include/

LDFLAGS	=	-L./lib/my/ -lmy

_OBJ	=	$(SRC:.c=.o)

OBJ	=	$(patsubst %,$(ODIR)/%,$(_OBJ))

NAME	=	42sh

all		:	mkobj mlib $(NAME)

$(ODIR)/%.o	:	$(SDIR)/%.c
	$(CC) $(CFLAGS)	-c -o $@ $<

mkobj		:
	./tools/verif_objdir

$(NAME)		:	$(OBJ)
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
