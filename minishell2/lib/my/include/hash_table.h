/*
** hash_table.h for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat Mar 25 11:05:54 2017 Benjamin Viguier
** Last update Tue Apr  4 21:43:48 2017 Benjamin Viguier
*/

#ifndef HASH_TABLE_H_
# define HASH_TABLE_H_

# include <stdlib.h>
# include <stdint.h>

# ifndef BASIC_HT_SIZE
#  define BASIC_HT_SIZE (1024)
# endif /* !BASIC_HT_SIZE */

/*
** INVALIDPTR est retourné si le pointeur donné est NULL ou 0xFFFFFF...
*/
typedef enum	e_ht_error
  {
    ALREADYSET,
    INVALIDPTR,
    OTHERERROR,
    SUCCESS
  }		t_ht_error;

typedef uint32_t	(*t_hash_fct)(char *);

typedef struct	s_ht_elm
{
  int		islist;
  void		*value;
}		t_ht_elm;

typedef struct	s_ht
{
  t_ht_elm	*buffer;
  t_hash_fct	hash_fct;
  size_t	len;
}		t_ht;

typedef t_ht	t_memgrb;

/*
** Pour hash_fct est une fonction de hashage, de base les fonctions de /
**   d'initialisation utilise jenkins_hash_ptr pour hasher la clé.
*/
t_ht		*init_ht(size_t len, t_hash_fct hash_fct);
int		init_allowed_ht(t_ht *ht,  size_t len, t_hash_fct hash_fct);
t_ht_error	set_ht_value(t_ht *ht, void *value, void *key);
t_ht_elm	*get_ht_value(t_ht *ht, void *key);
t_ht_error	remove_ht_value(t_ht *ht, void *value, void *key);

/*
** Hash_function :
*/
uint32_t	jenkins_hash_str(char *buffer);
uint32_t	jenkins_hash_ptr(char *buffer);

#endif /* !HASH_TABLE_H_ */
