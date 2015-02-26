/*
** calc_xy.c for calc_xy in /home/dulin_m/rendu/wolf3D
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Fri Jan 10 18:49:09 2014 maxime dulin
** Last update Sun Jan 12 19:04:09 2014 maxime dulin
*/

#include <math.h>
#include "wolf.h"

float	calc_x(t_gen *gen)
{
  float mem;

  mem = 10000;
  while (gen->pos.xf < 10)
    {
      gen->pos.k = (gen->pos.xf - gen->pos.x0) / gen->pos.vx;
      gen->pos.iy = gen->pos.y0 + gen->pos.k * gen->pos.vy;
      if (gen->pos.k > 0 && gen->pos.iy > 0 && gen->pos.iy < 10)
	{
	  if (check_my_iy(gen) == 1)
	    {
	      if (gen->pos.k < mem)
		mem = gen->pos.k;
	    }
	}
      gen->pos.xf++;
    }
  return (mem);
}

float	calc_y(t_gen *gen)
{
  float mem;

  mem = 10000;
  while (gen->pos.yf < 10)
    {
      gen->pos.k = (gen->pos.yf - gen->pos.y0) / gen->pos.vy;
      gen->pos.ix = gen->pos.x0 + gen->pos.k * gen->pos.vx;
      if (gen->pos.k > 0 && gen->pos.ix > 0 && gen->pos.ix < 10)
	{
	  if (check_my_ix(gen) == 1)
	    {
	      if (gen->pos.k < mem)
		mem = gen->pos.k;
	    }
	}
      gen->pos.yf++;
    }
  return (mem);
}

int	calc_base(t_gen *gen, int ct)
{
  gen->pos.xf = 1;
  gen->pos.yf = 1;
  gen->pos.y = ((1080 / 2) - (float)ct) / 1080;
  gen->pos.xp = (gen->pos.d * cosf(gen->pos.alpha)) -
    (gen->pos.y * sinf(gen->pos.alpha));
  gen->pos.yp = (gen->pos.d * sinf(gen->pos.alpha)) +
    (gen->pos.y * cosf(gen->pos.alpha));
  gen->pos.xpp = gen->pos.xp + gen->pos.x0;
  gen->pos.ypp = gen->pos.yp + gen->pos.y0;
}
