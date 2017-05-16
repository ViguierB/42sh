/*
** parser.c for mysh in /home/benji_epitech/System_Unix/PSU_2016_minishell2
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sun Mar 19 20:00:50 2017 Benjamin Viguier
** Last update Tue May 16 13:50:34 2017 Benjamin Viguier
*/

#include "mysh.h"
#include "parser.h"

int	get_info(char *str, t_sepinfo *info, t_op_flags *cur)
{
  int	len;

  info->to_ecrase = 0;
  if (cur->opts & (ALW_IN | ALW_OUT) && ISNUM(*(str - 1)))
    {
      while (*(--str) && ISNUM(*str))
	(info->to_ecrase)++;
      if (*(str++) != ' ')
	{
	  str += info->to_ecrase - 1;
	  info->to_ecrase = 0;
	}
    }
  len = my_strlen(cur->str);
  while (str[len] && str[len] == ' ')
    len++;
  if (!(info->sep = malloc(sizeof(char) * (len + info->to_ecrase) + 1)))
    my_perror((char*) __func__);
  my_memcpy(info->sep, str, len + info->to_ecrase);
  info->sep[len + info->to_ecrase] = '\0';
  info->sep = my_ftrim(info->sep);
  info->fct = cur->fct;
  info->ident = cur->str;
  info->len = len;
  return (0);
}

int		is_sep(char *str, t_sepinfo *info, const t_op_flags *flags)
{
  t_op_flags	*cur;

  cur = (void*) flags;
  my_memset(info, 0, sizeof(*info));
  while (cur->type != END_ENUM)
    if (!my_strncmp(cur->str, str, my_strlen(cur->str)))
      {
	get_info(str, info, cur);
	info->opt = cur->opts;
	info->is_sep = 1;
	info->type = cur->type;
	return (1);
      }
    else
      cur++;
  return (0);
}

t_token		*create_token(int is_sep, void *value)
{
  t_token	*res;

  res = malloc(sizeof(t_token));
  if (!res)
    my_perror("Malloc()");
  res->type = CMD;
  if (is_sep)
    {
      my_memcpy(&(res->value.info), value, sizeof(t_sepinfo));
      res->type = res->value.info.type;
    }
  else if (!(*((char*) value)))
    {
      res->value.cmd = NULL;
      free(value);
    }
  else
    res->value.cmd = value;
  return (res);
}

char		*blk_sep_checker(char *cur, t_strbuilder *sb,
				 t_clist **list, int *is_block, const t_op_flags *flags)
{
  t_sepinfo	info;

  if (!(*is_block) && (*cur == '"' || *cur == ("'")[0]))
    *is_block = *cur;
  else if (*cur == *is_block)
    *is_block = 0;
  if (!(*is_block) && is_sep(cur, &info, flags))
    {
      my_sb_ecrase(sb, info.to_ecrase);
      *list = clist_push(*list, create_token(0,
					     my_ftrim(my_sb_flush(sb))));
      if (info.is_sep)
	{
	  *list = clist_push(*list, create_token(info.is_sep, &info));
	  cur += info.len;
	}
      else
	cur++;
    }
  else
    my_sb_write(sb, cur++, 1);
  return (cur);
}

int		get_tokens(char *cmd, t_clist **list, const t_op_flags *flags)
{
  char		*cur;
  t_strbuilder	*sb;
  int		is_block;

  is_block = 0;
  *list = NULL;
  cur = cmd;
  sb = my_sb_init();
  while (*cur)
    {
      cur = blk_sep_checker(cur, sb, list, &is_block, flags);
    }
  cur = my_sb_get_str(sb);
  if (*cur)
    {
      cur = my_ftrim(cur);
      if (*cur != '|' && *cur != '&')
	*list = clist_push(*list, create_token(0, cur));
    }
  if (is_block)
    my_pcustomwarning("Block unclosed (open with %c)\n", is_block);
  return (0);
}
