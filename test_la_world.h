/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Test functions for ADT 'Ant's World'.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_LA_WORLD_H
#define ___TEST_LA_WORLD_H

#include "shortcut.h"

TEST(test_init_world__shall_provide_valid_world);
TEST(test_init_world__shall_make_all_cells_white);
TEST(test_init_world__shall_define_the_size_of_the_world__for_regular_values);
TEST(test_init_world__shall_define_the_size_of_the_world__for_zero_values);
TEST(test_init_world__shall_define_the_size_of_the_world__for_oversized_values);

TEST(test_get_world__shall_provide_the_same_world_each_time);


TEST(test_is_world_valid__shall_be_valid_for_initialized_world);
TEST(test_is_world_valid__shall_be_invalid_for_0_world);
TEST(test_is_world_valid__shall_be_invalid_for_0_sized_world);

TEST(test_get_world_width__shall_be_0__for_invalid_world);
TEST(test_get_world_height__shall_be_0__for_invalid_world);
TEST(test_get_cell_color__shall_be_white__for_invalid_world);

TEST(test_flip_cell_color__shall_change_a_white_cell_to_black);
TEST(test_flip_cell_color__shall_change_a_black_cell_to_white);
TEST(test_flip_cell_color__shall_not_change_a_cell__for_invalid_world);

TEST(test_get_next_x_pos__shall_provide_next_column__for_heading_east);
TEST(test_get_next_x_pos__shall_provide_first_column__for_heading_east_across_border);
TEST(test_get_next_x_pos__shall_provide_prev_column__for_heading_west);
TEST(test_get_next_x_pos__shall_provide_last_column__for_heading_west_across_border);
TEST(test_get_next_x_pos__shall_provide_cur_column__for_heading_north);
TEST(test_get_next_x_pos__shall_provide_cur_column__for_heading_south);
TEST(test_get_next_x_pos__shall_provide_given_column__for_invalid_attributes);

TEST(test_get_next_y_pos__shall_provide_next_row__for_heading_south);
TEST(test_get_next_y_pos__shall_provide_first_row__for_heading_south_across_border);
TEST(test_get_next_y_pos__shall_provide_prev_row__for_heading_north);
TEST(test_get_next_y_pos__shall_provide_last_row__for_heading_north_across_border);
TEST(test_get_next_y_pos__shall_provide_cur_row__for_heading_east);
TEST(test_get_next_y_pos__shall_provide_cur_row__for_heading_west);
TEST(test_get_next_y_pos__shall_provide_given_row__for_invalid_attributes);

#endif
