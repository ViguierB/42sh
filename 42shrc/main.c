/*
** main.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/42shrc/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May 12 18:36:59 2017 Guilhem Fulcrand
** Last update Mon May 15 18:55:00 2017 Guilhem Fulcrand
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

int         add_to_aliases(t_all *all, char *line)
{
    int     i;
    int     len;
    t_alias *new;

    i = 4;
    len = 0;
    new = NULL;
    if (!(new = malloc(sizeof(t_alias))))
        return (EXIT_F);
    new->var = NULL;
    new->val = NULL;
    while (line[++i] && BLANK(line[i]) == 1);
    i--;
    while (line[++i] && line[i] != '=')
        len++;
    new->var = my_strndup(line + i - len, len);
    i++;
    len = 0;
    while (line[++i] && line[i] != '\'')
        len++;
    new->val = my_strndup(line + i - len, len);
    all->list = clist_push(all->list, new);
    return (EXIT_S);
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

int         main()
{
    t_all   all;
    t_my_fd *fd;
    char    *buff;

    if (!(fd = my_fopen(".42shrc", O_RDONLY)))
        return (EXIT_F);
    all.rc = NULL;
    all.list = NULL;
    if (my_fread_to_end(fd, &buff) == -1)
        return (EXIT_F);
    my_fclose(fd);
    all.rc = my_split(buff, '\n', NULL);
    free(buff);
    parse(&all);
    free(all.rc[0]);
    free(all.rc);
    print_alias(all.list);
    clist_free_data(all.list, free_alias);
    return (EXIT_S);
}
