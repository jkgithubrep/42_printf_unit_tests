#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_o.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_o_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_o_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_o";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%o|%-o|%#o|%0o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1o|%-1o|%#o|%01o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23o|%-23o|%#o|%023o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.o|%-.o|%#.o|%0.o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5o|%-.5o|%#.5o|%0.5o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.o|%-1.o|%#1.o|%01.o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.o|%-23.o|%#23.o|%023.o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5o|%-1.5o|%#1.5o|%01.5o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5o|%-23.5o|%#23.5o|%023.5o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#o|%-0o|%#0o|%-#0o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1o|%-01o|%#01o|%-#01o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23o|%-023o|%#023o|%-#023o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.o|%-0.o|%#0.o|%-#0.o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5o|%-0.5o|%#0.5o|%-#0.5o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.o|%-01.o|%#01.o|%-#01.o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5o|%-01.5o|%#01.5o|%-#01.5o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.o|%-023.o|%#023.o|%-#023.o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5o|%-023.5o|%#023.5o|%-#023.5o\", 0U, 0U, 0U, 0U",
			&conv_o_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%o|%-o|%#o|%0o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1o|%-1o|%#o|%01o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23o|%-23o|%#o|%023o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.o|%-.o|%#.o|%0.o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5o|%-.5o|%#.5o|%0.5o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.o|%-1.o|%#1.o|%01.o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.o|%-23.o|%#23.o|%023.o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5o|%-1.5o|%#1.5o|%01.5o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5o|%-23.5o|%#23.5o|%023.5o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#o|%-0o|%#0o|%-#0o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1o|%-01o|%#01o|%-#01o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23o|%-023o|%#023o|%-#023o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.o|%-0.o|%#0.o|%-#0.o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5o|%-0.5o|%#0.5o|%-#0.5o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.o|%-01.o|%#01.o|%-#01.o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5o|%-01.5o|%#01.5o|%-#01.5o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.o|%-023.o|%#023.o|%-#023.o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5o|%-023.5o|%#023.5o|%-#023.5o\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_o_uint_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%o|%-o|%#o|%0o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1o|%-1o|%#o|%01o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23o|%-23o|%#o|%023o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.o|%-.o|%#.o|%0.o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5o|%-.5o|%#.5o|%0.5o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.o|%-1.o|%#1.o|%01.o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.o|%-23.o|%#23.o|%023.o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5o|%-1.5o|%#1.5o|%01.5o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5o|%-23.5o|%#23.5o|%023.5o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#o|%-0o|%#0o|%-#0o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1o|%-01o|%#01o|%-#01o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23o|%-023o|%#023o|%-#023o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.o|%-0.o|%#0.o|%-#0.o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5o|%-0.5o|%#0.5o|%-#0.5o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.o|%-01.o|%#01.o|%-#01.o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5o|%-01.5o|%#01.5o|%-#01.5o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.o|%-023.o|%#023.o|%-#023.o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5o|%-023.5o|%#023.5o|%-#023.5o\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_o_ulong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%o|%-o|%#o|%0o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1o|%-1o|%#o|%01o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23o|%-23o|%#o|%023o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.o|%-.o|%#.o|%0.o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5o|%-.5o|%#.5o|%0.5o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.o|%-1.o|%#1.o|%01.o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.o|%-23.o|%#23.o|%023.o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5o|%-1.5o|%#1.5o|%01.5o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5o|%-23.5o|%#23.5o|%023.5o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#o|%-0o|%#0o|%-#0o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1o|%-01o|%#01o|%-#01o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23o|%-023o|%#023o|%-#023o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.o|%-0.o|%#0.o|%-#0.o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5o|%-0.5o|%#0.5o|%-#0.5o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.o|%-01.o|%#01.o|%-#01.o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5o|%-01.5o|%#01.5o|%-#01.5o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.o|%-023.o|%#023.o|%-#023.o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5o|%-023.5o|%#023.5o|%-#023.5o\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hho|%-hho|%#hho|%0hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hho|%-1hho|%#hho|%01hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hho|%-23hho|%#hho|%023hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hho|%-.hho|%#.hho|%0.hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hho|%-.5hho|%#.5hho|%0.5hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hho|%-1.hho|%#1.hho|%01.hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hho|%-23.hho|%#23.hho|%023.hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hho|%-1.5hho|%#1.5hho|%01.5hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hho|%-23.5hho|%#23.5hho|%023.5hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#hho|%-0hho|%#0hho|%-#0hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1hho|%-01hho|%#01hho|%-#01hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23hho|%-023hho|%#023hho|%-#023hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.hho|%-0.hho|%#0.hho|%-#0.hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5hho|%-0.5hho|%#0.5hho|%-#0.5hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.hho|%-01.hho|%#01.hho|%-#01.hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5hho|%-01.5hho|%#01.5hho|%-#01.5hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.hho|%-023.hho|%#023.hho|%-#023.hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5hho|%-023.5hho|%#023.5hho|%-#023.5hho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%ho|%-ho|%#ho|%0ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1ho|%-1ho|%#ho|%01ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23ho|%-23ho|%#ho|%023ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.ho|%-.ho|%#.ho|%0.ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5ho|%-.5ho|%#.5ho|%0.5ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.ho|%-1.ho|%#1.ho|%01.ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.ho|%-23.ho|%#23.ho|%023.ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5ho|%-1.5ho|%#1.5ho|%01.5ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5ho|%-23.5ho|%#23.5ho|%023.5ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#ho|%-0ho|%#0ho|%-#0ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1ho|%-01ho|%#01ho|%-#01ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23ho|%-023ho|%#023ho|%-#023ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.ho|%-0.ho|%#0.ho|%-#0.ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5ho|%-0.5ho|%#0.5ho|%-#0.5ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.ho|%-01.ho|%#01.ho|%-#01.ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5ho|%-01.5ho|%#01.5ho|%-#01.5ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.ho|%-023.ho|%#023.ho|%-#023.ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5ho|%-023.5ho|%#023.5ho|%-#023.5ho\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lo|%-lo|%#lo|%0lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lo|%-1lo|%#lo|%01lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lo|%-23lo|%#lo|%023lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lo|%-.lo|%#.lo|%0.lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lo|%-.5lo|%#.5lo|%0.5lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lo|%-1.lo|%#1.lo|%01.lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lo|%-23.lo|%#23.lo|%023.lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lo|%-1.5lo|%#1.5lo|%01.5lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lo|%-23.5lo|%#23.5lo|%023.5lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#lo|%-0lo|%#0lo|%-#0lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1lo|%-01lo|%#01lo|%-#01lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23lo|%-023lo|%#023lo|%-#023lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.lo|%-0.lo|%#0.lo|%-#0.lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5lo|%-0.5lo|%#0.5lo|%-#0.5lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.lo|%-01.lo|%#01.lo|%-#01.lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5lo|%-01.5lo|%#01.5lo|%-#01.5lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.lo|%-023.lo|%#023.lo|%-#023.lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5lo|%-023.5lo|%#023.5lo|%-#023.5lo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%llo|%-llo|%#llo|%0llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1llo|%-1llo|%#llo|%01llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23llo|%-23llo|%#llo|%023llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.llo|%-.llo|%#.llo|%0.llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5llo|%-.5llo|%#.5llo|%0.5llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.llo|%-1.llo|%#1.llo|%01.llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.llo|%-23.llo|%#23.llo|%023.llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5llo|%-1.5llo|%#1.5llo|%01.5llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5llo|%-23.5llo|%#23.5llo|%023.5llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#llo|%-0llo|%#0llo|%-#0llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1llo|%-01llo|%#01llo|%-#01llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23llo|%-023llo|%#023llo|%-#023llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.llo|%-0.llo|%#0.llo|%-#0.llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5llo|%-0.5llo|%#0.5llo|%-#0.5llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.llo|%-01.llo|%#01.llo|%-#01.llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5llo|%-01.5llo|%#01.5llo|%-#01.5llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.llo|%-023.llo|%#023.llo|%-#023.llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5llo|%-023.5llo|%#023.5llo|%-#023.5llo\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_o_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
