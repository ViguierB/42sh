/*
** my_strstr.c for libmy in /home/ben/epitech/PSU_2016_42sh
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat May  6 13:37:24 2017 Benjamin Viguier
** Last update Sat May  6 13:45:40 2017 Benjamin Viguier
*/

#include "libmy.h"

char	*my_strstr(char *haystack, char *needle)
{
  int	str_len;

  str_len = my_strlen(needle);
  while (*haystack)
    {
      if (!my_strncmp(haystack, needle, str_len))
	return (haystack);
      haystack++;
    }
  return (NULL);
}

char	*my_strnstr(char *haystack, char *needle, int n)
{
  int	str_len;
  int	i;

  i = 0;
  str_len = my_strlen(needle);
  while (*haystack && i < n)
    {
      if (!my_strncmp(haystack, needle, str_len))
	return (haystack);
      haystack++;
      i++;
    }
  return (NULL);
}
