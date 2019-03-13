#ifndef MAIN_H
# define MAIN_H

int	conv_f_launcher(void);
/*PROTOTYPES_HERE*/

typedef struct		s_launcher
{
	char			*fct_name;
	int				(*launcher)(void);
}					t_launcher;

t_launcher			g_launchtab[] =
{
	{"conv_f", conv_f_launcher},
	/*FCTS_HERE*/
	{"", NULL}
};

#endif
