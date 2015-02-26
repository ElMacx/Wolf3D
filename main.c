/*
** main.c for main in /home/dulin_m/rendu/wolf3D
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Thu Jan  2 11:52:18 2014 maxime dulin
** Last update Tue Feb  4 14:39:22 2014 maxime dulin
*/

#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "wolf.h"

int	gest_key(int key, t_gen *gen)
{
  if (key == 65362 || key == 122)
    move_cord(key, gen);
  if (key == 65361 || key == 133)
    move_cord(key, gen);
  if (key == 65363 || key == 100)
    move_cord(key, gen);
  if (key == 65364 || key == 115)
    move_cord(key, gen);
  if (key == 65307)
    exit(0);
  mlx_put_image_to_window(gen->cord.mlx, gen->cord.win, gen->cord.img, 0, 0);
  mlx_do_sync(gen->cord.mlx);
  return (0);
}

int	gest_expose(t_gen *gen)
{
  mlx_put_image_to_window(gen->cord.mlx, gen->cord.win, gen->cord.img, 0, 0);
  mlx_do_sync(gen->cord.mlx);
  return (0);
}

void	gest_back(t_gen *gen)
{
  int	i;
  int	up;
  int	down;

  i = gen->pam.bpp/8;
  up = 777600;
  down = 388000;
  gen->pam.back = malloc(sizeof(char) * gen->pam.sizeline * 720);
  while (up != 388000)
    {
      gen->pam.back[i] = mlx_get_color_value(gen->cord.mlx, 150);
      gen->pam.back[i + 1] = mlx_get_color_value(gen->cord.mlx, 120);
      gen->pam.back[i + 2] = mlx_get_color_value(gen->cord.mlx, 60);
      up--;
      i = i + 4;
    }
  while (down != 0)
    {
      gen->pam.back[i] = mlx_get_color_value(gen->cord.mlx, 0);
      gen->pam.back[i + 1] = mlx_get_color_value(gen->cord.mlx, 100);
      gen->pam.back[i + 2] = mlx_get_color_value(gen->cord.mlx, 40);
      down--;
      i = i + 4;
    }
}

int	main(int ac, char **av)
{
  t_gen gen;
  int	endian;

  recup_map(&gen, ac, av);
  if (gen.wolf.map == NULL)
    return (0);
  if ((gen.cord.mlx = mlx_init()) == NULL)
    return (0);
  gen.cord.win = mlx_new_window(gen.cord.mlx, 1080, 720, "Wold3D");
  gen.cord.img = mlx_new_image(gen.cord.mlx, 1080, 720);
  gen.pam.data = mlx_get_data_addr(gen.cord.img,
				   &gen.pam.bpp, &gen.pam.sizeline, &endian);
  gest_back(&gen);
  initialize(&gen);
  copy_data(&gen);
  calc_wall(&gen);
  mlx_put_image_to_window(gen.cord.mlx, gen.cord.win, gen.cord.img, 0, 0);
  mlx_do_sync(gen.cord.mlx);
  mlx_hook(gen.cord.win, 2, (1L<<0), gest_key, &gen);
  mlx_hook(gen.cord.win, 3, (1L<<1), gest_key, &gen);
  mlx_expose_hook(gen.cord.win, gest_expose, &gen);
  mlx_loop(gen.cord.mlx);
  mlx_destroy_window(gen.cord.mlx, gen.cord.win);
}
