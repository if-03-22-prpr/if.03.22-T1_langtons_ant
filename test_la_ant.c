/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Test functions for ADT 'Langton's ant'.
 * ----------------------------------------------------------
 */

#include "test_la_ant.h"

#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "config.h"
#include "general.h"

#include "la_ant.h"
#include "la_world.h"

char* _to_dir_str(Direction direction) {
	switch (direction) {
		case NORTH: 
			return "NORTH";
		case EAST:
			return "EAST";
		case SOUTH:
			return "SOUTH";
		case WEST:
			return "WEST";
		default:
			break;
	}
	return "?";
}

#define ASSURE_ANT_ON_WORLD(w, x, y, direction) _assure_ant_on_world(tc, x, y, direction)
Ant _assure_ant_on_world(struct TestCase* tc, Coord x, Coord y, Direction direction) {
	Ant ant = init_ant(x, y, direction);
	ASSERT_TRUE(is_ant_valid(ant), MSG("Expected valid ant"));
	return ant;
}

#define ASSURE_INITIALIZED_ANT(w, h, x, y, direction) _assure_initialized_ant(tc, w, h, x, y, direction)
Ant _assure_initialized_ant(struct TestCase* tc, Size width, Size height, Coord x, Coord y, Direction direction) {
	init_world(width, height);
	return _assure_ant_on_world(tc, x, y, direction);
}

#define DO_STEP_ANT(world, init_x, init_y, init_dir, init_col) _do_step_ant(tc, world, init_x, init_y, init_dir, init_col)
Ant _do_step_ant(struct TestCase* tc, World world, Coord init_x, Coord init_y, Direction init_dir, Color init_col) {
	Ant ant = _assure_ant_on_world(tc, init_x, init_y, init_dir);
	Color col = get_cell_color(world, init_x, init_y);
	for (int i = 0; col != init_col && i < 2; i++) {
		flip_cell_color(world, init_x, init_y);
		col = get_cell_color(world, init_x, init_y);
	}
	ASSERT_TRUE(init_col == col, MSG("Could not apply desired initial color"));
	
	step_ant(ant);
	return ant;
}

#define ASSERT_ANT_STEP_DIRECTION(world, init_x, init_y, init_dir, init_col, exp_dir) _assert_ant_step_direction(tc, world, init_x, init_y, init_dir, init_col, exp_dir)
Ant _assert_ant_step_direction(struct TestCase* tc, World world, Coord init_x, Coord init_y, Direction init_dir, Color init_col, Direction exp_dir) {
	Ant ant = _do_step_ant(tc, world, init_x, init_y, init_dir, init_col);
	Direction act_dir = get_ant_direction(ant);
	ASSERT_TRUE(act_dir == exp_dir, MSG("Expected direction of ant changed from %s to %s", _to_dir_str(exp_dir), _to_dir_str(act_dir)));
	return ant;
}

#define ASSERT_ANT_STEP_POSITION(world, init_x, init_y, init_dir, init_col, exp_x, exp_y) _assert_ant_step_position(tc, world, init_x, init_y, init_dir, init_col, exp_x, exp_y)
Ant _assert_ant_step_position(struct TestCase* tc, World world, Coord init_x, Coord init_y, Direction init_dir, Color init_col, Coord exp_x, Coord exp_y) {
	Ant ant = _do_step_ant(tc, world, init_x, init_y, init_dir, init_col);
	Coord act_x = get_ant_x_pos(ant);
	Coord act_y = get_ant_y_pos(ant);
	ASSERT_TRUE(exp_x == act_x && exp_y == act_y, MSG("Expected ant moved from %d/%d to %d/%d but sits on %d/%d", init_x, init_y, exp_x, exp_y, act_x, act_y));
	return ant;
}


TEST(test_init_ant__shall_provide_valid_ant) {
	ASSURE_INITIALIZED_ANT(9, 11, 0, 0, NORTH);
	ASSURE_INITIALIZED_ANT(11, 9, 10, 8, EAST);
	ASSURE_INITIALIZED_ANT(7, 9, 5, 6, SOUTH);
	ASSURE_INITIALIZED_ANT(9, 7, 8, 0, WEST);
}

