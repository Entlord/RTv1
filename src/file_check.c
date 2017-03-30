#include <rt.h>

t_list_rt		*file_check(int fd)
{
	t_list_rt	*map;

	(void)fd;
	if (!(map = new_list_rt()))
		perror(strerror(errno));
	/*
		var : sauvegarde struct tmp pour 

		si erreur dans la lecture du contenu du fichier :
			continuer et zapper le {} qui a une erreur
		Y a t'il le minimum à lire?
			Si non, supprimer l'élement de la liste

		retourner null ou la struct à push
	*/
	return (map);
}