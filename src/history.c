/*
** history.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Thu May 18 20:54:01 2017 Guilhem Fulcrand
** Last update Fri May 19 18:22:48 2017 Guilhem Fulcrand
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "mysh.h"
#include "history.h"

t_hist      *my_history()
{
    t_hist  *hist;
    t_my_fd *fd;
    char    *line;

    if (!(hist = malloc(sizeof(t_hist))))
        return (NULL);
    hist->nb = 0;
    hist->list = NULL;
    if (!(fd = my_fopen(".history", O_RDONLY)))
        return (NULL);
    while ((line = my_getline(fd)))
    {
        hist->list = clist_push(hist->list, line);
        hist->nb++;
    }
    my_fclose(fd);
    hist->start = hist->list;
    return (0);
}

void            print_hist(t_hist *hist)
{
    t_clist     *tmp;

    tmp = hist->list;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->ptr);
        tmp = CLIST_NEXT(hist->list, tmp);
    }
}
