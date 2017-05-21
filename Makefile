##
## Makefile for tetris in /home/benji_epitech/C_Graph_Prog/wolf3d
##
## Made by Benjamin Viguier
## Login   <benjamin.viguier@epitech.eu>
##
## Started on  Wed Dec  7 12:45:32 2016 Benjamin Viguier
## Last update Sun May 21 20:06:46 2017 alexandre Chamard-bois
##

include ./include/depend.mk

SRC	= 	main.c			\
		history.c		\
		build_tree.c		\
		parser.c		\
		check_var.c		\
		alias.c			\
		true_preparsing.c	\
		permissions.c		\
		which.c			\
		my_source.c		\
		error.c			\
		env.c			\
		env_ext.c		\
		op_and.c		\
		op_pipe.c		\
		redir_parser.c		\
		parse_argv.c		\
		execute.c		\
		utils.c			\
		globbing1.c		\
		globbing2.c		\
		get_path.c		\
		builtins.c		\
		builtin_crochet.c	\
		crochet_flags1.c	\
		crochet_flags2.c	\
		my_echo.c		\
		my_cd.c			\
		my_exit.c		\
		preparsing.c		\
		var.c			\
		var_last_ret.c		\
		print_env.c		\
		my_setenv.c		\
		do_cmd.c		\
		if.c			\
		recup_parentheses.c	\
		wordtab_to_str.c	\
		condition.c		\
		repeat.c		\
		foreach.c		\
		script.c		\
		magic_quote.c		\
		print_prompt.c		\

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
