#include "frmk_libunit.h"
#include "ft_printf.h"
#include "conv_u.h"

/* Load test format:
	if ((err = load_test(&test_list, "TMPL_TEST_NAME",
			&conv_u_TMPL_TEST_FCT_NAME, SUCCESS)))
		return (err);
*/

int					conv_u_launcher(void)
{
	t_unit_test 	*test_list;
	char			*fct_name;
	int				err;
	int				fd;
	int				fd_trace;

	fct_name = "conv_u";
	err = 0;
	fd = TESTS_OUTPUT_FD;
	fd_trace = get_fd(TRACE_FILE, OUTPUT_MODE, OP_APPEND);
	test_list = NULL;
	print_fct_name_fd(fct_name, fd);
	if (fd_trace != fd)
		print_fct_name_trace_fd(fct_name, fd_trace);
	if ((err = load_test(&test_list, "\"%u|%-u|%0u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1u|%-1u|%01u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23u|%-23u|%023u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.u|%-.u|%0.u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5u|%-.5u|%0.5u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.u|%-1.u|%01.u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.u|%-23.u|%023.u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5u|%-1.5u|%01.5u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5u|%-23.5u|%023.5u\", 0U, 0U, 0U",
			&conv_u_zero_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0u\", 0U",
			&conv_u_zero_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5u\", 0U",
			&conv_u_zero_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%u|%-u|%0u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1u|%-1u|%01u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23u|%-23u|%023u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.u|%-.u|%0.u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5u|%-.5u|%0.5u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.u|%-1.u|%01.u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.u|%-23.u|%023.u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5u|%-1.5u|%01.5u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5u|%-23.5u|%023.5u\", UINT_MAX, UINT_MAX, UINT_MAX",
			&conv_u_uint_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5u\", UINT_MAX",
			&conv_u_uint_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%u|%-u|%0u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1u|%-1u|%01u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23u|%-23u|%023u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.u|%-.u|%0.u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5u|%-.5u|%0.5u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.u|%-1.u|%01.u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.u|%-23.u|%023.u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5u|%-1.5u|%01.5u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5u|%-23.5u|%023.5u\", ULONG_MAX, ULONG_MAX, ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5u\", ULONG_MAX",
			&conv_u_ulong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%u|%-u|%0u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1u|%-1u|%01u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23u|%-23u|%023u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.u|%-.u|%0.u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5u|%-.5u|%0.5u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.u|%-1.u|%01.u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.u|%-23.u|%023.u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5u|%-1.5u|%01.5u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5u|%-23.5u|%023.5u\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5u\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_5_precision, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hhu|%-hhu|%0hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_hh_modifier_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hhu|%-1hhu|%01hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hhu|%-23hhu|%023hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hhu|%-.hhu|%0.hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hhu|%-.5hhu|%0.5hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hhu|%-1.hhu|%01.hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hhu|%-23.hhu|%023.hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hhu|%-1.5hhu|%01.5hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hhu|%-23.5hhu|%023.5hhu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5hhu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_hh_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%hu|%-hu|%0hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_h, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1hu|%-1hu|%01hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23hu|%-23hu|%023hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.hu|%-.hu|%0.hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5hu|%-.5hu|%0.5hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.hu|%-1.hu|%01.hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.hu|%-23.hu|%023.hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5hu|%-1.5hu|%01.5hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5hu|%-23.5hu|%023.5hu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5hu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_h_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%lu|%-lu|%0lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1lu|%-1lu|%01lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23lu|%-23lu|%023lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.lu|%-.lu|%0.lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5lu|%-.5lu|%0.5lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.lu|%-1.lu|%01.lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.lu|%-23.lu|%023.lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5lu|%-1.5lu|%01.5lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5lu|%-23.5lu|%023.5lu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5lu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_l_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%llu|%-llu|%0llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1llu|%-1llu|%01llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23llu|%-23llu|%023llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.llu|%-.llu|%0.llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%.5llu|%-.5llu|%0.5llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.llu|%-1.llu|%01.llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.llu|%-23.llu|%023.llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%1.5llu|%-1.5llu|%01.5llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%23.5llu|%-23.5llu|%023.5llu\", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-0.5llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-01.5llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_1_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_dot_precision_ll_modifier, SUCCESS)))
		return (err);
	if ((err = load_test(&test_list, "\"%-023.5llu\", ULLONG_MAX",
			&conv_u_ullong_max_and_various_flags_combined_and_23_width_and_5_precision_ll_modifier, SUCCESS)))
		return (err);
	/*LOAD_TEST_HERE*/
	return (launch_tests(&test_list, fd));
}
