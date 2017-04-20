/*
** my_toupper.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_tetris/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Feb 28 13:44:07 2017 Benjamin Viguier
** Last update Tue Feb 28 13:50:23 2017 Benjamin Viguier
*/

void	my_upper(char *str)
{
  while (*str)
    {
      if (*str >= 'a' && *str <= 'z')
	*str += 'a' - 'A';
      str++;
    }
}

void	my_lower(char *str)
{
  while (*str)
    {
      if (*str >= 'A' && *str <= 'Z')
	*str -= 'a' - 'A';
      str++;
    }
}
