/*
** alias.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/42shrc/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May 12 19:59:40 2017 Guilhem Fulcrand
** Last update Mon May 15 18:54:44 2017 Guilhem Fulcrand
*/

#include "42shrc.h"

void    free_alias(void *alias)
{
    if (!alias)
        return;
    if (((t_alias *)alias)->var)
        free(((t_alias *)alias)->var);
    if (((t_alias *)alias)->val)
        free(((t_alias *)alias)->val);
    free(alias);
}

void    print_alias(t_clist *list)
{
    t_clist *cur;

    cur = list;
    while (cur)
    {
        my_putstr((char *)((t_alias *)cur->ptr)->var);
        my_putstr(" -> ");
        my_putstr((char *)((t_alias *)cur->ptr)->val);
        my_putchar('\n');
        cur = CLIST_NEXT(list, cur);
    }
}
