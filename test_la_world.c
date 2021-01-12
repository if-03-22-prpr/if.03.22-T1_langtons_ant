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

#include "test_la_world.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"

#include "la_world.h"

#define ASSURE_INITIALIZED_WORLD(width, height) _assure_initialized_world(tc, width, height)
World _assure_initialized_world(struct TestCase* tc, Size width, Size height) {
	World world = init_world(width, height);
	ASSERT_TRUE(world != 0, MSG("Expected non-null world"));
	return world;
}

#define ASSERT_WORLD_SIZE(width, height, exp_width, exp_height) _assert_world_size(tc, width, height, exp_width, exp_height)
void _assert_world_size(struct TestCase* tc, Size width, Size height, Size exp_width, Size exp_height) {
	World world = init_world(width, height);
	Size act_width = get_world_width(world);
	Size act_height = get_world_height(world);
	ASSERT_TRUE(exp_width == act_width, MSG("Expected width of world being %d but got %d", exp_width, act_width));
	ASSERT_TRUE(exp_height == act_height, MSG("Expected height of world being %d but got %d", exp_height, act_height));
}

#define ASSERT_CELL_COLOR(world, x, y, init_color, flipped_color) _assert_cell_color(tc, world, x, y, init_color, flipped_color)
void _assert_cell_color(struct TestCase* tc, World world, Coord x, Coord y, Color init_color, Color flipped_color) {
	ASSERT_TRUE(get_cell_color(world, x, y) == init_color, MSG("Expected initial color of cell %d/%d being %s", x, y, (init_color == WHITE ? "WHITE" : "BLACK")));
	flip_cell_color(world, x, y);
	ASSERT_TRUE(get_cell_color(world, x, y) == flipped_color, MSG("Expected color of cell %d/%d being %s", x, y, (flipped_color == WHITE ? "WHITE" : "BLACK")));
}

#define ASSERT_NEXT_POSITION(check_column, width, height, direction, cur_pos, exp_pos) _assert_next_pos(tc, check_column, width, height, direction, cur_pos, exp_pos)
void _assert_next_pos(struct TestCase* tc, bool check_column, Size width, Size height, Direction direction, Coord cur_pos, Coord exp_pos) {
	World world = ASSURE_INITIALIZED_WORLD(width, height);
	Coord act_pos = check_column 
		? get_next_x_pos(world, cur_pos, direction)
		: get_next_y_pos(world, cur_pos, direction);
	ASSERT_TRUE(act_pos == exp_pos, MSG("Expected next %s from %d heading %s being %d but got %d", 
		check_column ? "X-POS" : "Y-POS",
		cur_pos,
		direction == EAST ? "EAST" : direction == SOUTH ? "SOUTH" : direction == WEST ? "WEST" : "NORTH",
		exp_pos, act_pos));
}


TEST(test_init_world__shall_provide_valid_world) {
	World world = init_world(7, 11);
	ASSERT_TRUE(world != 0, MSG("Expected non-null world"));
	ASSERT_TRUE(is_world_valid(world), MSG("Expected valid world"));
}

TEST(test_get_world__shall_provide_the_same_world_each_time) {
	World world1 = ASSURE_INITIALIZED_WORLD(7, 11);
	World world2 = get_world();
	ASSERT_TRUE(world2 != 0, MSG("Expected non-null world 2"));
	ASSERT_TRUE(world1 == world2, MSG("Expected same world"));
}

TEST(test_init_world__shall_make_all_cells_white) {
	Size w = 7;
	Size h = 11;
	World world = ASSURE_INITIALIZED_WORLD(w, h);
	flip_cell_color(world, 0, 0);
	flip_cell_color(world, w/2, h/2);
	flip_cell_color(world, w-1, h-1);
	 world = init_world(w, h);
	bool all_white = true;
	for (Coord r = 0; r < h; r++) {
		for (Coord c = 0; c < w; c++) {
			all_white = all_white && (get_cell_color(world, c, r) == WHITE);
		}		
	}
	ASSERT_TRUE(all_white, MSG("Expected that all cells are white after init"));
}

TEST(test_init_world__shall_define_the_size_of_the_world__for_regular_values) {
	ASSERT_WORLD_SIZE(11, 9, 11, 9);
}

