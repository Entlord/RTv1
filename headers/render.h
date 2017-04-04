#ifndef __RENDER_H__
# define __RENDER_H__

typedef struct	s_dict_obj 
{
	int			type;
	float		(*f)(t_coor, t_vector, void*);
}				t_dict_obj;


#endif