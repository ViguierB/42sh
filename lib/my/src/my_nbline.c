/*
** my_nbline.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 13:46:51 2017 Alexandre Chamard-bois
** Last update Sat May  6 13:46:56 2017 Alexandre Chamard-bois
*/

int my_nbline(const char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
