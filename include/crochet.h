/*
** crochet.h for ok in /home/alexandre/Documents/tek1/PSU_2016_42sh/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Sat May 13 10:44:25 2017 Alexandre Chamard-bois
** Last update Sun May 21 20:08:52 2017 alexandre Chamard-bois
*/

#ifndef CROCHET_H_
# define CROCHET_H_

# define REV(ret) (to_pars[3] ? !ret : ret)

typedef struct  s_pars_crochet
{
  char          *flag;
  int           pos;
  int           (*func)(char *tab[4]);
}               t_pars_crochet;

int _flag_n(char *to_pars[4]);
int _flag_z(char *to_pars[4]);
int _flag_eg(char *to_pars[4]);
int _flag_dif(char *to_pars[4]);
int _flag_num(char *to_pars[4]);
int _flag_d(char *to_pars[4]);
int _flag_e(char *to_pars[4]);
int _flag_f(char *to_pars[4]);

#endif
