/*
** my_hash_table_utils.c for libmy in /home/benji_epitech/workdir/perso/libmy/tmp/lib/my
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Sat Mar 25 14:06:16 2017 Benjamin Viguier
** Last update Sun Mar 26 22:49:46 2017 Benjamin Viguier
*/

#include "hash_table.h"

uint32_t	jenkins_hash_str(char *buffer)
{
  uint32_t	hash;

  hash = 0;
  while (*buffer)
    {
      hash += *((unsigned char*) (buffer++));
      hash += (hash << 10);
      hash ^= (hash >> 6);
    }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return (hash);
}

uint32_t	jenkins_hash_ptr(char *buffer)
{
  uint32_t	hash;
  size_t	len;
  char		*buf;

  buf = (void*) &buffer;
  len = sizeof(void*);
  hash = 0;
  while (len--)
    {
      hash += *((unsigned char*) (buf++));
      hash += (hash << 10);
      hash ^= (hash >> 6);
    }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return (hash);
}
