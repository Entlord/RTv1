#ifndef __RENDER_H__
# define __RENDER_H__

typedef float (*t_ptr_intersect)(t_coor, t_vector, void *);

typedef struct	s_dict_obj 
{
	int				type;
	t_ptr_intersect	f;
}				t_dict_obj;


#endif