/*
** egality.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Wed May 10 19:13:15 2017 Alexandre Chamard-bois
** Last update Thu May 11 09:27:34 2017 Alexandre Chamard-bois
*/

#include "script.h"

t_do_appel g_appel[] =
{
  {A_BRUT, appel_brut},
  {A_CALC, appel_calcul},
  {A_VAR, appel_var},
  {A_ASS, appel_assign},
  {A_TER, appel_ternaire},
  {A_FUNC, appel_function},
  {0, NULL}
};

t_value appel_brut(t_mysh *mysh, void *appel)
{
  t_value value;

  (void) mysh;
  my_memcpy(&value, appel, sizeof(t_value));
  return (value);
}

t_value appel_var(t_mysh *mysh, void *appel)
{
  (void) mysh;
  return (((t_var_elm*)appel)->value);
}

t_value do_appel(t_mysh *sh, t_appel *appel)
{
  t_value value;
  int i;

  my_memset(&value, 0, sizeof(t_value));
  i = 0;
  while (g_appel[i].code && g_appel[i].code != appel->type)
    i++;
  if (g_appel[i].code)
  {
    value = g_appel.func(sh, appel->ptr);
  }
  return (value);
}

t_value do_egality(t_mysh *sh, t_var *var, t_appel *appel)
{
  t_value ret;
  t_value value;

  my_memset(&ret, 0, sizeof(t_value));
  value = do_appel(sh, appel);
  if (value.type)
  {
    my_memcpy(&(PTR(var)->value), &value, sizeof(t_value));
    my_memcpy(&ret, &value, sizeof(t_value));
  }
  return (ret);
}
