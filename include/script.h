/*
** script.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 11:30:21 2017 Alexandre Chamard-bois
** Last update Sat May  6 12:10:16 2017 Alexandre Chamard-bois
*/

#include "libmy.h"

#ifndef SCRIPT_H_
# define SCRIPT_H_

typedef struct  s_cond
{
  int           type_next; // 0 = AND // 1 = OR //
  struct s_cond *next;
  int           type_cond; // 000 != // 001 == // 010 > // 100 < // 011 >= // 101 <= //
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

#endif
/*
if (cond)...
then
...
elif (cond)...
...
else
...
end
*/
