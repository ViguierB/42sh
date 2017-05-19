/*
** if.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May  7 20:17:55 2017 Alexandre Chamard-bois
** Last update Fri May 19 19:12:05 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "script.h"

char *conc_with_free(char *str1, char *str2)
{
  char *tmp;

  tmp = my_strconca(str1, str2);
  free(str1);
  return (tmp);
}

char *concatene_cond(char **cond)
{
  int i;
  char *str;
  char *tmp;

  i = 0;
  str = my_strdup("[ ");
  while (cond[i])
  {
    if (!my_strcmp(cond[i], "&&") || !my_strcmp(cond[i], "||"))
    {
      str = conc_with_free(str, "] ");
      str = conc_with_free(str, cond[i]);
      str = conc_with_free(str, " [ ");
    }
    else
    {
      tmp = str_conca(3, str, cond[i], " ");
      free(str);
      str = tmp;
    }
    i++;
  }
  str = conc_with_free(str, "]");
  return (str);
}

int built_if(char **tab, t_mysh *sh)
{
  char **cond;
  char *str;
  int i;

  i = 0;
  (void) sh;
  if (!(cond = recup_parentheses(tab + 1, &i)))
    return (1);
  str = concatene_cond(cond);
  my_printf("%s\n", str);
  free(cond);
  free(str);
  return (0);
}

int main(int ac, char **av)
{
  (void) ac;
  built_if(av + 1, NULL);
  return (0);
}
