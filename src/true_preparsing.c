/*
** true_preparsing.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Wed May 17 17:57:58 2017 Guilhem Fulcrand
** Last update Thu May 18 14:52:50 2017 Alexandre Chamard-bois
*/

#include "my_env.h"
#include "mysh.h"

char        *true_preparsing(t_mysh *mysh, char *cmd)
{
    int     i;
    char    *home;

    i = -1;
    while (cmd[++i])
    {
      if (cmd[i] == '\t')
        cmd[i] = ' ';
        if (cmd[i] == '~')
        {
            if ((home = my_getenv(mysh->env, "HOME")))
                cmd = substr(cmd, home, i, 1);
            else
                cmd = substr(cmd, "/", i, 1);
        }
    }
    return (clean_line(cmd));
}
