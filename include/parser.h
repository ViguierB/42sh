/*
** parser.h for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Apr  3 18:05:31 2017 Benjamin Viguier
** Last update Thu May 18 16:15:07 2017 Guilhem Fulcrand
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "mysh.h"

# define NEED_FD 0x4
# define ALW_IN 0x8
# define ALW_OUT 0x10
# define NEED_WORD 0x20

# define CAST_OPFCT(fct) ((int (*)(t_mysh*, t_tree*, t_exec_opts*)) fct)
# define ISNUM(x) (((x) >= '0') && ((x) <= '9'))

# define MIN_SEP 7

/*
** 0  : NULL
** 1  : commande
** 2  : <
** 3  : >
** 4  : >>
** 5  : <<
** 6  : <>
** 7  : ||
** 8  : &&
** 9  : |
** 10 : ;
*/

typedef enum	e_type
  {
    END_ENUM	= 0,
    CMD		= 1,
    IREDIR	= 2,
    OREDIR	= 3,
    APPEND	= 4,
    READWHILE	= 5,
    DUPLICATE	= 6,
    OPOR	= 7,
    OPAND	= 8,
    PIPE	= 9,
    NEXTCMD	= 10,
  }		t_type;

typedef enum	e_mode_type
  {
    NODE_CMD,
    NODE_SEP,
    NODE_UNKNOW
  }		t_node_type;

typedef struct	t_op_flags
{
  t_type	type;
  char		*str;
  int		opts;
  void		*fct;
}		t_op_flags;

typedef struct	s_sepinfo
{
  t_type	type;
  int		is_sep;
  int		to_ecrase;
  char		*ident;
  char		*sep;
  void		*fct;
  int		opt;
  int		len;
  int		fd_value;
}		t_sepinfo;

typedef union	u_token_value
{
  char		*cmd;
  t_sepinfo	info;
}		t_token_value;

typedef struct	s_token
{
  t_type	type;
  t_token_value	value;
}		t_token;

typedef struct	s_sep_prio
{
  t_type	type;
  int		prio;
}		t_sep_prio;

typedef union	s_tree_elm
{
  t_process	proc;
  t_token	token;
}		t_tree_elm;

typedef struct	s_tree
{
  t_node_type	type;
  t_tree_elm	value;
  int		fda;
  int		fdb;
  struct s_tree	*r;
  struct s_tree	*l;
}		t_tree;

typedef struct	t_exec_opts
{
  int		need_redir;
  int		pipe_in[2];
  int		pipe_out[2];
  int		pipe_err[2];
  int		ascyn;
  int		exit_code;
}		t_exec_opts;

t_tree	*parse_cmd(char *cmd);
int	get_tokens(char *cmd, t_clist **list, const t_op_flags *flags);
char	*get_block(char *cur, t_strbuilder *sb);
void	free_tree(t_tree *node);
int	execute_tree(t_mysh *sh, t_tree *tree, t_exec_opts *opts);
int	parse_cmd_args(t_process *proc, char *cmd);
int	parse_simple_cmd(t_process *proc, t_token *token);
char*	get_real_cmd(t_mysh *sh, t_process *proc);
int is_builtin(char *name);
int exec_builtin(t_mysh *mysh, t_process *proc, t_exec_opts *opts);
int globbing(char ***args);
int preparsing(t_mysh *mysh, char ***);
char *true_preparsing(t_mysh *mysh, char *cmd);
char *search_in_path(t_mysh *, char *);
char *search_in_all_paths(t_mysh *sh, char *name);

int	op_or(t_mysh *sh, t_tree *node, t_exec_opts *opts);
int	op_and(t_mysh *sh, t_tree *node, t_exec_opts *opts);
int	op_pipe(t_mysh *sh, t_tree *node, t_exec_opts *opts);
int	op_next(t_mysh *sh, t_tree *node, t_exec_opts *opts);

#endif /* !PARSER_H_ */
