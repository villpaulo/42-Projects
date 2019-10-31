#ifndef HEADSTRUCT_H
# define HEADSTRUCT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_list
{
	void *content;
	size_t content_size;
	struct s_list *next;
} t_list;


#endif
