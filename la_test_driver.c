/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Executes all unit tests of Langton's Ant.
 * ----------------------------------------------------------
 */

#include "shortcut.h"
#include "test_la_world.h"
#include "test_la_ant.h"

int main(int argc, char *argv[])
{
	/* WORLD ***********************************/
	ADD_TEST(test_init_world__shall_provide_valid_world);
	ADD_TEST(test_init_world__shall_make_all_cells_white);
	ADD_TEST(test_init_world__shall_define_the_size_of_the_world__for_regular_values);
	ADD_TEST(test_init_world__shall_define_the_size_of_the_world__for_zero_values);
	ADD_TEST(test_init_world__shall_define_the_size_of_the_world__for_oversized_values);

	ADD_TEST(test_get_world__shall_provide_the_same_world_each_time);

	ADD_TEST(test_is_world_valid__shall_be_valid_for_initialized_world);
	ADD_TEST(test_is_world_valid__shall_be_invalid_for_0_world);
	ADD_TEST(test_is_world_valid__shall_be_invalid_for_0_sized_world);

	ADD_TEST(test_get_world_width__shall_be_0__for_invalid_world);
	ADD_TEST(test_get_world_height__shall_be_0__for_invalid_world);
	ADD_TEST(test_get_cell_color__shall_be_white__for_invalid_world);

	ADD_TEST(test_flip_cell_color__shall_change_a_white_cell_to_black);
	ADD_TEST(test_flip_cell_color__shall_change_a_black_cell_to_white);
	ADD_TEST(test_flip_cell_color__shall_not_change_a_cell__for_invalid_world);

	ADD_TEST(test_get_next_x_pos__shall_provide_next_column__for_heading_east);
	ADD_TEST(test_get_next_x_pos__shall_provide_first_column__for_heading_east_across_border);
	ADD_TEST(test_get_next_x_pos__shall_provide_prev_column__for_heading_west);
	ADD_TEST(test_get_next_x_pos__shall_provide_last_column__for_heading_west_across_border);
	ADD_TEST(test_get_next_x_pos__shall_provide_cur_column__for_heading_north);
	ADD_TEST(test_get_next_x_pos__shall_provide_cur_column__for_heading_south);
	ADD_TEST(test_get_next_x_pos__shall_provide_given_column__for_invalid_attributes);

	ADD_TEST(test_get_next_y_pos__shall_provide_next_row__for_heading_south);
	ADD_TEST(test_get_next_y_pos__shall_provide_first_row__for_heading_south_across_border);
	ADD_TEST(test_get_next_y_pos__shall_provide_prev_row__for_heading_north);
	ADD_TEST(test_get_next_y_pos__shall_provide_last_row__for_heading_north_across_border);
	ADD_TEST(test_get_next_y_pos__shall_provide_cur_row__for_heading_east);
	ADD_TEST(test_get_next_y_pos__shall_provide_cur_row__for_heading_west);
	ADD_TEST(test_get_next_y_pos__shall_provide_given_row__for_invalid_attributes);

	/* ANT *************************************/
	ADD_TEST(test_init_ant__shall_provide_valid_ant);
	ADD_TEST(test_init_ant__shall_place_ant_on_world);
	ADD_TEST(test_init_ant__shall_orientate_ant);
	ADD_TEST(test_init_ant__shall_provide_invalid_ant__for_invalid_values);

	ADD_TEST(test_get_ant__shall_provide_the_same_ant_each_time);

	ADD_TEST(test_is_ant_valid__shall_be_invalid__for_null_ant);
	ADD_TEST(test_is_ant_valid__shall_be_invalid__when_outside_world);

	ADD_TEST(test_get_ant_x_pos__shall_provide_pos);
	ADD_TEST(test_get_ant_x_pos__shall_provide_0__for_invalid_ant);
	ADD_TEST(test_get_ant_y_pos__shall_provide_index);
	ADD_TEST(test_get_ant_y_pos__shall_provide_0__for_invalid_ant);
	ADD_TEST(test_get_ant_direction__shall_provide_direction);
	ADD_TEST(test_get_ant_direction__shall_provide_north__for_invalid_ant);

	ADD_TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_north);
	ADD_TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_east);
	ADD_TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_south);
	ADD_TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_west);

	ADD_TEST(test_step_ant__shall_flip_cell_color);

	ADD_TEST(test_step_ant__shall_move_to_next_position__when_looking_at_north);
	ADD_TEST(test_step_ant__shall_move_to_next_position__when_looking_at_east);
	ADD_TEST(test_step_ant__shall_move_to_next_position__when_looking_at_south);
	ADD_TEST(test_step_ant__shall_move_to_next_position__when_looking_at_west);

	ADD_TEST(test_step_ant__shall_ignore_invalid_ant);

	run_tests();
	return 0;
}