TEST(test_init_ant__shall_place_ant_on_world) {
	Coord exp_x = 3;
	Coord exp_y = 5;
	Ant ant = ASSURE_INITIALIZED_ANT(9, 11, exp_x, exp_y, NORTH);
	Coord act_x = get_ant_x_pos(ant);
	Coord act_y = get_ant_y_pos(ant);
	ASSERT_TRUE(act_x == exp_x && act_y == exp_y, MSG("Expected ant on %d/%d but found it on %d/%d", exp_x, exp_y, act_x, act_y));
}

TEST(test_init_ant__shall_orientate_ant) {
	Direction exp_dir = WEST;
	Ant ant = ASSURE_INITIALIZED_ANT(9, 11, 4, 1, exp_dir);
	Direction act_dir = get_ant_direction(ant);
	ASSERT_TRUE(exp_dir == act_dir, MSG("Expected ant looking at %s but it looked at %s", _to_dir_str(exp_dir), _to_dir_str(act_dir)));
}

TEST(test_init_ant__shall_provide_invalid_ant__for_invalid_values) {
	Size w = 5;
	Size h = 7;
	init_world(w, h);
	Ant ant = init_ant(w, (h - 1), WEST);
	ASSERT_FALSE(is_ant_valid(ant), MSG("Expected invalid ant when placed too far east"));
	ant = init_ant(w-1, h, NORTH);
	ASSERT_FALSE(is_ant_valid(ant), MSG("Expected invalid ant when placed too far south"));
}

TEST(test_get_ant__shall_provide_the_same_ant_each_time) {
	Ant ant1 = ASSURE_INITIALIZED_ANT(9, 11, 4, 1, WEST);
	Ant ant2 = get_ant();
	ASSERT_TRUE(ant1 == ant2, MSG("Expected the same ant"));
}

TEST(test_is_ant_valid__shall_be_invalid__for_null_ant) {
	ASSERT_FALSE(is_ant_valid(0), MSG("Expected invalid ant when null"));
}

TEST(test_is_ant_valid__shall_be_invalid__when_outside_world) {
	Ant ant = ASSURE_INITIALIZED_ANT(7, 9, 6, 8, EAST);
	init_world(4, 5);
	ASSERT_FALSE(is_ant_valid(ant), MSG("Expected invalid ant when outside world"));
}

TEST(test_get_ant_x_pos__shall_provide_pos) {
	Coord exp_x = 7;
	Coord exp_y = 1;
	Ant ant = ASSURE_INITIALIZED_ANT(9, 11, exp_x, exp_y, NORTH);
	Coord act_x = get_ant_x_pos(ant);
	ASSERT_TRUE(act_x == exp_x, MSG("Expected ant at X %d but found it on %d", exp_x, act_x));
}

TEST(test_get_ant_x_pos__shall_provide_0__for_invalid_ant) {
	Coord act_x = get_ant_x_pos(0);
	ASSERT_TRUE(act_x == 0, MSG("Expected ant at X 0 but found it on %d", act_x));
}

TEST(test_get_ant_y_pos__shall_provide_index) {
	Coord exp_x = 7;
	Coord exp_y = 1;
	Ant ant = ASSURE_INITIALIZED_ANT(9, 11, exp_x, exp_y, NORTH);
	Coord act_y = get_ant_y_pos(ant);
	ASSERT_TRUE(act_y == exp_y, MSG("Expected ant at Y %d but found it on %d", exp_y, act_y));
}

TEST(test_get_ant_y_pos__shall_provide_0__for_invalid_ant) {
	Coord act_y = get_ant_y_pos(0);
	ASSERT_TRUE(act_y == 0, MSG("Expected ant at Y 0 but found it on %d", act_y));
}

TEST(test_get_ant_direction__shall_provide_direction) {
	Direction exp_dir = EAST;
	Ant ant = ASSURE_INITIALIZED_ANT(9, 11, 4, 1, exp_dir);
	Direction act_dir = get_ant_direction(ant);
	ASSERT_TRUE(exp_dir == act_dir, MSG("Expected ant looking at %s but it looked at %s", _to_dir_str(exp_dir), _to_dir_str(act_dir)));
}

TEST(test_get_ant_direction__shall_provide_north__for_invalid_ant) {
	Direction act_dir = get_ant_direction(0);
	ASSERT_TRUE(NORTH == act_dir, MSG("Expected ant looking at %s but it looked at %s", _to_dir_str(NORTH), _to_dir_str(act_dir)));
}

TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_north) {
	World world = init_world(9, 11);
	ASSERT_ANT_STEP_DIRECTION(world, 5, 2, NORTH, WHITE, EAST);
	ASSERT_ANT_STEP_DIRECTION(world, 2, 5, NORTH, BLACK, WEST);
}

TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_east) {
	World world = init_world(9, 11);
	ASSERT_ANT_STEP_DIRECTION(world, 4, 6, EAST, WHITE, SOUTH);
	ASSERT_ANT_STEP_DIRECTION(world, 6, 4, EAST, BLACK, NORTH);
}

TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_south) {
	World world = init_world(9, 11);
	ASSERT_ANT_STEP_DIRECTION(world, 5, 2, SOUTH, WHITE, WEST);
	ASSERT_ANT_STEP_DIRECTION(world, 2, 5, SOUTH, BLACK, EAST);
}

TEST(test_step_ant__shall_turn_ant_direction_depending_on_cell_color__for_starting_with_west) {
	World world = init_world(9, 11);
	ASSERT_ANT_STEP_DIRECTION(world, 2, 1, WEST, WHITE, NORTH);
	ASSERT_ANT_STEP_DIRECTION(world, 1, 2, WEST, BLACK, SOUTH);
}

TEST(test_step_ant__shall_flip_cell_color) {
	Coord init_x = 3;
	Coord init_y = 4;
	Direction init_dir = NORTH;
	Color init_col = WHITE;
	Color exp_col = BLACK;

	World world = init_world(9, 11);
	Coord next_x = get_next_x_pos(world, init_x, init_dir);
	Coord next_y = get_next_y_pos(world, init_y, init_dir);
	Color next_col = get_cell_color(world, next_x, next_y);

	DO_STEP_ANT(world, init_x, init_y, init_dir, init_col);

	Color act_col = get_cell_color(world, init_x, init_y);
	Color act_next_col = get_cell_color(world, next_x, next_y);

	ASSERT_TRUE(exp_col == act_col, MSG("Expected that the color of the cell the ant left is changed"));
	ASSERT_TRUE(next_col == act_next_col, MSG("Expected that the color of the cell the ant entered is NOT changed"));
}

TEST(test_step_ant__shall_move_to_next_position__when_looking_at_north) {
	World world = init_world(9, 7);
	/* initial direction considers wanted stepping direction */
	ASSERT_ANT_STEP_POSITION(world, 3, 5, WEST, WHITE, 3, 4);
	ASSERT_ANT_STEP_POSITION(world, 0, 0, WEST, WHITE, 0, 6);
	ASSERT_ANT_STEP_POSITION(world, 8, 6, WEST, WHITE, 8, 5);
}

TEST(test_step_ant__shall_move_to_next_position__when_looking_at_east) {
	World world = init_world(9, 7);
	/* initial direction considers wanted stepping direction */
	ASSERT_ANT_STEP_POSITION(world, 3, 5, NORTH, WHITE, 4, 5);
	ASSERT_ANT_STEP_POSITION(world, 0, 0, NORTH, WHITE, 1, 0);
	ASSERT_ANT_STEP_POSITION(world, 8, 6, NORTH, WHITE, 0, 6);
}

TEST(test_step_ant__shall_move_to_next_position__when_looking_at_south) {
	World world = init_world(9, 7);
	/* initial direction considers wanted stepping direction */
	ASSERT_ANT_STEP_POSITION(world, 3, 5, EAST, WHITE, 3, 6);
	ASSERT_ANT_STEP_POSITION(world, 0, 0, EAST, WHITE, 0, 1);
	ASSERT_ANT_STEP_POSITION(world, 8, 6, EAST, WHITE, 8, 0);
}

TEST(test_step_ant__shall_move_to_next_position__when_looking_at_west) {
	World world = init_world(9, 7);
	/* initial direction considers wanted stepping direction */
	ASSERT_ANT_STEP_POSITION(world, 3, 5, SOUTH, WHITE, 2, 5);
	ASSERT_ANT_STEP_POSITION(world, 0, 0, SOUTH, WHITE, 8, 0);
	ASSERT_ANT_STEP_POSITION(world, 8, 6, SOUTH, WHITE, 7, 6);
}

TEST(test_step_ant__shall_ignore_invalid_ant) {
	step_ant(0);
}