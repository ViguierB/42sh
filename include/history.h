/*
** history.h for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/include/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Fri May  5 18:33:28 2017 Guilhem Fulcrand
** Last update Fri May 19 18:22:02 2017 Guilhem Fulcrand
*/

#include "libmy.h"

#ifndef HISTORY_H
# define HISTORY_H

/* EXIT */

# ifndef EXIT_S
#  define EXIT_S        0
# endif

# ifndef EXIT_F
#  define EXIT_F        84
# endif

typedef struct          s_hist
{
    t_clist             *list;
    t_clist             *start;
    int                 nb;
}                       t_hist;

t_hist  *my_history();

#endif
