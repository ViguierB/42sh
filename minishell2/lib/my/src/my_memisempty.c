/*
** my_memisempty.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_navy
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Mon Jan 30 18:07:41 2017 Benjamin Viguier
** Last update Mon Jan 30 18:13:50 2017 Benjamin Viguier
*/

#include <unistd.h>

int	my_memisempty(void *ptr, size_t size)
{
  char	*tmp;

  tmp = (char*) ptr;
  while (size)
    {
      if (*tmp)
	return (0);
      tmp++;
      size--;
    }
  return (1);
}
