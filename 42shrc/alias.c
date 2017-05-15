/*
** alias.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/42shrc/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May 12 19:59:40 2017 Guilhem Fulcrand
** Last update Fri May 12 20:36:18 2017 Guilhem Fulcrand
*/

#include "42shrc.h"

void    free_alias(t_alias *alias)
{
    free(alias->var);
    free(alias->val);
    free(alias);
}

void    print_alias(t_clist *list)
{
    t_clist *cur;

    cur = list;
    while (list->next != cur)
        my_printf("%s -> %s\n", ((t_alias *)list->ptr)->var,
                                ((t_alias *)list->ptr)->val);
}
