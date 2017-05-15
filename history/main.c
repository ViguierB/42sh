/*
** main.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/history/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May  5 18:38:22 2017 Guilhem Fulcrand
** Last update Fri May 12 18:37:08 2017 Guilhem Fulcrand
*/

#include <stdlib.h>

#include "history.h"
#include "libmy.h"

int     main()
{
    t_clist   *list;
    char      *line;
    t_my_fd   *fd;

    list = NULL;
    fd = get_fd_from_fd(0);
    while (1)
    {
        my_printf("$>");
        line =
    }
    list = clist_push(list, "salut");
    list = clist_push(list, "patate");
    return (EXIT_S);
}
