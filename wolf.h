/*
** wolf.h for wolf in /home/dulin_m/rendu/wolf3D
**
** Made by maxime dulin
** Login   <dulin_m@epitech.net>
**
** Started on  Tue Jan  7 11:14:06 2014 maxime dulin
** Last update Sun Jan 12 19:13:42 2014 maxime dulin
*/

#ifndef _WOLF_H_
#define _WOLF_H_
#define BUFFER_SIZE 2
#define PI 3.141592653589793238462643383279

typedef struct	s_wolf
{
  int	**map;
  int	len_l;
  int	len_c;
  char	*s;
}		t_wolf;

typedef struct	s_pos
{
  float	alpha;
  float	d;
  float x0;
  float y0;
  float	x;
  float	y;
  float vx;
  float vy;
  float	k;
  float	ix;
  float iy;
  float xp;
  float yp;
  float ypp;
  float xpp;
  float xf;
  float yf;
  float adj;
  float opp;
}		t_pos;

typedef struct	s_id
{
  int	x1;
  int	x2;
  int	y1;
  int	y2;
}		t_id;

typedef struct	s_param
{
  int	bpp;
  char	*data;
  int	sizeline;
  char	*back;
}		t_param;

typedef struct	s_cord
{
  void	*mlx;
  void	*win;
  void	*img;
}		t_cord;

typedef struct	s_gen
{
  t_cord cord;
  t_wolf wolf;
  t_pos	pos;
  t_param pam;
}		t_gen;

/*
** main.c
*/

void gest_back(t_gen *gen);
int gest_expose(t_gen *gen);
int gest_key(int key, t_gen *gen);

/*
** calc_wall.c
*/

int check_my_ix(t_gen *gen);
int check_my_iy(t_gen *gen);
t_pos calc_wall(t_gen *gen);
int draw_wall(float mem, int ct, t_gen *gen, int i);
int initialize(t_gen *gen);

/*
** draw_line.c
*/

void my_pixel_put_to_image(t_id *id, t_gen *gen, int i);
void my_pixel_put_to_image2(t_id *id, t_gen *gen, int i);

/*
** move_cord.c
*/

int check_my_map(t_gen *gen);
int check_my_map2(t_gen *gen);
int copy_data(t_gen *gen);
int calc_adj(t_gen *gen);
int move_cord(int key, t_gen *gen);

/*
** calc_xy.c
*/

int calc_base(t_gen *gen, int ct);
float calc_x(t_gen *gen);
float calc_y(t_gen *gen);


/*
** my_exit.c
*/

void my_exit();
void my_exit2();

/*
** recup_map.c
*/

int check_map(t_gen *gen);
int map_lenght_col(int ac, char **av);
int map_lenght_lig(int ac, char **av);
char **recup_map(t_gen *gen, int ac, char **av);

#endif
