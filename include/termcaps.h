/*
** termcaps.h for 42sh in /home/byliarus/work/PSU_2016_42sh/include/
**
** Made by Pierre Narcisi
** Login   <pierre.nacisi@epitech.eu>
**
** Started on  Thu May 18 18:28:17 2017 Pierre Narcisi
** Last update Fri May 19 11:57:35 2017 Pierre Narcisi
*/

#ifndef TERM_H
# define TERM_H

typedef struct s_term_tab
{
  int param1;
  int param2;
  char		*(*term)(char *str, char c, int *cursor);
}               t_term_tab;


char	*rm_ch(char *str, int cursor);
char	*add_ch(char *str, char c, int *cursor);
char *back_space(char *str, char c, int *cursor);
char *right_arrow(char *str, char c, int *cursor);
char *left_arrow(char *str, char c, int *cursor);
#endif
