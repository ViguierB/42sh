/*
** my_memset.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_navy
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Jan 30 11:36:38 2017 Benjamin Viguier
** Last update Mon Jan 30 11:41:41 2017 Benjamin Viguier
*/

#include <unistd.h>

void		my_memset(void *ptr, int c, size_t size)
{
  char		*cptr;
  size_t	i;

  cptr = (char*) ptr;
  i = 0;
  while (i < size)
    {
      cptr[i] = c;
      i++;
    }
}