TEST(test_init_world__shall_define_the_size_of_the_world__for_zero_values) {
	ASSERT_WORLD_SIZE(0, 1, 0, 0);
	ASSERT_WORLD_SIZE(1, 0, 0, 0);
}

TEST(test_init_world__shall_define_the_size_of_the_world__for_oversized_values) {
	ASSERT_WORLD_SIZE(MAX_WORLD_SIZE + 10, 3, MAX_WORLD_SIZE, 3);
	ASSERT_WORLD_SIZE(5, MAX_WORLD_SIZE + 10, 5, MAX_WORLD_SIZE);
	ASSERT_WORLD_SIZE(MAX_WORLD_SIZE + 10, MAX_WORLD_SIZE + 11, MAX_WORLD_SIZE, MAX_WORLD_SIZE);
}

TEST(test_is_world_valid__shall_be_valid_for_initialized_world) {
	ASSURE_INITIALIZED_WORLD(3, 4);
	ASSURE_INITIALIZED_WORLD(1, 1);
	ASSURE_INITIALIZED_WORLD(MAX_WORLD_SIZE, MAX_WORLD_SIZE);
}

TEST(test_is_world_valid__shall_be_invalid_for_0_world) {
	ASSERT_FALSE(is_world_valid(0), MSG("Expected null world being invalid"));
}

TEST(test_is_world_valid__shall_be_invalid_for_0_sized_world) {
	World world = init_world(0, 0);
	ASSERT_FALSE(is_world_valid(world), MSG("Expected world of size 0/0 being invalid"));
	world = init_world(0, 1);
	ASSERT_FALSE(is_world_valid(world), MSG("Expected world of size 0/1 being invalid"));
	world = init_world(1, 0);
	ASSERT_FALSE(is_world_valid(world), MSG("Expected world of size 1/0 being invalid"));
}

TEST(test_get_world_width__shall_be_0__for_invalid_world) {
	Size act_width = get_world_width(0);
	ASSERT_TRUE(act_width == 0, MSG("Expected width of invalid world being 0 but was %d", act_width));
}

TEST(test_get_world_height__shall_be_0__for_invalid_world) {
	Size act_height = get_world_height(0);
	ASSERT_TRUE(act_height == 0, MSG("Expected height of invalid world being 0 but was %d", act_height));
}

TEST(test_get_cell_color__shall_be_white__for_invalid_world) {
	Color act_color = get_cell_color(0, 0 ,0);
	ASSERT_TRUE(act_color == WHITE, MSG("Expected color of world being WHITE but was %d", act_color));
}

TEST(test_flip_cell_color__shall_change_a_white_cell_to_black) {
	World world = ASSURE_INITIALIZED_WORLD(11, 13);
	ASSERT_CELL_COLOR(world, 0, 0, WHITE, BLACK);
	ASSERT_CELL_COLOR(world, 7, 3, WHITE, BLACK);
	ASSERT_CELL_COLOR(world, 10, 12, WHITE, BLACK);
}

TEST(test_flip_cell_color__shall_change_a_black_cell_to_white) {
	World world = ASSURE_INITIALIZED_WORLD(13, 11);
	ASSERT_CELL_COLOR(world, 0, 0, WHITE, BLACK);
	ASSERT_CELL_COLOR(world, 0, 0, BLACK, WHITE);
	ASSERT_CELL_COLOR(world, 3, 7, WHITE, BLACK);
	ASSERT_CELL_COLOR(world, 3, 7, BLACK, WHITE);
	ASSERT_CELL_COLOR(world, 12, 10, WHITE, BLACK);
	ASSERT_CELL_COLOR(world, 12, 10, BLACK, WHITE);
}

TEST(test_flip_cell_color__shall_not_change_a_cell__for_invalid_world) {
	flip_cell_color(0, 0, 0);
}

TEST(test_get_next_x_pos__shall_provide_next_column__for_heading_east) {
	ASSERT_NEXT_POSITION(true, 11, 13, EAST, 0, 1);
	ASSERT_NEXT_POSITION(true, 11, 13, EAST, 6, 7);
	ASSERT_NEXT_POSITION(true, 11, 13, EAST, 9, 10);
}

