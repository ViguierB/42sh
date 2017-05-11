/*
** script.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 11:30:21 2017 Alexandre Chamard-bois
** Last update Thu May 11 11:24:32 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "var.h"

#ifndef SCRIPT_H_
# define SCRIPT_H_

typedef struct  s_cond
{
  int           type_next; // 0 = AND // 1 = OR //
  struct s_cond *next;
  int           type_cond; // 000 != // 001 == // 010 > // 100 < // 011 >= // 101 <= //
  short         type_ptr[2];
  void          *ptr[2];
}               t_cond;

typedef struct  s_elif
{
  t_cond        *cond;
  t_clist       *then;
  struct s_elif *next;
}               t_elif;

typedef struct  s_if
{
  t_cond        *cond;
  t_clist       *then;
  t_elif        *elif;
  t_clist       *els;
}               t_if;

/*
** VAR functions
*/

typedef struct  s_do_appel
{
  int           code;
  t_value       (*func)(t_mysh *mysh, void *ptr);
}               t_do_appel;

t_value appel_brut(t_mysh *sh, void *ptr);
t_value appel_calcul(t_mysh *sh, void *ptr);
t_value appel_var(t_mysh *sh, void *ptr);
t_value appel_assign(t_mysh *sh, void *ptr);
t_value appel_ternaire(t_mysh *sh, void *ptr);
t_value appel_function(t_mysh *sh, void *ptr);
t_value do_appel(t_mysh *sh, t_appel *appel);

t_value do_egality(t_mysh *sh, t_var *var, t_appel *);

t_cond *build_cond(char *str);

#endif
/*
  cond    [ appel == appel ]  return: 0 == || 1 != || 2 err ## builtin [
  egality var = appel         return: 0
*/
/*
( EXPRESSION )               EXPRESSION is true
! EXPRESSION                 EXPRESSION is false
EXPRESSION1 -a EXPRESSION2   both EXPRESSION1 and EXPRESSION2 are true
EXPRESSION1 -o EXPRESSION2   either EXPRESSION1 or EXPRESSION2 is true

-n STRING            the length of STRING is nonzero
STRING               equivalent to -n STRING
-z STRING            the length of STRING is zero
STRING1 = STRING2    the strings are equal
STRING1 != STRING2   the strings are not equal

INTEGER1 -eq INTEGER2   INTEGER1 is equal to INTEGER2
INTEGER1 -ge INTEGER2   INTEGER1 is greater than or equal to INTEGER2
INTEGER1 -gt INTEGER2   INTEGER1 is greater than INTEGER2
INTEGER1 -le INTEGER2   INTEGER1 is less than or equal to INTEGER2
INTEGER1 -lt INTEGER2   INTEGER1 is less than INTEGER2
INTEGER1 -ne INTEGER2   INTEGER1 is not equal to INTEGER2

FILE1 -ef FILE2   FILE1 and FILE2 have the same device and inode numbers
FILE1 -nt FILE2   FILE1 is newer (modification date) than FILE2
FILE1 -ot FILE2   FILE1 is older than FILE2

-b FILE     FILE exists and is block special
-c FILE     FILE exists and is character special
-d FILE     FILE exists and is a directory
-e FILE     FILE exists
-f FILE     FILE exists and is a regular file
-g FILE     FILE exists and is set-group-ID
-G FILE     FILE exists and is owned by the effective group ID
-h FILE     FILE exists and is a symbolic link (same as -L)
-k FILE     FILE exists and has its sticky bit set
-L FILE     FILE exists and is a symbolic link (same as -h)
-O FILE     FILE exists and is owned by the effective user ID
-p FILE     FILE exists and is a named pipe
-r FILE     FILE exists and read permission is granted
-s FILE     FILE exists and has a size greater than zero
-S FILE     FILE exists and is a socket
-t FD       file descriptor FD is opened on a terminal
-u FILE     FILE exists and its set-user-ID bit is set
-w FILE     FILE exists and write permission is granted
-x FILE     FILE exists and execute (or search) permission is granted
*/
