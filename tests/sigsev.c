/*
** sigsev.c for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/tests/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 13 14:53:01 2017 Alexandre Chamard-bois
** Last update Sat May 13 14:53:02 2017 Alexandre Chamard-bois
*/

int main()
{
  char	*test;

  test = (void*) 0;
  while (1)
    {
      *(test++) = 'a';
    }
  return (0);
}
