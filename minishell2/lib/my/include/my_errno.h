/*
** my_errno.h for libmy in /home/benji_epitech/C_Prog_Elem/CPE_2016_matchstick
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Fri Feb 17 13:39:01 2017 Benjamin Viguier
** Last update Fri Feb 17 13:52:48 2017 Benjamin Viguier
*/

#ifndef MY_ERRNO_H_
# define MY_ERRNO_H_

#define MERRNO_SET 1
#define MERRNO_GET 2

enum
  {
    ESUCCESS,
    ENOFILE,
    EBADARG
  };

typedef struct	s_merrno_msg
{
  int		err;
  char		*err_str;
}		t_merrno_msg;

char	*errno_msg(void);
int	my_perrno(char *str);
int	get_errno(void);
void	set_errno(int val);

#endif /* !MY_ERRNO_H_ */
