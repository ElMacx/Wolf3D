/*
** get_next_line.c for get_next_line in /home/dulin_m/rendu/CPE_2013_getnextline
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Dec  3 10:57:51 2013 maxime dulin
** Last update Sun Jan 12 19:04:24 2014 maxime dulin
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char 		*my_strcat(char *out, char *in)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (out[i] != 0)
    i++;
  while (in[j] != 0)
    {
      out[i] = in[j];
      i++;
      j++;
    }
  out[i] = 0;
}

char		*alloc_and_add(int size, char *to, char *from)
{
  char		*save;

  save = NULL;
  if (to != NULL)
    save = to;
  CHECK(to = malloc(size));
  to[0] = 0;
  if (save != NULL)
    my_strcat(to, save);
  if (from != NULL)
    my_strcat(to, from);
  return (to);
}

char		*is_there_n(int size, char *str)
{
  int		i;
  char		*ret;

  i = 0;
  ret = NULL;
  if (str != NULL)
    {
      while (str[i] != '\0' && str[i] != '\n')
	i++;
      if (str[i] == '\n')
	{
	  str[i] = 0;
	  CHECK(ret = alloc_and_add(size, ret, str));
	  else
	    return (ret);
	}
      else
	return (NULL);
    }
  return (NULL);
}

char		*free_left(char *left)
{
  char		*ret;
  int		i;

  if (left != NULL && *left != '\0')
    {
      i = 0;
      ret = NULL;
      while (left[i] != 0)
	i++;
      if (i != 0)
	CHECK(ret = alloc_and_add(i + 1, ret, left));
      return (ret);
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	*left;
  char		*buffer;
  char		*ret;
  int		rd;
  int		ofs;
  int		a;

  a = READ_AMT + 1;
  ofs = 0;
  CHECK(buffer = malloc(READ_AMT + 1));
  ret = NULL;
  while ((ret = is_there_n(a + 1, left)) == NULL)
    {
      if ((rd = read(fd, buffer, READ_AMT)) == -1)
	return (NULL);
      a = a + rd;
      buffer[rd] = 0;
      if (rd <= 0)
	return (left = free_left(left));
      CHECK(left = alloc_and_add(a + 1, left, buffer));
    }
  while (ret[ofs] != '\0')
    ofs++;
  left = left + ofs + 1;
  return (ret);
}
