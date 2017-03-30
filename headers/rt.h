#ifndef __RT_H__
# define __RT_H__

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <struct.h>

# define	NO_PARAM		"Error input: 0 param"

# define	ERROR_KEYWORD	-1
# define	MAP_NAME		1
# define	SPHERE 			2
# define	CYLINDER		3
# define	CONE 			4
# define	PLAN 			5
# define 	BOX 			6

t_ball				*new_ball(void);
t_tube				*new_tube(void);
t_cone				*new_cone(void);
t_plan				*new_plan(void);
t_box				*new_box(void);

t_list_rt			*new_list_rt(void);
t_list_rt			*file_check(int fd);
//a faire
t_object			*new_object(void);
//ft_push map
//


//fonction de lexeur

//fonction de lecture


//fonction de parcours dans une sphere


int				keyword_file_check(const char *str, size_t n);
size_t			keyword_file_size(const char *str);
void			keyword_tolower(char *str, size_t n);

#endif
