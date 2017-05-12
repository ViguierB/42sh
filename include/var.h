/*
** var.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri May  5 19:23:43 2017 Alexandre Chamard-bois
** Last update Thu May 11 22:05:09 2017 Alexandre Chamard-bois
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
# define TYPE(var)  (PTR(var)->value.type)
# define STR(var)   (TYPE(var) == T_STR ? 1 : 0)
# define INT(var)   (TYPE(var) == T_INT ? 1 : 0)
# define FLOAT(var) (TYPE(var) == T_FLOAT ? 1 : 0)

typedef struct   s_value
{
  int           type;
  void          *ptr;
}               t_value;

typedef struct  s_var_elm
{
  char          *name;
  t_value       value;
}               t_var_elm;

typedef t_clist t_var;

# define A_BRUT  (1 << 0)
# define A_CALC  (1 << 1)
# define A_VAR   (1 << 2)
# define A_ASS   (1 << 3)
# define A_TER   (1 << 4)
# define A_FUNC  (1 << 5)
# define A_ERR  (-1)

typedef struct  s_appel
{
  int           type;
  void          *ptr;
}               t_appel;

/*  renvoie une valeur
    valeur brute  (ex: 10, 'bonjour', ...)
    calcul        (ex: 10 + $1, ...)
    variable      (ex: $a $1, ...)
    assignation   (ex: ($a = 1), ($b = $a + 10), ($c = 'bonjour + $b'), ...)
    ternaire      (ex: ($a > 10 ? $a : 10), ...)
    function with return (len($c), abs(-10), ...)
*/

typedef struct  s_pars_crochet
{
  
}               t_pars_crochet;

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

int find_type(char *str);

#endif

// str      0000 //
// int      0001 //
// float    0010 //
// t_clist  1... //
