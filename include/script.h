/*
** script.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 11:30:21 2017 Alexandre Chamard-bois
** Last update Fri May 19 20:50:21 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "var.h"

#ifndef SCRIPT_H_
# define SCRIPT_H_

typedef struct  s_if
{
  t_clist       *then;
  t_clist       *els;
}               t_if;

/*
** VAR functions
*/

t_value do_egality(t_mysh *sh, t_var *var, char **tab);
char **recup_parentheses(char **tab, int *pos);

#endif
/*
  cond    [ appel == appel ]  return: 0 == || 1 != || 2 err ## builtin [
  egality var = appel         return: 0
*/
