/*
** test.c for  in /home/augustin/Bureau/augustin/projets_groupes/42sh/PSU_2016_42sh/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Fri May 19 10:35:22 2017 augustin leconte
** Last update Fri May 19 20:40:27 2017 augustin leconte
*/


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

struct termios saved_attributes;

void my_putchar(char c)
{
  write (1, &c, 1);
}

void my_putstr(char *str)
{
  int i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}

// void reset_input_mode (void)
// {
//  tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
// }
//
// int set_input_mode ()
// {
//  struct termios tattr;
//
//  if (!isatty (STDIN_FILENO))
//     return (84);
//  tcgetattr (STDIN_FILENO, &saved_attributes);
//  atexit (reset_input_mode);
//  tcgetattr (STDIN_FILENO, &tattr);
//  tattr.c_lflag &= ~(ICANON|ECHO);
//  tattr.c_cc[VMIN] = 1;
//  tattr.c_cc[VTIME] = 0;
//  tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
//  return (0);
// }

int main ()
{
 // char c;z
 int j;
 // int cursor;

 // cursor = 0;
 // if (set_input_mode() == 84)
  // return (84);
 j = 0;
 while (j < 3)
   {
     if (j == 0)
      my_putstr("salut");
      j++;
    //  j = read(STDIN_FILENO, &c, 1);
    //  if (c == '\004')
      //  return (0);
      my_putstr("\033[1D");
   }
   while (1);
 return (0);
}
