/*
** stack.c for my_printf in /home/benji_epitech/System_Unix/PSU_2016_my_printf
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Thu Nov 10 13:13:08 2016 Benjamin Viguier
** Last update Tue Nov 15 17:02:36 2016 Benjamin Viguier
*/

#include "my.h"

t_stack	*stack_push(t_stack *stack, char val)
{
  t_stack	*elm;

  elm = malloc(sizeof(t_stack));
  if (elm == NULL)
    return (stack);
  elm->c = val;
  elm->next = stack;
  return (elm);
}

t_stack	*stack_peek(t_stack *stack, char *val)
{
  t_stack	*elm;

  if (stack)
    {
      *val = stack->c;
      elm = stack->next;
      free(stack);
      return (elm);
    }
  else
    return (NULL);
}

t_stack *stack_insert(t_stack *stack, char val)
{
  t_stack	*elm;

  if (stack)
    {
      elm = malloc(sizeof(t_stack));
      if (elm == NULL)
	return (NULL);
      elm->next = stack->next;
      stack->next = elm;
      elm->c = val;
      return (elm);
    }
  else
    return (stack_push(stack, val));
}

t_stack		*stack_insert_bef(t_stack *prev, t_stack *stack, char val)
{
  t_stack	*elm;

  if (stack || prev)
    {
      elm = malloc(sizeof(t_stack));
      if (elm == NULL)
	return (NULL);
      if (prev)
	  prev->next = elm;
      elm->next = stack;
      elm->c = val;
      return (elm);
    }
  else
    return (stack_push(stack, val));
}

char	*stack_to_str(t_stack *stack, int size)
{
  char	*res;
  int	i;

  res = malloc(sizeof(char) * (size + 1));
  if (res == NULL)
    return (NULL);
  res[size] = '\0';
  i = 0;
  while (size)
    {
      stack = stack_peek(stack, (res + i));
      size -= 1;
      i += 1;
    }
  return (res);
}
