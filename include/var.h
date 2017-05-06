/*
** var.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Fri May  5 19:23:43 2017 Alexandre Chamard-bois
** Last update Sat May  6 12:08:59 2017 Alexandre Chamard-bois
*/

#ifndef VAR_H_
#define VAR_H_

typedef struct  s_var
{
  int           type;
  char          *name;
  void          *ptr;
  struct s_var  *next;
}               t_var;

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
