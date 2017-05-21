/*
** true_preparsing.c for 42sh in /home/guilhem/C/Shell/PSU_2016_42sh/src/
**
** Made by Guilhem Fulcrand
** Login   <guilhem.fulcrand@epitech.eu>
**
** Started on  Wed May 17 17:57:58 2017 Guilhem Fulcrand
** Last update Sun May 21 11:20:33 2017 Alexandre Chamard-bois
*/

#include "my_env.h"
#include "parser.h"
#include "mysh.h"

char        *true_preparsing(t_mysh *mysh, char *cmd)
{
    int     i;
    char    *home;

    i = -1;
    while (cmd && cmd[++i])
    {
      if (cmd[i] == '\t' || cmd[i] == '\n')
        cmd[i] = ' ';
        else if (cmd[i] == '~' && (home = my_getenv(mysh->env, "HOME")))
          cmd = substr(cmd, home, i, 1);
        else if (cmd[i] == '`')
          cmd = magic_quote(mysh, cmd, i);
        else if (!my_strncmp(cmd + i, "!!", 2) && mysh->hist)
          cmd = substr(cmd, mysh->hist->prev->ptr, i, 2);
    }
    if (!cmd)
      return (NULL);
    return (clean_line(cmd));
}
