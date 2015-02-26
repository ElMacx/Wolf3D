/*
** calc_wall.c for calc_wall in /home/dulin_m/rendu/wolf3D
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Jan  7 18:33:54 2014 maxime dulin
** Last update Sun Jan 12 19:03:03 2014 maxime dulin
*/

#include <math.h>
#include "wolf.h"

int	check_my_iy(t_gen *gen)
{
  int	ct;

  if (gen->pos.xf < gen->pos.x0)
    ct = 1;
  else
    ct = 0;
  if (gen->wolf.map[(int)gen->pos.iy][(int)gen->pos.xf - ct] == 1)
    return (1);
  else
    return (0);
}

int	check_my_ix(t_gen *gen)
{
  int	ct;

  if (gen->pos.yf < gen->pos.y0)
    ct = 1;
  else
    ct = 0;
  if (gen->wolf.map[(int)gen->pos.yf - ct][(int)gen->pos.ix] == 1)
    return (1);
  else
    return (0);
}

int	draw_wall(float mem, int ct, t_gen *gen, int i)
{
  float	wall;
  t_id	id;

  wall = 720 / (2 * mem);
  id.x1 = ct;
  id.x2 = ct;
  id.y1 = 360 - wall - 1;
  id.y2 = 360 + wall;
  while (++id.y1 <= id.y2)
    {
      if (i == 0)
	my_pixel_put_to_image(&id, gen, i);
      if (i == 1)
	my_pixel_put_to_image2(&id, gen, i);
    }
}

int	initialize(t_gen *gen)
{
  gen->pos.d = 0.5;
  gen->pos.x0 = 1.5;
  gen->pos.y0 = 1.5;
  gen->pos.ix = 0;
  gen->pos.iy = 0;
  gen->pos.alpha = 0;
  gen->pos.alpha = gen->pos.alpha / 180 * PI;
}

t_pos	calc_wall(t_gen *gen)
{
  int	ct;
  float	mem;
  float mem2;
  int	i;
  int	j;

  j = 0;
  i = 1;
  ct = 0;
  while (ct <= 1080)
    {
      calc_base(gen, ct);
      gen->pos.vx = gen->pos.xpp - gen->pos.x0;
      gen->pos.vy = gen->pos.ypp - gen->pos.y0;
      mem = calc_x(gen);
      mem2 = calc_y(gen);
      if (mem <= mem2)
	draw_wall(mem, ct, gen, i);
      if (mem2 <= mem)
	draw_wall(mem2, ct, gen, j);
      ct++;
    }
}
