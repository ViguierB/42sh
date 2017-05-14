/*
** macro.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 13:41:43 2017 Alexandre Chamard-bois
** Last update Thu May 11 09:45:21 2017 Alexandre Chamard-bois
*/

#ifndef MACRO_H_
# define MACRO_H_

#ifndef MIN
# define MIN(x, y) ((x) < (y) ? (x) : (y))
#endif
#ifndef MAX
# define MAX(x, y) ((x) > (y) ? (x) : (y))
#endif
#ifndef ABS
# define ABS(x) ((x) > 0 ? (x) : -(x))
#endif
#ifndef NUM
# define NUM(c) ((c) >= '0' && (c) <= '9' ? 1 : 0)
#endif
#ifndef UPPER
# define UPPER(c) ((c) >= 'A' && (c) <= 'Z' ? 1 : 0)
#endif
#ifndef LOWER
# define LOWER(c) ((c) >= 'a' && (c) <= 'z' ? 1 : 0)
#endif
#ifndef PRINTABLE
# define PRINTABLE(c) ((c) >= 32 && (c) <= 126 ? 1 : 0)
#endif
#ifndef QUOTE
# define QUOTE(c) ((c) != '\'' ? (c) != '\"' ? (c) != '`' ? 0 : 1 : 2 : 3)
#endif
#ifndef LEVEL
# define LEVEL(c) (QUOTE(c) || (c) == '(' || (c) == ')' ? 1 : 0)
#endif
#ifndef SPACE
# define SPACE(c) ((c) == ' ' || (c) == '\t' ? 1 : 0)
#endif
#ifndef BLANK
# define BLANK(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' ? 1 : 0)
#endif
#ifndef GLOBING
# define GLOBING(c) ((c) == '*' || (c) == '?' ? 1 : 0)
#endif
#ifndef READ_SIZE
# define READ_SIZE  1024
#endif

#endif
