/*
** my_source.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Tue May 16 16:08:05 2017 Guilhem Fulcrand
** Last update Tue May 16 15:37:57 2017 Alexandre Chamard-bois
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "42shrc.h"
#include "macro.h"

int     check_exp(char *line)
{
    int i;

    if (BLANK(line[5]) == 0)
        return (EXIT_F);
    i = 4;
    while (line[++i] && BLANK(line[i]) == 1);
    i--;
    while (line[++i] && line[i] != '=');
    if (line[i] != '=')
        return (EXIT_F);
    if (line[i + 1] != '\'')
        return (EXIT_F);
    while (line[++i]);
    if (line[i - 1] != '\'')
        return (EXIT_F);
    return (EXIT_S);
}

int         check_in_list(t_all *all, char *var, char *val)
{
    t_clist *tmp;
    t_alias *new;

    tmp = all->list;
    while (tmp)
    {
        if (my_strcmp(((t_alias *)tmp->ptr)->var, var) == EXIT_S)
        {
            free(((t_alias *)tmp->ptr)->val);
            ((t_alias *)tmp->ptr)->val = my_strdup(val);
            free(var);
            free(val);
            return (EXIT_S);
        }
        tmp = CLIST_NEXT(all->list, tmp);
    }
    if (!(new = malloc(sizeof(t_alias))))
        return (EXIT_F);
    new->var = my_strdup(var);
    new->val = my_strdup(val);
    free(var);
    free(val);
    all->list = clist_push(all->list, new);
    return (EXIT_S);
}

int         add_to_aliases(t_all *all, char *line)
{
    int     i;
    int     len;
    char    *var;
    char    *val;

    i = 4;
    len = 0;
    while (line[++i] && BLANK(line[i]) == 1);
    i--;
    while (line[++i] && line[i] != '=')
        len++;
    var = my_strndup(line + i - len, len);
    i++;
    len = 0;
    while (line[++i] && line[i] != '\'')
        len++;
    val = my_strndup(line + i - len, len);
    return (check_in_list(all, var, val));
}

int     parse(t_all *all)
{
    int i;
    int j;

    j = -1;
    i = 0;
    while (all->rc[++j])
    {
        i = 0;
        while (BLANK(all->rc[j][i]) == 1)
            i++;
        if (my_strncmp(all->rc[j] + i, "alias", 5) == 0)
        {
            if (check_exp(all->rc[j] + i) != EXIT_S)
                continue;
            if (add_to_aliases(all, all->rc[j] + i) != EXIT_S)
                return (EXIT_F);
        }
    }
    return (EXIT_S);
}

t_clist     *my_source(t_clist *previous_alias)
{
    t_all   all;
    t_my_fd *fd;
    char    *buff;

    if (previous_alias != NULL)
        clist_free_data(previous_alias, free_alias);
    if (!(fd = my_fopen(".42shrc", O_RDONLY)))
        return (NULL);
    all.rc = NULL;
    all.list = NULL;
    if (my_fread_to_end(fd, &buff) == -1)
    {
      my_fclose(fd);
      return (NULL);
    }
    my_fclose(fd);
    all.rc = my_split(buff, '\n', NULL);
    free(buff);
    parse(&all);
    free(all.rc[0]);
    free(all.rc);
    return (all.list);
}
