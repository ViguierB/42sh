/*
** my_memcpy.c for libmy in /home/benji_epitech/C_Graph_Prog/wolf3d/bonus/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Jan 20 13:13:17 2017 Benjamin Viguier
** Last update Mon Jan 30 11:43:29 2017 Benjamin Viguier
*/

#include <unistd.h>
#include <libmy.h>

void		*my_memcpy(void *dptr, void *fptr, size_t size)
{
  char		*dest;
  char		*from;
  size_t	i;

  dest = (char*) dptr;
  from = (char*) fptr;
  i = 0;
  while (i < size)
    {
      dest[i] = from[i];
      i++;
    }
  return (dptr);
}
