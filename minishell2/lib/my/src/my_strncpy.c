/*
** my_strncpy.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:03:10 2017 Benjamin Viguier
** Last update Thu Jan 19 14:03:11 2017 Benjamin Viguier
*/

char *my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i < n && (src[i] != '\0'))
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}
