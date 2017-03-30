#include <libft.h>
#include <struct.h>
#include <rt.h>


/*
	Gestion input
		fichier valide?
	Lexeur 
	parseur
	Appel partie matthieu
*/

/*
	init_window(200, 200);
	clear_image();
	copy_image_to_window();
	SDL_Delay(500);
	clear_image();
	SDL_Delay(500);
	free_resources();
*/

/*
static void		st_check_file(int fd, map, img)
{

}
*/

static void		st_check_list_param(int argc, char **argv//, 
									/*t_list_rt **map, t_list_rt **img*/)
{
		int		i;
		int		fd;

		i = 0;
		while (i < argc)
		{
			++i;
			fd = open(argv[i], O_RDONLY);
			if (fd == -1)
			{
				perror(strerror(errno));
			}
			else
			{
//				st_check_file(fd, map, img);
				if (close(fd) == -1)
					perror(strerror(errno));
				//calcul image
			}
		}
}

int				main(int argc, char **argv)
{
//	t_list_rt	*map;
//	t_list_rt	*img;


	if (argc == 1)
		ft_putstr(NO_PARAM);
	else
	{
//		map = NULL;
//		img = NULL;
		st_check_list_param(argc, argv);
		//free map;
		//free img;
	}
	return (0);
}
