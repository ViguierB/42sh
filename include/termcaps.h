/*
** termcaps.h for 42sh in /home/byliarus/work/PSU_2016_42sh/include/
**
** Made by Pierre Narcisi
** Login   <pierre.nacisi@epitech.eu>
**
** Started on  Thu May 18 18:28:17 2017 Pierre Narcisi
** Last update Thu May 18 18:57:58 2017 Pierre Narcisi
*/

#ifndef TERM_H
# define TERM_H

typedef struct s_term_tab
{
  int param1;
  int param2;
  char		*(*term)(char *str, char c, int *cursor);
}               t_term_tab;

#endif
