/*
** var.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri May  5 19:23:43 2017 Alexandre Chamard-bois
** Last update Sat May  6 13:52:04 2017 Alexandre Chamard-bois
*/


#ifndef VAR_H_
# define VAR_H_

# include "libmy.h"

#define T_STR     0b00
#define T_INT     0b01
#define T_FLOAT   0b10

typedef struct  s_var_elm
{
  int           type;
  char          *name;
  void          *ptr;
}               t_var_elm;

typedef t_clist t_var;

extern t_var *var;

#endif

// str      0000 //
// int      0001 //
// float    0010 //
// if       0011 //
// while    0100 //
// until    0101 //
// for      0110 //
// t_clist  1... //

// 0000   0000    0000 0000 0000 ... //
// type   nb_arg  t_arg * 14 //
