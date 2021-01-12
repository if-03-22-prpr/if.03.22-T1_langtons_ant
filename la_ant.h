/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant
 * Author:			*/<your name>/*
 * ----------------------------------------------------------
 * Description:
 * The declaration of an Abstract Data Type representing
 * the ant of Christopher Langton.
 * ----------------------------------------------------------
 */

/* note: common data types are declared in general.h */

/** Declares type for the ant, named 'Ant' */

/**
 * Initializes the only ant:
 * + Defines the initial position within it universe.
 * + Defines the initial direction.
 * 
 * Note: This functions requires an initialized world.
 * 
 * @param x The index of the column of the cell the ant starts 
 *                traveling from in range from 0 to world width - 1.
 * @param y The index of the row of the cell the ant starts 
 *                traveling from in range from 0 to world height - 1.
 * @param direction The initial viewing direction of the ant.
 * @return The initialized ant or 0, if given attributes are invalid.
 */
<type> init_ant(Coord x, Coord y, Direction direction);

/**
 * Provides the instance of the ant.
 * Exactly one instance is supported. 
 * The state of the ant is not affected by this function.
 * 
 * @return The ant instance.
 */
<type> get_ant();

/**
 * Determines whether or not the given ant is valid.
 * The ant is NOT valid
 *      + if it is 0,
 *      + or if it has a position outside the universe.
 * 
 * @param ant The ant instance in focus.
 * @return True if the given ant is valid, false otherwise.
 */
<type> is_ant_valid(<params>);

/**
 * Makes the ant take the next (one!) step according to its current direction.
 * A step of the ant consists of:
 *  1. determination of the color of the cell
 *  2. change of the ant's direction depending on the cell-color
 *     a) if the color is ´WHITE´: ant turns 90° clockwise (e.g from ´NORTH´ to ´EAST´ or from ´SOUTH´ to ´WEST´)
 *     b) if the color is ´BLACK´: ant turns 90° counter-clockwise (e.g from ´SOUTH´ to ´EAST´ or from ´NORTH´ to ´WEST´)
 *  3. flipping the color of the cell
 *  4. moving to the next cell according to the current direction by using ´get_next_x_pos(...)´ and ´get_next_y_pos(...)´.
 * 
 *     Note that the universe is endless: 
 *         If e.g. the ant would step out at the right border (East), 
 *         it actually steps into the left-most cell (West) in the same row and vice versa. 
 *         The same behaviour applies in North-South direction.
 * 
 * @param ant The ant instance in focus.
 */
<type> step_ant(<params>);

/**
 * Provides the postion of the ant in horizontal orientation.
 * 
 * @param ant The ant instance in focus.
 * @return The index of the column of the cell the ant 
 *         currently resides on, or 0 it the ant is not valid.
 */
<type> get_ant_x_pos(<params>);

/**
 * Provides the position of the ant in vertical orientation.
 * 
 * @param ant The ant instance in focus.
 * @return The index of the row of the cell the ant 
 *         currently resides on, or 0 it the ant is not valid.
 */
<type> get_ant_y_pos(<params>);

/**
 * Provides the current viewing direction of the ant.
 * 
 * @param ant The ant instance in focus.
 * @return The current viewing direction of the ant 
 *         or `NORTH`, if the ant is not valid.
 */
<type> get_ant_direction(<params>);
