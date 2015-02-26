/*
** draw_line.c for draw_line in /home/dulin_m/rendu/TP05
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Mon Dec  2 14:27:33 2013 maxime dulin
** Last update Sun Jan 12 18:46:53 2014 maxime dulin
*/

#include "mlx.h"
#include "wolf.h"

void	my_pixel_put_to_image(t_id *id, t_gen *gen, int i)
{
  float	al;

  al = gen->pos.alpha * PI / 180;
  if (id->y1 >= 0 && id->y1 <= 720 && id->x1 >= 0 && id->x1
      <= gen->pam.sizeline / 4 && i == 0 && gen->pos.vy >= 0)
    {
      i = gen->pam.sizeline * id->y1 + 4 * id->x1;
      gen->pam.data[i] = 200;
      gen->pam.data[i + 1] = 192;
      gen->pam.data[i + 2] = 50;
      gen->pam.data[i + 3] = 0;
    }
  if (id->y1 >= 0 && id->y1 <= 720 && id->x1 >= 0 && id->x1
      <= gen->pam.sizeline / 4 && i == 0 && gen->pos.vy < 0)
    {
      i = gen->pam.sizeline * id->y1 + 4 * id->x1;
      gen->pam.data[i] = 200;
      gen->pam.data[i + 1] = 57;
      gen->pam.data[i + 2] = 50;
      gen->pam.data[i + 3] = 0;
    }
}

void	my_pixel_put_to_image2(t_id *id, t_gen *gen, int i)
{
  if (id->y1 >= 0 && id->y1 <= 720 && id->x1 >= 0 && id->x1
      <= gen->pam.sizeline / 4 && i == 1 && gen->pos.vx >= 0)
    {
      i = gen->pam.sizeline * id->y1 + 4 * id->x1;
      gen->pam.data[i] = 77;
      gen->pam.data[i + 1] = 97;
      gen->pam.data[i + 2] = 198;
      gen->pam.data[i + 3] = 0;
    }
  if (id->y1 >= 0 && id->y1 <= 720 && id->x1 >= 0 && id->x1
      <= gen->pam.sizeline / 4 && i == 1 && gen->pos.vx < 0)
    {
      i = gen->pam.sizeline * id->y1 + 4 * id->x1;
      gen->pam.data[i] = 77;
      gen->pam.data[i + 1] = 215;
      gen->pam.data[i + 2] = 198;
      gen->pam.data[i + 3] = 0;
    }
}