TEST(test_get_next_x_pos__shall_provide_first_column__for_heading_east_across_border) {
	ASSERT_NEXT_POSITION(true, 13, 12, EAST, 12, 0);
}

TEST(test_get_next_x_pos__shall_provide_prev_column__for_heading_west) {
	ASSERT_NEXT_POSITION(true, 12, 13, WEST, 11, 10);
	ASSERT_NEXT_POSITION(true, 12, 13, WEST, 6, 5);
	ASSERT_NEXT_POSITION(true, 12, 13, WEST, 1, 0);
}

TEST(test_get_next_x_pos__shall_provide_last_column__for_heading_west_across_border) {
	ASSERT_NEXT_POSITION(true, 12, 13, WEST, 0, 11);
}

TEST(test_get_next_x_pos__shall_provide_cur_column__for_heading_north) {
	ASSERT_NEXT_POSITION(true, 10, 13, NORTH, 0, 0);
	ASSERT_NEXT_POSITION(true, 10, 13, NORTH, 7, 7);
	ASSERT_NEXT_POSITION(true, 10, 13, NORTH, 9, 9);
}
TEST(test_get_next_x_pos__shall_provide_cur_column__for_heading_south) {
	ASSERT_NEXT_POSITION(true, 12, 11, SOUTH, 0, 0);
	ASSERT_NEXT_POSITION(true, 12, 11, SOUTH, 7, 7);
	ASSERT_NEXT_POSITION(true, 12, 11, SOUTH, 11, 11);
}

TEST(test_get_next_x_pos__shall_provide_given_column__for_invalid_attributes) {
	ASSERT_NEXT_POSITION(true, 10, 12, NORTH, 10, 10);
	ASSERT_NEXT_POSITION(true, 10, 12, EAST, 10, 10);
	ASSERT_NEXT_POSITION(true, 10, 12, SOUTH, 10, 10);
	ASSERT_NEXT_POSITION(true, 10, 12, WEST, 10, 10);
}

TEST(test_get_next_y_pos__shall_provide_next_row__for_heading_south) {
	ASSERT_NEXT_POSITION(false, 12, 11, SOUTH, 0, 1);
	ASSERT_NEXT_POSITION(false, 12, 11, SOUTH, 5, 6);
	ASSERT_NEXT_POSITION(false, 12, 11, SOUTH, 9, 10);
}

TEST(test_get_next_y_pos__shall_provide_first_row__for_heading_south_across_border) {
	ASSERT_NEXT_POSITION(false, 12, 13, SOUTH, 12, 0);
}

TEST(test_get_next_y_pos__shall_provide_prev_row__for_heading_north) {
	ASSERT_NEXT_POSITION(false, 12, 13, NORTH, 1, 0);
	ASSERT_NEXT_POSITION(false, 12, 13, NORTH, 6, 5);
	ASSERT_NEXT_POSITION(false, 12, 13, NORTH, 12, 11);
}

TEST(test_get_next_y_pos__shall_provide_last_row__for_heading_north_across_border) {
	ASSERT_NEXT_POSITION(false, 12, 13, NORTH, 0, 12);
}

TEST(test_get_next_y_pos__shall_provide_cur_row__for_heading_east) {
	ASSERT_NEXT_POSITION(false, 12, 13, EAST, 0, 0);
	ASSERT_NEXT_POSITION(false, 12, 13, EAST, 5, 5);
	ASSERT_NEXT_POSITION(false, 12, 13, EAST, 12, 12);
}

TEST(test_get_next_y_pos__shall_provide_cur_row__for_heading_west) {
	ASSERT_NEXT_POSITION(false, 12, 13, WEST, 0, 0);
	ASSERT_NEXT_POSITION(false, 12, 13, WEST, 5, 5);
	ASSERT_NEXT_POSITION(false, 12, 13, WEST, 12, 12);
}

TEST(test_get_next_y_pos__shall_provide_given_row__for_invalid_attributes) {
	ASSERT_NEXT_POSITION(false, 10, 10, NORTH, 10, 10);
	ASSERT_NEXT_POSITION(false, 10, 10, EAST, 10, 10);
	ASSERT_NEXT_POSITION(false, 10, 10, SOUTH, 10, 10);
	ASSERT_NEXT_POSITION(false, 10, 10, WEST, 10, 10);
}

