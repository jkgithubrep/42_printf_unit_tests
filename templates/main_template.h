#ifndef MAIN_H
# define MAIN_H

/*PROTOTYPES_HERE*/

typedef struct		s_launcher
{
	char			*fct_name;
	int				(*launcher)(void);
}					t_launcher;

t_launcher			g_launchtab[] =
{
	/*FCTS_HERE*/
	{"", NULL}
};

#endif
