/*
** build_tree.c for minishell2 in /home/benji_epitech/System_Unix/PSU_2016_minishell2
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Tue Apr  4 14:45:41 2017 Benjamin Viguier
** Last update Sat May  6 20:38:22 2017 Alexandre Chamard-bois
*/

#include "mysh.h"
#include "parser.h"

const t_op_flags	g_ops_tab[] =
  {
    {OPOR, "||", 0, &op_or},
    {OPAND, "&&", 0, &op_and},
    {PIPE, "|", 0, &op_pipe},
    {NEXTCMD, ";", 0, &op_next},
    {END_ENUM, NULL, 0, NULL}
  };

const int	g_idx_map[] =
  {
    -1, 0, 1, 1, 1, 1, 1, 2, 2, 2, 3
  };

t_clist_elm	*get_best_sep(t_clist *begin, t_clist *end)
{
  t_clist_elm	*cur;
  t_clist_elm	*res;

  cur = begin;
  res = cur;
  while (cur)
    {
      if (((t_token*) cur->ptr)->type >= MIN_SEP &&
	  (g_idx_map[((t_token*) cur->ptr)->type] >
	   g_idx_map[((t_token*) res->ptr)->type]))
	res = cur;
      cur = CLIST_NEXT(end, cur);
    }
  return (res);
}

int	create_node(t_tree **node, t_clist *begin, t_clist *end)
{
  t_clist_elm	*cur;

  cur = get_best_sep(begin, end);
  if (!(*node = malloc(sizeof(t_tree))))
    my_perror((void*) __func__);
  my_memcpy(&((*node)->value.token), cur->ptr, sizeof(t_token));
  if (((t_token*) cur->ptr)->type == CMD)
    {
      (*node)->type = NODE_CMD;
      (*node)->l = NULL;
      (*node)->r = NULL;
      if (parse_simple_cmd(&((*node)->value.proc), cur->ptr) < 0)
	return (-1);
      return (0);
    }
  (*node)->type = NODE_SEP;
  if (begin != cur && (create_node(&((*node)->l), begin, cur) < 0))
      return (-1);
  if (end != cur->next && (create_node(&((*node)->r), cur->next, end) < 0))
      return (-1);
  return (0);
}

void	free_tree(t_tree *node)
{
  if (node)
    {
      if (node->type == NODE_CMD)
	{
	}
      else if (node->value.token.value.info.sep)
	free(node->value.token.value.info.sep);
      if (node->r)
	free_tree(node->r);
      if (node->l)
	free_tree(node->l);
      free(node);
    }
}

t_tree		*parse_cmd(char *cmd)
{
  t_tree	*tree;
  t_clist	*list;

  if (!(cmd = globbing(cmd)))
    return (NULL);
  if (!get_tokens(cmd, &list, g_ops_tab))
    {
      if (create_node(&tree, list, list) < 0)
	{
	  clist_free_data(list, (void (*)(void*)) &free);
	  return (NULL);
	}
      return (tree);
    }
  return (NULL);
}
