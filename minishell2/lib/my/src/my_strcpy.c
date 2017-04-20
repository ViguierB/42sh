/*
** my_strcpy.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:02:19 2017 Benjamin Viguier
** Last update Thu Jan 19 14:02:20 2017 Benjamin Viguier
*/

char *my_strcpy(char *dest, char *src)
{
  if (src[0] == '\0')
    dest[0] = '\0';
  else
    {
      my_strcpy(dest + 1, src + 1);
      dest[0] = src[0];
    }
  return (dest);
}
