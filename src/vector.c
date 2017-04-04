#include <rt.h>

static t_coor	vector_rotate_x(const t_coor vector, const float angle)
{
	t_coor	result;

	result.x = vector.x;
	result.y = vector.y * cosf(angle) - vector.z * sinf(angle);
	result.z = vector.y * sinf(angle) + vector.z * cosf(angle);

	return (result);
}

static t_vector	vector_rotate_z(const t_coor vector, const float angle)
{
	t_vector	result;

	result.x = vector.x * cosf(angle) + vector.y * sinf(angle);
	result.y = -vector.x * sinf(angle) + vector.y * cosf(angle);
	result.z = vector.z;

	return (result);
}

float		vector_get_length(const t_vector vector)
{
	float	length;

	length = sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	return (length);
}

t_vector	*vector_normalize(t_coor *vector)
{
	float length;

	length = sqrtf((vector->x * vector->x) + (vector->y * vector->y) + (vector->z * vector->z));
	vector->x = vector->x / length;
	vector->y = vector->y / length;
	vector->z = vector->z / length;

	return vector;
}

t_coor		vector_rotate(const t_vector a, float rotation_x, float rotation_z)
{
	t_vector	result;
	
	result.x = a.x;
	result.y = a.y;
	result.z = a.z;
	if (rotation_x)
		result = vector_rotate_x(result, rotation_x * M_PI / 180);
	if (rotation_z)
		result = vector_rotate_z(result, rotation_z * M_PI / 180);

	return (result);
}

t_vector	vector_add(const t_vector a, const t_vector b)
{
	t_vector result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}