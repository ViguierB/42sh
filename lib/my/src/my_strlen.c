/*
** my_strlen.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_minishell1
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Jan 19 14:02:45 2017 Benjamin Viguier
** Last update Thu Jan 19 14:02:46 2017 Benjamin Viguier
*/

int my_strlen(char *str)
{
  int	count;

  count = 0;
  if (str == (void*) 0)
    return (0);
  while (*(str + count) != '\0')
    count += 1;
  return (count);
}
