/*
** termcaps.h for 42sh in /home/byliarus/work/PSU_2016_42sh/include/
**
** Made by Pierre Narcisi
** Login   <pierre.nacisi@epitech.eu>
**
** Started on  Thu May 18 18:28:17 2017 Pierre Narcisi
** Last update Sat May 20 20:36:22 2017 Alexandre Chamard-bois
*/

#ifndef TERM_H
# define TERM_H

#include "libmy.h"

typedef struct s_term_tab
{
  int param1;
  int param2;
  t_clist *(*term)(int *cursor, t_clist *list);
}               t_term_tab;

char *rm_ch(char *str, int cursor);
char *add_ch(char c, int *cursor, char *str);
t_clist *back_space(int *cursor, t_clist *list);
t_clist *right_arrow(int *cursor, t_clist *list);
t_clist *left_arrow(int *cursor, t_clist *list);
t_clist *up_arrow(int *cursor, t_clist *list);
t_clist *down_arrow(int *cursor, t_clist *list);

#endif
