#ifndef __VECTOR_H__
# define __VECTOR_H__

t_vector	*vector_normalize(t_coor *vector);
t_coor		vector_rotate(const t_coor a, float rotation_x, float rotation_z);
float		vector_get_length(const t_vector vector);
t_vector	vector_add(const t_vector a, const t_vector b);

#endif