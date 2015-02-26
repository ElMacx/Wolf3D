/*
** my_exit.c for my_exit in /home/dulin_m/rendu/wolf3D
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Jan  7 15:37:10 2014 maxime dulin
** Last update Tue Jan  7 15:39:49 2014 maxime dulin
*/

#include <stdlib.h>
#include <stdio.h>

void	my_exit()
{
  my_putstr("I can't open, I'm sorry...\n");
  exit(1);
}

void	my_exit2()
{
  my_putstr("Close fail\n");
  exit(1);
}
