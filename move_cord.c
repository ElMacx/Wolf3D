/*
** move_cord.c for move_cord in /home/dulin_m/rendu/wolf3D
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Sat Jan 11 13:59:35 2014 maxime dulin
** Last update Sun Jan 12 18:55:00 2014 maxime dulin
*/

#include <math.h>
#include "wolf.h"

int	check_my_map(t_gen *gen)
{
  float tmpx;
  float tmpy;

  tmpx = gen->pos.x0;
  tmpy = gen->pos.y0;
  tmpx = tmpx + gen->pos.adj;
  tmpy = tmpy + gen->pos.opp;
  if (gen->wolf.map[(int)tmpy][(int)tmpx] == 0)
    return (1);
  else
    return (0);
}

int	check_my_map2(t_gen *gen)
{
  float tmpx;
  float tmpy;

  tmpx = gen->pos.x0;
  tmpy = gen->pos.y0;
  tmpx = tmpx - gen->pos.adj;
  tmpy = tmpy - gen->pos.opp;
  if (gen->wolf.map[(int)tmpy][(int)tmpx] == 0)
    return (1);
  else
    return (0);
}

int	copy_data(t_gen *gen)
{
  int	i;

  i = 0;
  while (i < (gen->pam.sizeline * 720))
    {
      gen->pam.data[i] = gen->pam.back[i];
      i++;
    }
}

int	calc_adj(t_gen *gen)
{
  gen->pos.adj = cosf(gen->pos.alpha) * 0.03;
  gen->pos.opp = tanf(gen->pos.alpha) * gen->pos.adj;
}

int	move_cord(int key, t_gen *gen)
{
  copy_data(gen);
  if (key == 65361)
    gen->pos.alpha = gen->pos.alpha + 0.04;
  if (key == 65363)
    gen->pos.alpha = gen->pos.alpha - 0.04;
  calc_adj(gen);
  if (key == 65362 && gen->pos.x0 > 1 && gen->pos.y0 > 1 &&
      gen->pos.x0 < 9 && gen->pos.y0 < 9)
    {
      if ((check_my_map(gen)) == 1)
	{
	  gen->pos.x0 = gen->pos.x0 + gen->pos.adj;
	  gen->pos.y0 = gen->pos.y0 + gen->pos.opp;
	}
    }
  else if (key == 65364)
    {
      if ((check_my_map2(gen)) == 1)
	{
	  gen->pos.x0 = gen->pos.x0 - gen->pos.adj;
	  gen->pos.y0 = gen->pos.y0 - gen->pos.opp;
	}
    }
  calc_wall(gen);
}
