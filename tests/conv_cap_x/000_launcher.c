#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_cap_x.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_cap_x_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_cap_x_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_cap_x";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%X|%-X|%#X|%0X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1X|%-1X|%#X|%01X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23X|%-23X|%#X|%023X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.X|%-.X|%#.X|%0.X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5X|%-.5X|%#.5X|%0.5X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.X|%-1.X|%#1.X|%01.X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.X|%-23.X|%#23.X|%023.X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5X|%-1.5X|%#1.5X|%01.5X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5X|%-23.5X|%#23.5X|%023.5X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#X|%-0X|%#0X|%-#0X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1X|%-01X|%#01X|%-#01X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23X|%-023X|%#023X|%-#023X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.X|%-0.X|%#0.X|%-#0.X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5X|%-0.5X|%#0.5X|%-#0.5X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.X|%-01.X|%#01.X|%-#01.X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5X|%-01.5X|%#01.5X|%-#01.5X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.X|%-023.X|%#023.X|%-#023.X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5X|%-023.5X|%#023.5X|%-#023.5X\", 0U, 0U, 0U, 0U",
			&conv_cap_x_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%X|%-X|%#X|%0X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1X|%-1X|%#X|%01X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23X|%-23X|%#X|%023X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.X|%-.X|%#.X|%0.X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5X|%-.5X|%#.5X|%0.5X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.X|%-1.X|%#1.X|%01.X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.X|%-23.X|%#23.X|%023.X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5X|%-1.5X|%#1.5X|%01.5X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5X|%-23.5X|%#23.5X|%023.5X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#X|%-0X|%#0X|%-#0X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1X|%-01X|%#01X|%-#01X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23X|%-023X|%#023X|%-#023X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.X|%-0.X|%#0.X|%-#0.X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5X|%-0.5X|%#0.5X|%-#0.5X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.X|%-01.X|%#01.X|%-#01.X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5X|%-01.5X|%#01.5X|%-#01.5X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.X|%-023.X|%#023.X|%-#023.X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5X|%-023.5X|%#023.5X|%-#023.5X\", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_cap_x_uint_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%X|%-X|%#X|%0X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1X|%-1X|%#X|%01X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23X|%-23X|%#X|%023X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.X|%-.X|%#.X|%0.X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5X|%-.5X|%#.5X|%0.5X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.X|%-1.X|%#1.X|%01.X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.X|%-23.X|%#23.X|%023.X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5X|%-1.5X|%#1.5X|%01.5X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5X|%-23.5X|%#23.5X|%023.5X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#X|%-0X|%#0X|%-#0X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1X|%-01X|%#01X|%-#01X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23X|%-023X|%#023X|%-#023X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.X|%-0.X|%#0.X|%-#0.X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5X|%-0.5X|%#0.5X|%-#0.5X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.X|%-01.X|%#01.X|%-#01.X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5X|%-01.5X|%#01.5X|%-#01.5X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.X|%-023.X|%#023.X|%-#023.X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5X|%-023.5X|%#023.5X|%-#023.5X\", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_cap_x_ulong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%X|%-X|%#X|%0X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1X|%-1X|%#X|%01X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23X|%-23X|%#X|%023X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.X|%-.X|%#.X|%0.X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5X|%-.5X|%#.5X|%0.5X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.X|%-1.X|%#1.X|%01.X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.X|%-23.X|%#23.X|%023.X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5X|%-1.5X|%#1.5X|%01.5X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5X|%-23.5X|%#23.5X|%023.5X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#X|%-0X|%#0X|%-#0X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1X|%-01X|%#01X|%-#01X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23X|%-023X|%#023X|%-#023X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.X|%-0.X|%#0.X|%-#0.X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5X|%-0.5X|%#0.5X|%-#0.5X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.X|%-01.X|%#01.X|%-#01.X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5X|%-01.5X|%#01.5X|%-#01.5X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.X|%-023.X|%#023.X|%-#023.X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5X|%-023.5X|%#023.5X|%-#023.5X\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhX|%-hhX|%#hhX|%0hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hhX|%-1hhX|%#hhX|%01hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hhX|%-23hhX|%#hhX|%023hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hhX|%-.hhX|%#.hhX|%0.hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hhX|%-.5hhX|%#.5hhX|%0.5hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hhX|%-1.hhX|%#1.hhX|%01.hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hhX|%-23.hhX|%#23.hhX|%023.hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hhX|%-1.5hhX|%#1.5hhX|%01.5hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hhX|%-23.5hhX|%#23.5hhX|%023.5hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#hhX|%-0hhX|%#0hhX|%-#0hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1hhX|%-01hhX|%#01hhX|%-#01hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23hhX|%-023hhX|%#023hhX|%-#023hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.hhX|%-0.hhX|%#0.hhX|%-#0.hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5hhX|%-0.5hhX|%#0.5hhX|%-#0.5hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.hhX|%-01.hhX|%#01.hhX|%-#01.hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5hhX|%-01.5hhX|%#01.5hhX|%-#01.5hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.hhX|%-023.hhX|%#023.hhX|%-#023.hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5hhX|%-023.5hhX|%#023.5hhX|%-#023.5hhX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hX|%-hX|%#hX|%0hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hX|%-1hX|%#hX|%01hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hX|%-23hX|%#hX|%023hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hX|%-.hX|%#.hX|%0.hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hX|%-.5hX|%#.5hX|%0.5hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hX|%-1.hX|%#1.hX|%01.hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hX|%-23.hX|%#23.hX|%023.hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hX|%-1.5hX|%#1.5hX|%01.5hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hX|%-23.5hX|%#23.5hX|%023.5hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#hX|%-0hX|%#0hX|%-#0hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1hX|%-01hX|%#01hX|%-#01hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23hX|%-023hX|%#023hX|%-#023hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.hX|%-0.hX|%#0.hX|%-#0.hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5hX|%-0.5hX|%#0.5hX|%-#0.5hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.hX|%-01.hX|%#01.hX|%-#01.hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5hX|%-01.5hX|%#01.5hX|%-#01.5hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.hX|%-023.hX|%#023.hX|%-#023.hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5hX|%-023.5hX|%#023.5hX|%-#023.5hX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lX|%-lX|%#lX|%0lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lX|%-1lX|%#lX|%01lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lX|%-23lX|%#lX|%023lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lX|%-.lX|%#.lX|%0.lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lX|%-.5lX|%#.5lX|%0.5lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lX|%-1.lX|%#1.lX|%01.lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lX|%-23.lX|%#23.lX|%023.lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lX|%-1.5lX|%#1.5lX|%01.5lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lX|%-23.5lX|%#23.5lX|%023.5lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#lX|%-0lX|%#0lX|%-#0lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1lX|%-01lX|%#01lX|%-#01lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23lX|%-023lX|%#023lX|%-#023lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.lX|%-0.lX|%#0.lX|%-#0.lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5lX|%-0.5lX|%#0.5lX|%-#0.5lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.lX|%-01.lX|%#01.lX|%-#01.lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5lX|%-01.5lX|%#01.5lX|%-#01.5lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.lX|%-023.lX|%#023.lX|%-#023.lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5lX|%-023.5lX|%#023.5lX|%-#023.5lX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%llX|%-llX|%#llX|%0llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1llX|%-1llX|%#llX|%01llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23llX|%-23llX|%#llX|%023llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.llX|%-.llX|%#.llX|%0.llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5llX|%-.5llX|%#.5llX|%0.5llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.llX|%-1.llX|%#1.llX|%01.llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.llX|%-23.llX|%#23.llX|%023.llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5llX|%-1.5llX|%#1.5llX|%01.5llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5llX|%-23.5llX|%#23.5llX|%023.5llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#llX|%-0llX|%#0llX|%-#0llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1llX|%-01llX|%#01llX|%-#01llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23llX|%-023llX|%#023llX|%-#023llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.llX|%-0.llX|%#0.llX|%-#0.llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#.5llX|%-0.5llX|%#0.5llX|%-#0.5llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.llX|%-01.llX|%#01.llX|%-#01.llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#1.5llX|%-01.5llX|%#01.5llX|%-#01.5llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.llX|%-023.llX|%#023.llX|%-#023.llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-#23.5llX|%-023.5llX|%#023.5llX|%-#023.5llX\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_cap_x_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
