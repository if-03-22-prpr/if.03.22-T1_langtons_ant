/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Test functions for ADT 'Langtons's Ant'.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_LA_ANT_H
#define ___TEST_LA_ANT_H

#include "shortcut.h"

TEST(test_init_ant__shall_provide_valid_ant);
TEST(test_init_ant__shall_place_ant_on_world);
TEST(test_init_ant__shall_orientate_ant);
TEST(test_init_ant__shall_provide_invalid_ant__for_invalid_values);

TEST(test_get_ant__shall_provide_the_same_ant_each_time);

TEST(test_is_ant_valid__shall_be_invalid__for_null_ant);
TEST(test_is_ant_valid__shall_be_invalid__when_outside_world);

TEST(test_get_ant_x_pos__shall_provide_pos);
TEST(test_get_ant_x_pos__shall_provide_0__for_invalid_ant);
TEST(test_get_ant_y_pos__shall_provide_index);
TEST(test_get_ant_y_pos__shall_provide_0__for_invalid_ant);
TEST(test_get_ant_direction__shall_provide_direction);
TEST(test_get_ant_direction__shall_provide_north__for_invalid_ant);

TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_north);
TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_east);
TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_south);
TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_west);

TEST(test_step_ant__shall_flip_cell_color);

TEST(test_step_ant__shall_move_to_next_position__when_looking_at_north);
TEST(test_step_ant__shall_move_to_next_position__when_looking_at_east);
TEST(test_step_ant__shall_move_to_next_position__when_looking_at_south);
TEST(test_step_ant__shall_move_to_next_position__when_looking_at_west);

TEST(test_step_ant__shall_ignore_invalid_ant);

#endif
