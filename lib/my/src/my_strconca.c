/*
** my_strconca.c for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_ls
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Thu Nov 24 15:24:14 2016 Benjamin Viguier
** Last update Sat May  6 23:34:25 2017 Alexandre Chamard-bois
*/

#include "my.h"

char	*my_strconca(char *str1, char *str2)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  if (res == NULL)
    return (NULL);
  if (str1)
    while (str1[i])
      {
        res[i] = str1[i];
        i += 1;
      }
  if (str2)
    while (str2[j])
      {
        res[i] = str2[j];
        i += 1;
        j += 1;
      }
  res[i] = '\0';
  return (res);
}

char		*str_conca(int n, ...)
{
  va_list ap;
	char *s1;
	char *s2;
	int i;

	if (!n)
		return (NULL);
	va_start(ap, n);
	i = 1;
	s1 = va_arg(ap, char *);
	while (i < n)
	{
		s2 = va_arg(ap, char *);
		s1 = my_strconca(s1, s2);
		i++;
	}
	va_end(ap);
	return (s1);
}
