#ifndef MAIN_H
# define MAIN_H

int	no_type_launcher(void);
int	conv_d_launcher(void);
int	conv_i_launcher(void);
int	conv_u_launcher(void);
int	conv_o_launcher(void);
int	conv_x_launcher(void);
int	conv_cap_x_launcher(void);
int	conv_c_launcher(void);
int	conv_s_launcher(void);
int	conv_p_launcher(void);
int	conv_f_launcher(void);
int	mix_launcher(void);
/*PROTOTYPES_HERE*/

typedef struct		s_launcher
{
	char			*fct_name;
	int				(*launcher)(void);
}					t_launcher;

t_launcher			g_launchtab[] =
{
	{"no_type", no_type_launcher},
	{"conv_d", conv_d_launcher},
	{"conv_i", conv_i_launcher},
	{"conv_u", conv_u_launcher},
	{"conv_o", conv_o_launcher},
	{"conv_x", conv_x_launcher},
	{"conv_cap_x", conv_cap_x_launcher},
	{"conv_c", conv_c_launcher},
	{"conv_s", conv_s_launcher},
	{"conv_p", conv_p_launcher},
	{"conv_f", conv_f_launcher},
	{"mix", mix_launcher},
	/*FCTS_HERE*/
	{"", NULL}
};

#endif
