/*
** my_errno.c for libmy in /home/benji_epitech/C_Prog_Elem/CPE_2016_matchstick
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 17 13:31:12 2017 Benjamin Viguier
** Last update Tue Feb 21 11:43:16 2017 Benjamin Viguier
*/

#include "my_errno.h"
#include "libmy.h"

void		intern_errno__(int *val, int opt)
{
  static int	my_errno_val;

  if (opt == MERRNO_SET)
    my_errno_val = *val;
  else if (opt == MERRNO_GET)
    *val = my_errno_val;
}
