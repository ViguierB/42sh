/*
** main.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/42shrc/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May 12 18:36:59 2017 Guilhem Fulcrand
** Last update Fri May 12 20:38:40 2017 Guilhem Fulcrand
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

    if (BLANK(line[6]) == 0)
        return (EXIT_F);
    i = 5;
    while (line[++i] && BLANK(line[i]) == 1);
    i++;
    if (line[i] != '=')
        return (EXIT_F);
    if (line[i + 1] != '\'')
        return (EXIT_F);
    while (line[++i]);
    if (line[i - 1] != '\'')
        return (EXIT_F);
    return (EXIT_S);
}

int         add_to_aliases(t_clist *list, char *line)
{
    int     i;
    int     len;
    t_alias *new;

    i = 5;
    len = 0;
    new = NULL;
    if (!(new = malloc(sizeof(t_alias))))
        return (EXIT_F);
    new->var = NULL;
    new->val = NULL;
    while (line[++i] && BLANK(line[i]) == 1);
    while (line[++i] && line[i] != '=')
        len++;
    new->var = my_strndup(line + i - len, len);
    i++;
    len = 0;
    while (line[++i] && line[i] != '\'')
        len++;
    new->val = my_strndup(line + i - len, len);
    list = clist_push(list, new);
    return (EXIT_S);
}

int     parse(t_clist *list, char **rc)
{
    int i;
    int j;

    j = -1;
    i = 0;
    while (rc[++j])
    {
        i = 0;
        while (BLANK(rc[j][i]) == 1)
            j++;
        if (my_strncmp(rc[i] + j, "alias", 5) == 0)
        {
            if (check_exp(rc[i] + j) != EXIT_S)
                continue;
            if (add_to_aliases(list, rc[i] + j) != EXIT_S)
                return (EXIT_F);
        }
    }
    return (EXIT_S);
}

int         main()
{
    t_clist *list;
    t_my_fd *fd;
    char    **rc;

    if (!(fd = my_fopen(".42shrc", O_RDONLY)))
        return (EXIT_F);
    list = NULL;
    rc = NULL;
    if (my_fread_to_end(fd, rc) == -1)
        return (EXIT_F);
    parse(list, rc);
    print_alias(list);
    clist_free_data(list, free_alias((t_alias *)list->ptr));
    return (EXIT_S);
}
