/*
** mysh.h for mysh in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Sun Mar 19 19:59:51 2017 Benjamin Viguier
** Last update Sat May 20 19:47:33 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "var.h"

#ifndef MYSH_H_
# define MYSH_H_

# ifndef TRUE
#  define TRUE 1
# endif /* !TRUE */

# ifndef FALSE
#  define FALSE 0
# endif /* !FALSE */

typedef struct	s_mysh_fd
{
  int		fd;
  char		*filename;
  int		flags;
  int		right;
}		t_mysh_fd;

typedef struct	s_process
{
  int		pid;
  char		*name;
  char		**args;
  char		**env;
  t_mysh_fd	in;
  t_mysh_fd	out;
  t_mysh_fd	err;
  int		builtin;
  int		redir_type;
}		t_process;

typedef struct	s_mysh
{
  t_clist	*env;
  t_clist   *hist;
  t_clist	*alias;
  t_var		*var;
  int		last_exit;
  int		exit;
  t_my_fd	*in;
}		t_mysh;

typedef struct	s_builtin
{
  char		*name;
  int     (*func)(char **tab, t_mysh *mysh);
}		t_builtin;

int main_script(int ac, char **av, t_mysh *sh);
int is_permited(char *path);
int is_file(char *name);
int	is_local_cmd(char *name);
void print_prompt(t_mysh *sh);
int	fexists(char *name);
void	wait_child(t_mysh *sh, t_process *proc);
char *wordtab_to_str(char **tab);
void var_last_ret(t_mysh *mysh);
int var_set(t_mysh *mysh, char *key, char *value);
void var_set_env(t_mysh *mysh, char *key, char *value);
void print_var(t_mysh *mysh);
t_clist *my_history();
void write_hist(t_clist *hist);
void print_hist(t_clist *hist);
t_clist *push_in_hist(t_clist *hist, char *cmd);
int do_cmd(t_mysh *sh, char *cmd);

/*
** ERROR functions
*/

int	my_echo(char **av, t_mysh *sh);
int my_cd(char **tab, t_mysh *sh);
int my_set(char **tab, t_mysh *sh);
int my_print_env(char **tab, t_mysh *mysh);
int	my_ssetenv(char **tab, t_mysh *sh);
int	my_unsetenv(char **tab, t_mysh *sh);
int builtin_crochet(char **tab, t_mysh *sh);
int	my_exit(char **av, t_mysh *sh);
int my_which(char **av, t_mysh *sh);
int my_where(char **av, t_mysh *sh);
int my_alias(char **av, t_mysh *sh);
int my_if(char **tab, t_mysh *sh);
int		my_repeat(char **av, t_mysh *sh);
int my_foreach(char **tab, t_mysh *sh);

/*
** ERROR functions
*/

char	*my_name(int to_do, ...);
int	my_perror(char *str);
int	my_warning(char *str, char *to_print);
int	my_pwarning(char *str);
int	my_pcustomwarning(char *str, ...);

#endif /* !MYSH_H_ */
