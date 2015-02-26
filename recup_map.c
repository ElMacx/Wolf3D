/*
** recup_map.c for recup_map in /home/dulin_m/rendu/wolf3D
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Jan  7 11:08:45 2014 maxime dulin
** Last update Sun Jan 12 19:01:49 2014 maxime dulin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "wolf.h"

int	check_map(t_gen *gen)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (++j != gen->wolf.len_l - 1)
    {
      while (gen->wolf.map[0][++i] == 1)
	{
	  if (gen->wolf.map[0][i] != 1)
	    my_exit();
	}
      i = 0;
      while (gen->wolf.map[gen->wolf.len_l - 1][++i] == 1)
	{
	  if (gen->wolf.map[gen->wolf.len_l - 1][i] != 1)
	    my_exit();
	}
      if (gen->wolf.map[gen->wolf.len_l - 1][i] == 1)
	my_exit();
      if (gen->wolf.map[j][0] != 1)
	my_exit();
      if (gen->wolf.map[j][gen->wolf.len_c - 1] != 1)
	my_exit();
    }
}

int	map_lenght_lig(int ac, char **av)
{
  int	len;
  int	fd;

  len = 0;
  ac = ac;
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr("Program need map to run\n");
      exit(1);
    }
  while ((get_next_line(fd)) != NULL)
    len++;
  if ((close(fd)) == -1)
    {
      my_putstr("Close fail\n");
      exit(1);
    }
  return (len);
}

int	map_lenght_col(int ac, char **av)
{
  int	len;
  int	fd;

  len = 0;
  ac = ac;
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr("Program need map to run\n");
      exit(1);
    }
  while (get_next_line(fd) != NULL)
    len++;
  if ((close(fd)) == -1)
    {
      my_putstr("Close fail\n");
      exit(1);
    }
  return (len);
}

char	**recup_map(t_gen *gen, int ac, char **av)
{
  int	i;
  int	j;
  int	fd;

  i = -1;
  gen->wolf.len_l = map_lenght_lig(ac, av);
  if (gen->wolf.len_l <= 5)
    my_exit();
  if ((gen->wolf.map = malloc(sizeof(int *) * gen->wolf.len_l)) == NULL)
    exit(1);
  gen->wolf.len_c = map_lenght_col(ac, av);
  if ((fd = open(av[1], O_RDONLY)) == -1 || gen->wolf.len_c == 0)
    my_exit();
  while ((gen->wolf.s = get_next_line(fd)) != NULL)
    {
      j = 0;
      if ((gen->wolf.map[++i] = malloc(sizeof(int) * gen->wolf.len_c)) == NULL
	  || gen->wolf.len_c == 0)
	exit(1);
      while (j < gen->wolf.len_c)
	gen->wolf.map[i][j] = gen->wolf.s[j++] - 48;
    }
  check_map(gen);
  if ((close(fd)) == -1)
    my_exit2();
}
