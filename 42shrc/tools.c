/*
** alias.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/42shrc/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May 12 19:59:40 2017 Guilhem Fulcrand
** Last update Tue May 16 15:02:01 2017 Guilhem Fulcrand
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
    t_clist *tmp;

    tmp = list;
    while (tmp)
    {
        my_putstr((char *)((t_alias *)tmp->ptr)->var);
        my_putstr(" -> ");
        my_putstr((char *)((t_alias *)tmp->ptr)->val);
        my_putchar('\n');
        tmp = CLIST_NEXT(list, tmp);
    }
}

char        *find_alias(t_clist *list, char *cmd)
{
    t_clist *tmp;

    tmp = list;
    while (tmp)
    {
        if (my_strcmp(((t_alias *)tmp->ptr)->var, cmd) == EXIT_S)
            return (((t_alias *)tmp->ptr)->val);
        tmp = CLIST_NEXT(list, tmp);
    }
    return (NULL);
}
