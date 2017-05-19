/*
** var.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri May  5 19:23:43 2017 Alexandre Chamard-bois
** Last update Fri May 19 09:02:44 2017 Alexandre Chamard-bois
*/

#ifndef VAR_H_
# define VAR_H_

#include "libmy.h"

# define T_STR     0b001
# define T_INT     0b010
# define T_FLOAT   0b100

# define PTR(var)   ((t_var_elm*)var->ptr)
# define NAME(var)  (PTR(var)->name)
# define VALUE(var) (PTR(var)->value.ptr)

typedef struct   s_value
{
  char          *ptr;
}               t_value;

typedef struct  s_var_elm
{
  char          *name;
  t_value       value;
}               t_var_elm;

typedef t_clist t_var;

typedef struct  s_pars_level
{
  int           parent;
  int           s_quote;
  int           d_quote;
}               t_pars_level;

typedef struct  s_function
{
  t_var         *private_var;
  void          *ptr;
}               t_function;

char *find_var(t_clist *, t_clist *, char *);

#endif

// str      0000 //
// int      0001 //
// float    0010 //
// t_clist  1... //
