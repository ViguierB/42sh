/*
** script.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 11:30:21 2017 Alexandre Chamard-bois
** Last update Sun May 14 15:12:45 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "var.h"

#ifndef SCRIPT_H_
# define SCRIPT_H_

typedef struct  s_cond
{
  int           type_next;
  struct s_cond *next;
  int           type_cond;
  short         type_ptr[2];
  void          *ptr[2];
}               t_cond;

typedef struct  s_elif
{
  t_cond        *cond;
  t_clist       *then;
  struct s_elif *next;
}               t_elif;

typedef struct  s_if
{
  t_cond        *cond;
  t_clist       *then;
  t_elif        *elif;
  t_clist       *els;
}               t_if;

/*
** VAR functions
*/

t_value do_egality(t_mysh *sh, t_var *var, char **tab);

t_cond *build_cond(char *str);

#endif
/*
  cond    [ appel == appel ]  return: 0 == || 1 != || 2 err ## builtin [
  egality var = appel         return: 0
*/
