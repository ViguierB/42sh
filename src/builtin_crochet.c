/*
** builtin_crochet.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 11:15:04 2017 Alexandre Chamard-bois
** Last update Thu May 11 23:13:20 2017 Alexandre Chamard-bois
*/

#include "mysh.h"

#define FLAG      1
#define STRING    2
#define INTEGER   4

static int _pars(char **tab, char *to_pars[4], int i)
{
  int j;

  j = 0;
  my_memset(to_pars, 0, sizeof(char *) * 4);
  if (!my_strcmp(tab[i], "]"))
    return (0);
  i++;
  if (!my_strcmp(tab[i], "!"))
    to_pars[3] = tab[i++];
  while (my_strcmp(tab[i + j], "-a") && my_strcmp(tab[i + j], "-o") &&
          my_strcmp(tab[i + j], "]") && j < 3)
  {
    to_pars[j] = tab[i + j];
    j++;
  }
  if (my_strcmp(tab[i + j], "-a") && my_strcmp(tab[i + j], "-o") &&
          my_strcmp(tab[i + j], "]"))
  {
    my_putstr("too many arguments\n");
    return (-1);
  }
  return (i + j);
}

t_mysh builtin_crochet(char **tab, t_mysh sh)
{
  int i;
  char *to_pars[4];
  int res;

  res = 1;
  i = 0;
  if (my_strcmp(tab[my_nbline(tab) - 1], "]"))
    return (my_putstr("missing `]'\n"), (t_mysh){sh.env, sh.var, 2});
  while (res != 2 && (i = _pars(tab, to_pars, i)) > 0)
  {
    int j = 0;
    while (j < 4 && to_pars[j])
      my_printf("%s\n", to_pars[j++]);
  }
  if (i == -1)
    return ((t_mysh){sh.env, sh.var, 2});
  return ((t_mysh){sh.env, sh.var, res});
}

int main()
{
  t_mysh sh;
  char *buff;
  t_my_fd	*in;

  my_memset(&sh, 0, sizeof(t_mysh));
  in = my_fd_from_fd(0);
  while ((buff = my_getline(in)))
  {
    if (!my_strncmp(buff, "[", 1))
      sh = builtin_crochet(my_split(buff, ' ', NULL), sh);
    my_printf("%d\n", sh.last_exit);
    free(buff);

  }
  return (0);
}
