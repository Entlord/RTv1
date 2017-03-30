#ifndef __STRUCT_H__
# define __STRUCT_H__

# define SPOT		1

typedef struct		s_coor
{
	float			x;
	float			y;
	float			z;
}					t_coor;

typedef struct		s_vector
{
	struct s_coor	position;
	struct s_coor	direction;
}					t_vector;

typedef struct		s_color
{
	char			red;
	char			green;
	char			blue;
}					t_color;

/*
**objects de la map
*/



typedef struct	s_ball
{
	t_vector	point;
	t_color		color;
	int			radius;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_ball;

typedef struct	s_tube
{
	t_vector	point;
	t_color		color;
	int			radius;
	int			height;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_tube;

typedef struct	s_cone
{
	t_vector	point;
	t_color		color;
	int			radius;
	int			height;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_cone;

typedef struct	s_plan
{
	t_vector	point;
	t_color		color;
	int			width;
	int			height;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_plan;

/*
**cam and light
*/

typedef struct	s_cam
{
	t_vector	point;
	int			fov;
	int			height;
	int			width;
}				t_cam;

typedef struct	s_light
{
	t_vector	point;
	t_color		color;
	int			radius;
}				t_light;

/*
**images and map
*/

typedef struct	s_map
{
	t_plan		*plan;
	t_ball		*ball;
	t_tube		*tube;
	t_cone		*cone;
	t_cam		*cam;
	t_light		*light;
}				t_map;

typedef struct	s_img
{
	int			height;
	int			width;
	t_color		**pixel;
}				t_img;

#endif
