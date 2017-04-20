/*
** redir_parser.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Apr  7 10:57:58 2017 Benjamin Viguier
** Last update Tue Apr 11 23:59:19 2017 Benjamin Viguier
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "parser.h"

const t_op_flags	g_redir_tab[] =
  {
    {READWHILE, "<<", ALW_IN | NEED_WORD | S_IN, NULL},
    {APPEND, ">>", ALW_OUT | NEED_WORD | S_OUT, NULL},
    {DUPLICATE, "<>", ALW_IN | NEED_WORD | S_IN, NULL},
    {OREDIR, ">", ALW_OUT | NEED_WORD | S_OUT, NULL},
    {IREDIR, "<", ALW_IN | NEED_WORD | S_IN, NULL},
    {END_ENUM, NULL, 0, NULL}
  };

void	set_process_redir(t_process *process, t_mysh_fd *fd)
{
  process->in = (t_mysh_fd) {S_IN, NULL, 0, 0};
  process->out = (t_mysh_fd) {S_OUT, NULL, 0, 0};
  process->err = (t_mysh_fd) {S_IN, NULL, 0, 0};
  if (fd->fd == S_IN)
    process->in = (t_mysh_fd) {S_IN, fd->filename, fd->flags, fd->right};
  if (fd->fd == S_OUT)
    process->out = (t_mysh_fd) {S_OUT, fd->filename, fd->flags, fd->right};
  if (fd->fd == S_ERR)
    process->err = (t_mysh_fd) {S_ERR, fd->filename, fd->flags, fd->right};
}

t_clist_elm	*parse_redir(t_clist *list, t_clist_elm *elm,
			     t_token *cur, t_process *process)
{
  t_mysh_fd	target_fd;
  char		*file;

  my_memset(&target_fd, 0, sizeof(target_fd));
  if ((cur->value.info.opt & NEED_WORD) &&
      (elm->next == list || ((t_token*) elm->next->ptr)->type != CMD))
    return ((void*) (long int)
	    (my_warning("parser", "Missing name for redirect.") & 0x0));
  file = my_strdup(((t_token*) elm->next->ptr)->value.cmd);
  if (cur->value.info.opt & ALW_OUT)
    target_fd =
      (t_mysh_fd) {0, file, O_WRONLY | O_CREAT
		   | ((cur->value.info.type == APPEND) ? O_APPEND : O_TRUNC), 0644};
  else if (cur->value.info.opt & ALW_IN)
    target_fd = (t_mysh_fd) {0, file, O_RDONLY, 0};
  target_fd.fd = cur->value.info.opt & 0x3;
  if (cur->value.info.sep[0] >= '0' && cur->value.info.sep[0] <= '9')
    my_strtol(cur->value.info.sep, (void*) &(target_fd.fd));
  set_process_redir(process, &target_fd);
  return (elm->next);
}

int		parse_simple_cmd(t_process *proc, t_token *token)
{
  t_clist	*list;
  t_clist_elm	*elm;
  t_token	*cur;

  list = NULL;
  get_tokens(token->value.cmd, &list, g_redir_tab);
  if (!list)
    return (-1);
  elm = list;
  while (elm)
    {
      cur = elm->ptr;
      if (cur->type != CMD)
        elm = parse_redir(list, elm, cur, proc);
      else
	parse_cmd_args(proc, cur->value.cmd);
      if (elm)
	elm = CLIST_NEXT(list, elm);
      else
	return (-1);
    }
  return (0);
}
