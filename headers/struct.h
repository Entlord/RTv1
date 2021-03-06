#ifndef __STRUCT_H__
# define __STRUCT_H__

# define	BUFFER_SIZE		4096
# define	t_vector	t_coor

typedef struct		s_coor
{
	float			x;
	float			y;
	float			z;
}					t_coor;

typedef struct		s_color
{
	char			r;
	char			g;
	char			b;
}					t_color;

/*
**objects de la map
*/



typedef struct	s_ball
{
	t_coor		position;
	t_coor		direction;
	t_color		color;
	int			radius;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_ball;

typedef struct	s_tube
{
	t_coor		position;
	t_coor		direction;
	t_color		color;
	int			radius;
	int			height;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_tube;

typedef struct	s_cone
{
	t_coor		position;
	t_coor		direction;
	t_color		color;
	int			radius;
	int			height;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_cone;

typedef struct	s_plan
{
	t_coor		position;
	t_coor		direction;
	t_color		color;
	int			width;
	int			height;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_plan;

typedef	struct	s_box
{
	t_coor		position;
	t_coor		direction;
	t_color		color;
	int			width;
	int			height;
	int			depth;
	char		shiny;
	char		transparency;
	char		refraction;
}				t_box;

/*
**cam and light
*/

typedef struct	s_cam
{
	t_coor		position;
	t_coor		direction;
	int			fov;
	int			height;
	int			width;
}				t_cam;

typedef struct	s_light
{
	t_coor		position;
	t_coor		direction;
	t_color		color;
	int			radius;
}				t_light;

/*
**images and map
*/


typedef struct		s_object
{
	int				id;
	int				type;
	void			*object;
	t_box			collide_box;
	struct s_object	*next;
}					t_object;

typedef struct		s_map
{
	t_object		*object;
	t_cam			*cam;
	t_light			*light;
}					t_map;

typedef struct		s_img
{	
	int				height;
	int				width;
	t_color			**pixel;
}					t_img;

typedef struct		s_listrt
{
	void			*elem;
	struct s_listrt	*next;
}					t_list_rt;

/*
**buffer de fichier
*/

typedef struct		s_buff
{
	char			buf[BUFFER_SIZE];
	struct s_buff	*next;
}					t_buff;

#endif
