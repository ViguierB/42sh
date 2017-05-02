/*
** my_printf.c for my_printf in /home/benji_epitech/System_Unix/my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Nov  9 11:19:19 2016 Benjamin Viguier
** Last update Tue Apr  4 13:38:41 2017 Benjamin Viguier
*/

#include "my.h"

t_print_telm	g_main_tab_tfct[] =
  {
    {'i', &print_int, "+-0 '", 1},
    {'d', &print_int, "+-0 '", 1},
    {'u', &print_uint, "-0'", 1},
    {'o', &print_oct, "#-0", 1},
    {'x', &print_xhex, "#-0", 1},
    {'X', &print_bxhex, "#-0", 1},
    {'c', &print_char, "-", 0},
    {'s', &print_str, "-", 2},
    {'p', &print_ptr, "#", 0},
    {'S', &print_bstr, "#-", 2},
    {'b', &print_bin, "#'", 1},
    {'%', &print_mod, "", 0},
    {'n', (t_param_funct) 1, NULL, 0},
    {'\0', NULL, NULL, 0}
  };

t_print_melm	g_main_tab_mfct[] =
  {
    {"l", &modif_l, sizeof(int) * 4},
    {"ll", &modif_ll, sizeof(int) * 4},
    {"j", &modif_j, sizeof(int) * 4},
    {"z", &modif_z, sizeof(int) * 4},
    {"h", &modif_h, sizeof(int) * 1},
    {"hh", &modif_hh, sizeof(int) * 1},
    {"i", &modif_i, sizeof(int) * 2},
    {NULL, NULL, 0}
  };

int		my_printf(char *format, ...)
{
  va_list	ap;
  int		res;

  va_start(ap, format);
  res = my_vfprintf(1, format, ap);
  va_end(ap);
  return (res);
}

int		my_fprintf(int fd, char *format, ...)
{
  va_list	ap;
  int		res;

  va_start(ap, format);
  res = my_vfprintf(fd, format, ap);
  va_end(ap);
  return (res);
}

int		my_vfprintf(int fd, char *format, va_list ap)
{
  int		n_count;

  n_count = 0;
  g_tab_tfct = g_main_tab_tfct;
  g_tab_mfct = g_main_tab_mfct;
  printf_b(fd, format, ap, &n_count);
  return (0);
}
