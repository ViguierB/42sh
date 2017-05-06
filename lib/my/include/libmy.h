/*
** libmy.h for libmy in /home/benji_epitech/System_Unix/PSU_2016_my_sokoban
**
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
**
** Started on  Mon Dec 12 13:19:11 2016 Benjamin Viguier
** Last update Sat May  6 14:18:14 2017 Alexandre Chamard-bois
*/

#ifndef LIBMY_H_
# define LIBMY_H_

# include <stdlib.h>
# include <sys/types.h>
# include "macro.h"

# define S_IN 0
# define S_OUT 1
# define S_ERR 2
# define LIBMY_INIT 21
# define LIBMY_GET 42
# define MY_FD_BUFF_LEN 1024
# define PSQ(x) ((x) * (x))
# define CLIST_NEXT(l, e) ((((e)->next) == (l)) ? ((void*) 0) : ((e)->next))

typedef struct	s_my_fd
{
  int		fd;
  char		buf[MY_FD_BUFF_LEN];
  int		rest;
  int		len;
}		t_my_fd;

typedef enum	s_whence
  {
    SBW_BEGIN,
    SBW_POS,
    SBW_END
  }		t_whence;

typedef struct	s_strbuilder
{
  char		buf[MY_FD_BUFF_LEN];
  size_t	len;
  char		*res;
  off_t		pos;
  size_t	res_len;
}		t_strbuilder;

typedef struct		s_clist
{
  void			*ptr;
  struct s_clist	*next;
  struct s_clist	*prev;
}			t_clist;
typedef t_clist		t_clist_elm;
typedef int		(*t_elm_cmp)(void *, void *);

typedef unsigned long	t_ulong;
typedef unsigned int	t_uint;
typedef unsigned short	t_usht;
typedef unsigned char	t_uchar;

/*
** Circular Linked List
*/
t_clist	*clist_push(t_clist *l, void *ptr);
void	clist_swap_val(t_clist_elm *elm1, t_clist_elm *elm2);
void	clist_free(t_clist *l);
void	clist_free_data(t_clist *l, void (*myfree)(void*));
t_clist	*clist_remove(t_clist *list, t_clist_elm *elm);
t_clist	*clist_rem_fdata(t_clist *list, t_clist_elm *elm,
			 void (*my_free)(void*));
void	clist_sort(t_clist *list, t_elm_cmp cmp_fct);
t_clist_elm	*clist_at(t_clist *list, int at);

/*
** Basics Functs
** Notes :
**	- nb_lines for my_split is optionnal,
**		use NULL if u don't want to use it.
*/

int	my_printf(char *fmt, ...);
int	my_fprintf(int fd, char *fmt, ...);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_puterror(char *error_str);
int	my_putnbr_base(int nb, char *base);
int	my_strlen(char *str);
int	my_malloc(void *ptr, size_t len);
char	*my_strconca(char *str1, char *str2);
char	*my_strcpy(char *dest, char *from);
char	*my_strncpy(char *dest, char *from, int n);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strdup(char *str);
char	*my_strndup(char *str, int n);
char	**my_split(char *inp, char sep, int *nb_lines);
int	my_showmem(char *str, int size);
void	*my_memcpy(void *dptr, void *fptr, size_t size);
void	my_memset(void *ptr, int c, size_t size);
int	my_memcmp(void *ptr1, void *ptr2, size_t len);
int	my_memisempty(void *ptr, size_t size);
char	*my_ftrim(char *str);
char	*my_trim(char *str);
int	my_isnum(char *str);
int	my_atoi(char *str);
int	my_strtol(char *str, long *res);
void	my_upper(char *str);
void	my_lower(char *str);
int	my_gethex(char *hex, int *res);
int my_isfloat(char *str);
char *clean_line(char *str);
int my_nbline(char **tab);
double my_atof(char *str);

/*
** my_fd functions
*/

t_my_fd	*my_fd_from_fd(const int fd);
t_my_fd	*my_fopen(char *path, int flags);
void	my_fclose(t_my_fd *to_free);
char	*my_getline(t_my_fd *pack);
ssize_t	my_fread(t_my_fd *pack, char *buffer, size_t size);
int	my_fread_to_end(t_my_fd *fd, char **res);

/*
** my_strbuilder functions
*/
t_strbuilder	*my_sb_init(void);
char		*my_sb_get_str(t_strbuilder *sb);
int		my_sb_write(t_strbuilder *sb, void *ptr, size_t size);
off_t		my_sb_seek(t_strbuilder *sb, off_t offset, t_whence whence);
char		*my_sb_flush(t_strbuilder *sb);
int		my_sb_ecrase(t_strbuilder *sb, size_t len);
void		my_sb_destroy(t_strbuilder *sb);

#endif /* !LIBMY_H_ */
