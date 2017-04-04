#include <rt.h>

/**
 *
 *	1/ Calcul de nombre de degrés entre deux pixels
 *	Le camera->fov représente le fov horizontal
 *	Le fov vertical est (fov horizontal * hauteur / largeur)
 *	
 *	2/ Calcul de l'angle de rotation a partir du milieu de l'écran
 *
 *	3/ Rotation du vecteur
 *
 *	4/ Normalisation du vecteur
 *
**/

t_vector	get_camera_vector(const t_cam *camera, int x, int y)
{	
	t_vector	ray;
	double		gap_x;
	double		gap_y;
	float		rotation_x;
	float		rotation_z;

	gap_x = (double)camera->fov / (double)camera->width;
	gap_y = ((double)camera->fov * (double)camera->height / (double)camera->width) / (double)camera->height;
	ray.x = camera->direction.x;
	ray.y = camera->direction.y;
	ray.z = camera->direction.z;
	rotation_x = gap_y * (y - camera->height / 2);
	rotation_z = gap_x * (x - camera->width / 2);
	// printf("gap : %f %f\n", gap_x, gap_y);
	// printf("camera : {%f, %f, %f}\n", camera->direction.x, camera->direction.y, camera->direction.z);
	// printf("screen : %d * %d # fov : %d\n\n", camera->width, camera->height, camera->fov);
	// printf("basic ray : \n%f \n%f \n%f\n", ray.x, ray.y, ray.z);
	ray = vector_rotate(ray, rotation_x, rotation_z);
	// printf("synced ray : \n%f \n%f \n%f\n", ray.x, ray.y, ray.z);
	// vector_normalize(&ray);

	return (ray); 
}
