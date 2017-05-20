/*
** script.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May  6 11:30:21 2017 Alexandre Chamard-bois
** Last update Sat May 20 10:27:29 2017 Alexandre Chamard-bois
*/

#include "libmy.h"
#include "mysh.h"
#include "var.h"

#ifndef SCRIPT_H_
# define SCRIPT_H_

t_value do_egality(t_mysh *sh, t_var *var, char **tab);
char **recup_parentheses(char **tab, int *pos);
char *concatene_cond(char **cond);

#endif
