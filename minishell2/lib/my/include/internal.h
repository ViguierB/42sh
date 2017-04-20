/*
** internal.h for libmy.h in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my/src
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Feb 23 15:09:08 2017 Benjamin Viguier
** Last update Mon Feb 27 13:47:57 2017 Benjamin Viguier
*/

#ifndef INTERNAL_H_
# define INTERNAL_H_

# include <stdarg.h>
# include "libmy.h"

/*
** my_printf struct, type & enum
*/
typedef struct	s_pf_data
{
  int		is_strbuffer;
  t_strbuilder	*sb;
  t_my_fd	*fd;
  int		pos;
  char		*fmt;
  va_list	va;
}		t_pf_data;

typedef union			u_pf_var
{
  long long int			d;
  unsigned long long int	ud;
  long double			ld;
  char				*s;
  void				*ptr;
}				t_pf_var;

typedef struct	s_pf_prm
{
  int		type;
  int		width;
  int		preci;
  int		flag;
  char		*pat;
  size_t	size;
  char		*save;
  t_pf_var	myvar;
}		t_pf_prm;

enum
  {
    PF_NO_FLAG		= 0x0,
    PF_FLAG_SUB		= 0x1,
    PF_FLAG_ADD		= 0x2,
    PF_FLAG_DEZ		= 0x4,
    PF_FLAG_SPACE	= 0x8,
    PF_FLAG_ZERO	= 0x10
  };

typedef struct	s_pf_prmflag
{
  int		type;
  char		c;
}		t_pf_prmflag;

typedef struct	s_pf_sprm
{
  char		*pat;
  size_t	size;
}		t_pf_sprm;

typedef struct		s_pf_type
{
  char			*pat;
  const t_pf_sprm	*sprm;
}			t_pf_type;

/*
** libmy internal functions
*/
int	__libmy_sb_flush(t_strbuilder *sb);
int	__libmy_sb_need_flush(t_strbuilder *sb);
int	__libmy_fd_need_flush(t_my_fd *fd);

/*
** my_print internal functions
*/
int	__pf_putchar(t_pf_data *data, char c);
int	__pf_flush(t_pf_data *data);
int	__pf_get_flags(t_pf_data *data, t_pf_prm *prm);
int	__pf_get_modpat(t_pf_data *data, t_pf_prm *prm);
int	__pf_format(t_pf_data *data, t_pf_prm *prm);
void	__pf_getd(va_list va, t_pf_prm *prm);
void	__pf_getud(va_list va, t_pf_prm *prm);
void	__pf_getrest(va_list va, t_pf_prm *prm, int type);

#endif /* !INTERNAL_H_ */
