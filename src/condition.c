/*
** condition.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sun May  7 20:26:36 2017 Alexandre Chamard-bois
** Last update Sun May 21 20:19:54 2017 alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"

char	*conc_with_free(char *str1, char *str2)
{
  char	*tmp;

  tmp = my_strconca(str1, str2);
  free(str1);
  return (tmp);
}

char	*concatene_cond(char **cond)
{
  int	i;
  char	*str;
  char	*tmp;

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
