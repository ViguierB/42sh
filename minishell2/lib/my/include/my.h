/*
** my.h for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 10 13:41:19 2016 Benjamin Viguier
** Last update Fri Jan 13 10:33:11 2017 Benjamin Viguier
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>

# define POS(x) ((x < 0) ? -(x) : (x))
# define IS_NUM(c) (((c) >= '0' && ((c) <= '9')))
# define IS_PRINTABLE(c) (((c) >= 32) && ((c) < 127))
# define IS_POS(x) ((x < 0) ? (-1) : (1))

# define BUFF_LEN 32
# define INT_IDENT (1 << 0)
# define HEX_IDENT (1 << 1)
# define OCT_IDENT (1 << 2)
# define STR_IDENT (1 << 3)
# define CHA_IDENT (1 << 4)
# define PTR_IDENT (1 << 5)
# define BIN_IDENT (1 << 6)

typedef unsigned int		t_uint;
typedef unsigned long long	t_ull;
typedef struct	s_print_melm
{
  char		*modif;
  void		*(*fct)(va_list);
  int		len;
}		t_print_melm;
typedef struct	s_val
{
  void		*data;
  t_print_melm	*melm;
}		t_val;
typedef struct	s_flag_parm
{
  int		pos;
  char		*d;
  char		p;
}		t_flag_parm;
typedef struct	s_flag
{
  char		*patern;
  char		**ptr_list;
  char		d_f;
  char		m_f;
  char		p_f;
  char		s_f;
  char		z_f;
  char		a_f;
}		t_flag;
typedef struct	s_param
{
  char		*(*type)(struct s_param *, va_list);
  t_val		modif;
  int		*preci;
  int		*width;
  t_flag	*flag;
  char		ismod;
  char		c;
  char		*allowed;
  int		preci_type;
}		t_param;
typedef struct		s_stack
{
  char			c;
  struct s_stack	*next;
}			t_stack;
typedef struct	s_stack_pair
{
  t_stack	*stack;
  t_stack	*prev;
}		t_stack_pair;
typedef char	*(*t_param_funct)(t_param *, va_list);
typedef struct	s_print_telm
{
  char		type;
  t_param_funct	fct;
  char		*allowed_flag;
  int		preci_type;
}		t_print_telm;
t_print_telm	*g_tab_tfct;
t_print_melm	*g_tab_mfct;

t_stack	*stack_push(t_stack *stack, char val);
t_stack *stack_peek(t_stack *stack, char *val);
t_stack *stack_insert(t_stack *stack, char val);
char	*stack_to_str(t_stack *stack, int size);
t_stack	*stack_insert_bef(t_stack *prev, t_stack *stack, char val);

int	my_putchar(char c);
int	my_put_nbr(int nbr);
int	my_putstr(char *str);
int	my_strlen(char *str);
char*	my_strdup(char *str);
char*	my_get_u_nbr(char *str, t_uint *res);
int	fast_str_dup(char *str, char **res);
int	my_putnbr_base(int nb, char *base);

t_flag_parm	*init_t_flag_p(int ident, char *str, char c);
t_stack		*exec_flag(t_param *par, t_stack *stack,
			   int *s, t_flag_parm *flag);
int		allowed_flag(t_param *par, char c);

void	printf_b(int out, char *format, va_list ap, int *n_count);
void	on_mod(char **format, va_list ap, int *n_count, int can);
int	my_printf(char *format, ...);
int	my_fprintf(int fd, char *format, ...);
int	my_vfprintf(int fd, char *format, va_list ap);

char	*exec_param(t_param *parm, va_list ap, int *n_count);
t_param	*get_param(char **format, va_list ap);
int	search_flags(t_param *par, char **format, char **flag_list);
char	**get_flag_blist(t_flag *f);
t_flag	*init_flag(void);
void	free_flag(t_flag *f);
int	get_flag_pos(t_flag *f, char c);
int	init_param(t_param **res);
int	free_param(t_param *to_free);
t_stack	*ew_np(t_param *par, t_stack *stack, char *is_s, char *to_print);
t_stack	*verif_wap(t_param *par, t_stack *res, int *count);
int	get_param_flag(t_param *par, char **format);
int	get_param_width(t_param *par, char **format, va_list ap);
int	get_param_preci(t_param *par, char **format, va_list ap);
int	get_type_or_modif(t_param *par, char **format);
int	get_modif(t_param *par, char **format);
int	get_fct(t_param *par, char **format);
char	*print_int(t_param *par, va_list ap);
char	*print_uint(t_param *par, va_list ap);
char	*print_xhex(t_param *par, va_list ap);
char	*print_bxhex(t_param *par, va_list ap);
char	*print_char(t_param *par, va_list ap);
char	*print_str(t_param *par, va_list ap);
char	*print_bstr(t_param *par, va_list ap);
char	*print_oct(t_param *par, va_list ap);
char	*print_ptr(t_param *par, va_list ap);
char	*print_bin(t_param *par, va_list ap);
char	*print_mod(t_param *par, va_list ap);
char	*print_unknow(t_param *par, va_list ap);

int		get_t_val(t_param *par, va_list ap);
t_stack		*exec_width(t_param *par, t_stack *stack,
			    t_stack *prev, int *cur_size);
t_stack_pair	*creat_pair(t_stack *a, t_stack *b);
t_stack		*exec_int_preci(t_param *par, t_stack_pair *pair, int *s);
t_stack		*exec_str_preci(t_param *par, t_stack_pair *pair, int *s);
void		r_push_stack(t_stack **stack, int *s,
			     t_flag_parm *flag);

void	*modif_i(va_list ap);
void	*modif_ll(va_list ap);
void	*modif_l(va_list ap);
void	*modif_h(va_list ap);
void	*modif_z(va_list ap);
void	*modif_j(va_list ap);
void	*modif_hh(va_list ap);

#endif /* !MY_H_ */
