#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_x.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_x_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_x_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_x";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%x|%-x|%#x|%0x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1x|%-1x|%#x|%01x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23x|%-23x|%#x|%023x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.x|%-.x|%#.x|%0.x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5x|%-.5x|%#.5x|%0.5x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.x|%-1.x|%#1.x|%01.x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.x|%-23.x|%#23.x|%023.x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5x|%-1.5x|%#1.5x|%01.5x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5x|%-23.5x|%#23.5x|%023.5x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#x|%-0x|%#0x|%-#0x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1x|%-01x|%#01x|%-#01x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23x|%-023x|%#023x|%-#023x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.x|%-0.x|%#0.x|%-#0.x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5x|%-0.5x|%#0.5x|%-#0.5x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.x|%-01.x|%#01.x|%-#01.x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5x|%-01.5x|%#01.5x|%-#01.5x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.x|%-023.x|%#023.x|%-#023.x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5x|%-023.5x|%#023.5x|%-#023.5x\", 0U, 0U, 0U, 0U",
			&conv_x_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%x|%-x|%#x|%0x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1x|%-1x|%#x|%01x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23x|%-23x|%#x|%023x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.x|%-.x|%#.x|%0.x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5x|%-.5x|%#.5x|%0.5x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.x|%-1.x|%#1.x|%01.x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.x|%-23.x|%#23.x|%023.x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5x|%-1.5x|%#1.5x|%01.5x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5x|%-23.5x|%#23.5x|%023.5x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#x|%-0x|%#0x|%-#0x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1x|%-01x|%#01x|%-#01x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23x|%-023x|%#023x|%-#023x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.x|%-0.x|%#0.x|%-#0.x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5x|%-0.5x|%#0.5x|%-#0.5x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.x|%-01.x|%#01.x|%-#01.x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5x|%-01.5x|%#01.5x|%-#01.5x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.x|%-023.x|%#023.x|%-#023.x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5x|%-023.5x|%#023.5x|%-#023.5x\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_x_uint_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%x|%-x|%#x|%0x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1x|%-1x|%#x|%01x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23x|%-23x|%#x|%023x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.x|%-.x|%#.x|%0.x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5x|%-.5x|%#.5x|%0.5x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.x|%-1.x|%#1.x|%01.x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.x|%-23.x|%#23.x|%023.x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5x|%-1.5x|%#1.5x|%01.5x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5x|%-23.5x|%#23.5x|%023.5x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#x|%-0x|%#0x|%-#0x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1x|%-01x|%#01x|%-#01x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23x|%-023x|%#023x|%-#023x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.x|%-0.x|%#0.x|%-#0.x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5x|%-0.5x|%#0.5x|%-#0.5x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.x|%-01.x|%#01.x|%-#01.x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5x|%-01.5x|%#01.5x|%-#01.5x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.x|%-023.x|%#023.x|%-#023.x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5x|%-023.5x|%#023.5x|%-#023.5x\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_x_ulong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%x|%-x|%#x|%0x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1x|%-1x|%#x|%01x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23x|%-23x|%#x|%023x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.x|%-.x|%#.x|%0.x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5x|%-.5x|%#.5x|%0.5x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.x|%-1.x|%#1.x|%01.x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.x|%-23.x|%#23.x|%023.x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5x|%-1.5x|%#1.5x|%01.5x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5x|%-23.5x|%#23.5x|%023.5x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#x|%-0x|%#0x|%-#0x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1x|%-01x|%#01x|%-#01x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23x|%-023x|%#023x|%-#023x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.x|%-0.x|%#0.x|%-#0.x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5x|%-0.5x|%#0.5x|%-#0.5x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.x|%-01.x|%#01.x|%-#01.x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5x|%-01.5x|%#01.5x|%-#01.5x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.x|%-023.x|%#023.x|%-#023.x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5x|%-023.5x|%#023.5x|%-#023.5x\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhx|%-hhx|%#hhx|%0hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hhx|%-1hhx|%#hhx|%01hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hhx|%-23hhx|%#hhx|%023hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hhx|%-.hhx|%#.hhx|%0.hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hhx|%-.5hhx|%#.5hhx|%0.5hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hhx|%-1.hhx|%#1.hhx|%01.hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hhx|%-23.hhx|%#23.hhx|%023.hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hhx|%-1.5hhx|%#1.5hhx|%01.5hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hhx|%-23.5hhx|%#23.5hhx|%023.5hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#hhx|%-0hhx|%#0hhx|%-#0hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1hhx|%-01hhx|%#01hhx|%-#01hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23hhx|%-023hhx|%#023hhx|%-#023hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.hhx|%-0.hhx|%#0.hhx|%-#0.hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5hhx|%-0.5hhx|%#0.5hhx|%-#0.5hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.hhx|%-01.hhx|%#01.hhx|%-#01.hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5hhx|%-01.5hhx|%#01.5hhx|%-#01.5hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.hhx|%-023.hhx|%#023.hhx|%-#023.hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5hhx|%-023.5hhx|%#023.5hhx|%-#023.5hhx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hx|%-hx|%#hx|%0hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hx|%-1hx|%#hx|%01hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hx|%-23hx|%#hx|%023hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hx|%-.hx|%#.hx|%0.hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hx|%-.5hx|%#.5hx|%0.5hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hx|%-1.hx|%#1.hx|%01.hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hx|%-23.hx|%#23.hx|%023.hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hx|%-1.5hx|%#1.5hx|%01.5hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hx|%-23.5hx|%#23.5hx|%023.5hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#hx|%-0hx|%#0hx|%-#0hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1hx|%-01hx|%#01hx|%-#01hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23hx|%-023hx|%#023hx|%-#023hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.hx|%-0.hx|%#0.hx|%-#0.hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5hx|%-0.5hx|%#0.5hx|%-#0.5hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.hx|%-01.hx|%#01.hx|%-#01.hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5hx|%-01.5hx|%#01.5hx|%-#01.5hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.hx|%-023.hx|%#023.hx|%-#023.hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5hx|%-023.5hx|%#023.5hx|%-#023.5hx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lx|%-lx|%#lx|%0lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lx|%-1lx|%#lx|%01lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lx|%-23lx|%#lx|%023lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lx|%-.lx|%#.lx|%0.lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lx|%-.5lx|%#.5lx|%0.5lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lx|%-1.lx|%#1.lx|%01.lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lx|%-23.lx|%#23.lx|%023.lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lx|%-1.5lx|%#1.5lx|%01.5lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lx|%-23.5lx|%#23.5lx|%023.5lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#lx|%-0lx|%#0lx|%-#0lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1lx|%-01lx|%#01lx|%-#01lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23lx|%-023lx|%#023lx|%-#023lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.lx|%-0.lx|%#0.lx|%-#0.lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5lx|%-0.5lx|%#0.5lx|%-#0.5lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.lx|%-01.lx|%#01.lx|%-#01.lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5lx|%-01.5lx|%#01.5lx|%-#01.5lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.lx|%-023.lx|%#023.lx|%-#023.lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5lx|%-023.5lx|%#023.5lx|%-#023.5lx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%llx|%-llx|%#llx|%0llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1llx|%-1llx|%#llx|%01llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23llx|%-23llx|%#llx|%023llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.llx|%-.llx|%#.llx|%0.llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5llx|%-.5llx|%#.5llx|%0.5llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.llx|%-1.llx|%#1.llx|%01.llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.llx|%-23.llx|%#23.llx|%023.llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5llx|%-1.5llx|%#1.5llx|%01.5llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5llx|%-23.5llx|%#23.5llx|%023.5llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#llx|%-0llx|%#0llx|%-#0llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1llx|%-01llx|%#01llx|%-#01llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23llx|%-023llx|%#023llx|%-#023llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.llx|%-0.llx|%#0.llx|%-#0.llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5llx|%-0.5llx|%#0.5llx|%-#0.5llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.llx|%-01.llx|%#01.llx|%-#01.llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5llx|%-01.5llx|%#01.5llx|%-#01.5llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.llx|%-023.llx|%#023.llx|%-#023.llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5llx|%-023.5llx|%#023.5llx|%-#023.5llx\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
