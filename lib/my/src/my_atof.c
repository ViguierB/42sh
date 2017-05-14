/*
** my_atof.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/lib/my/src/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 14:17:55 2017 Alexandre Chamard-bois
** Last update Sat May  6 14:17:57 2017 Alexandre Chamard-bois
*/

int getfl(const char *str, int *rang)
{
  int fl;
  int   max;

  fl = 0;
  max = 8;
  while (str[*rang] >= '0' && str[*rang] <= '9' && --max)
  {
    fl = fl * 10 + str[*rang] - '0';
    (*rang)++;
  }
  return (fl);
}

double my_atof(const char *str)
{
  double nb;
  double fl;
  int rang;
  int nega;
  int i;

  nb = 0;
  fl = 0;
  rang = 0;
  i = 0;
  nega = 1;
  if (*str == '-' && (nega = -1))
    i++;
  while (str[i] >= '0' && str[i] <= '9')
  {
    nb = nb * 10 + str[i] - '0';
    i++;
  }
  if (str[i] == '.')
    fl = getfl(str + i + 1, &rang);
  while ((--rang) > -1)
    fl /= 10;
  return ((nb + fl) * nega);
}
