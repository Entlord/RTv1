#include <rt.h>

/*
 *
 *	get_minimal_distance_point : Renvoi la distance minimale entre une droite et un point
 *	pos : Position de la droite
 *	ray : Vecteur unitaire de la droite
 *	point : point
 *
 *	Retour : Distance minimal entre la droite et le point 
 *
 **/

static t_vector get_nearest_point(t_vector ray, t_coor point)
{
	t_vector	nearest;

	nearest.x = point.y * ray.z - point.z * ray.y;
	nearest.y = point.z * ray.x - point.x * ray.z;
	nearest.z = point.x * ray.y - point.y * ray.x;
	return nearest;
}

float	get_intersect_sphere(t_coor ray_pos, t_vector ray, t_ball sphere)
{
	t_vector	oriented_sphere_ray;
	float		oriented_sphere_ray_length;
	float		intersect;
	float		delta;
	
	sphere.position.x -= ray_pos.x;
	sphere.position.y -= ray_pos.y;
	sphere.position.z -= ray_pos.z;

	oriented_sphere_ray = get_nearest_point(ray, sphere.position);
	oriented_sphere_ray_length = vector_get_length(oriented_sphere_ray);
	intersect = vector_get_length(vector_add(sphere.position, oriented_sphere_ray));

	if (oriented_sphere_ray_length > sphere.radius)
		return (-1);
	else if (oriented_sphere_ray_length == sphere.radius)
		return (intersect);
	else
	{
		delta = sqrt(sphere.radius * sphere.radius - oriented_sphere_ray_length * oriented_sphere_ray_length);
		return (intersect - delta);
	}
}