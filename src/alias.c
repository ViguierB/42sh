/*
** alias.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Tue May 16 16:09:47 2017 Guilhem Fulcrand
** Last update Thu May 18 18:19:01 2017 Guilhem Fulcrand
*/

#include "42shrc.h"
#include "mysh.h"

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
            return (my_strdup(((t_alias *)tmp->ptr)->val));
        tmp = CLIST_NEXT(list, tmp);
    }
    return (NULL);
}

int     my_alias(char **av, t_mysh *sh)
{
    int     i;
    t_all   all;
    char    *val;

    all.list = sh->alias;
    if (!av[1] || !av[2])
        return (0);
    if (!av[2])
        return (0);
    val = NULL;
    i = 1;
    while (av[++i])
    {
        val = my_strconca(val, av[i]);
        val = my_strconca(val, " ");
    }
    return (check_in_list(&all, av[1], val));
}
