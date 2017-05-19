/*
** history.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Thu May 18 20:54:01 2017 Guilhem Fulcrand
** Last update Fri May 19 19:40:14 2017 Guilhem Fulcrand
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "mysh.h"

t_clist      *my_history()
{
    t_clist  *hist;
    t_my_fd *fd;
    char    *line;

    hist = NULL;
    if (!(fd = my_fopen(".history", O_RDONLY)))
        return (NULL);
    while ((line = my_getline(fd)))
        hist = clist_push(hist, line);
    my_fclose(fd);
    return (hist);
}

t_clist     *push_in_hist(t_clist *hist, char *cmd)
{
    if (!hist || my_strcmp((char *)hist->ptr, cmd) != 0)
        hist = clist_push(hist, cmd);
    return (hist);
}

void            print_hist(t_clist *hist)
{
    t_clist     *tmp;

    tmp = hist;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->ptr);
        tmp = CLIST_NEXT(hist, tmp);
    }
}

void        write_hist(t_clist *hist)
{
    int     fd;
    t_clist *tmp;

    if ((fd = open(".history", O_CREAT | O_TRUNC | O_RDWR, 0644)) == -1)
        return;
    tmp = hist;
    while (tmp)
    {
        dprintf(fd, "%s\n", (char*)tmp->ptr);
        tmp = CLIST_NEXT(hist, tmp);
    }
    close(fd);
}
