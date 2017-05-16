/*
** 42shrc.h for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/include/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May 12 19:19:07 2017 Guilhem Fulcrand
** Last update Tue May 16 16:31:48 2017 Guilhem Fulcrand
*/

#include "libmy.h"

#ifndef RC_H
# define RC_H

/* EXIT */

# ifndef EXIT_S
#  define EXIT_S        0
# endif

# ifndef EXIT_F
#  define EXIT_F        84
# endif

typedef struct          s_alias
{
    char                *var;
    char                *val;
}                       t_alias;

typedef struct          s_all
{
    t_clist             *list;
    char                **rc;
}                       t_all;

t_clist *my_source(t_clist *);

/* ALIASES */

void    print_alias(t_clist *list);
void    free_alias(void *alias);
int     check_in_list(t_all *, char *var, char *val);
char    *find_alias(t_clist *, char *);

#endif
