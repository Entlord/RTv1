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
# define	NO_FILE			"Error input: param no file : "

# define HELLOWORLD "Hello World"

t_ball				*new_ball(void);
t_tube				*new_tube(void);
t_cone				*new_cone(void);
t_plan				*new_plan(void);
t_box				*new_box(void);
t_object			*new_object(void);




#endif
