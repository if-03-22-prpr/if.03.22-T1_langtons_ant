/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant
 * Author:			*/<your name>/*
 * ----------------------------------------------------------
 * Description:
 * The declaration of an Abstract Data Type representing
 * the universe for the ant of Christopher Langton.
 * ----------------------------------------------------------
 */

/* note: common data types are declared in general.h */

/** Declares the type for the ant's universe, named 'World' */

/** The possible colors of a cell: WHITE, BLACK. */


/**
 * Initializes the ant's universe by colering all cells ´WHITE´.
 * The size of the world is determined by given attributes, which
 * may not exceed ´WORLD_SIZE´ for each dimension.
 * 
 * @param width The number of cells in horizontal direction, is clipped to ´MAX_WORLD_SIZE´.
 * @param height The number of cells in vertical direction, is clipped to ´MAX_WORLD_SIZE´.
 * @return The initialized world.
 */
<type> init_world(Size width, Size height);

/**
 * Provides the instance of the world.
 * Exactly one instance is supported. 
 * The state of the world is not affected by this function.
 * 
 * @return The world instance.
 */
<type> get_world();

/**
 * Determines whether or not the given world is valid.
 * The world is NOT valid
 *      + if it is 0,
 *      + or if it has a size of zero or larger than ´WORLD_SIZE´ in any dimension.
 * 
 * @param world The world instance in focus.
 * @return True if the given world is valid, false otherwise.
 */
<type> is_world_valid(<params>);

/**
 * Provides the number of cells of the ant's universe in horizontal direction.
 * 
 * @param world The world instance in focus.
 * @return The width of the reachable universe or 0 for invalid attributes.
 */
<type> get_world_width(<params>);

/**
 * Provides the number of cells of the ant's universe in vertical direction.
 * 
 * @param world The world instance in focus.
 * @return The height of the reachable universe or 0 for invalid attributes.
 */
<type> get_world_height(<params>);

/**
 * Provides the color of the addressed cell.
 * 
 * @param world The world instance in focus.
 * @param x The index of the column of the cell for which the color is requested.
 * @param y The index of the row of the cell for which the color is requested.
 * @return The color of the addressed cell or `WHITE` in case of invalid attributes.
 */
<type> get_cell_color(<params>);

/**
 * Changes the color of the addressed cell in cyclic order of color definition.
 * (it changes ´WHITE´ to ´BLACK´ and vice versa). 
 * Invocations with invalid attributes are ignored.
 * 
 * @param world The world instance in focus.
 * @param x The index of the column of the cell for which the color is flipped.
 * @param y The index of the row of the cell for which the color is flipped.
 */
<type> flip_cell_color(<params>);

/**
 * Provides the next position in horizontal orientation in the given direction
 * relative to the given position.
 * The universe is endless: 
 *     If the index of the next column 'beyond' the right border is '0' 
 *     while the index of the next column 'left' to 0 is ´width - 1´.
 * 
 * @param world The world instance in focus.
 * @param x The index of the column from which the next column index is calculated.
 * @param direction The direction of the next column.
 * @return The index if the next column or the given ´x´ for invalid attributes.
 */
<type> get_next_x_pos(<params>);

/**
 * Provides the index of the next position in vertical orientation in the given direction
 * relative to the given position.
 * The universe is endless: 
 *     If the index of the next row 'below' the bottom border is '0' 
 *     while the index of the next row 'above' 0 is ´height - 1´.
 * 
 * @param world The world instance in focus.
 * @param y The index of the row from which the next row index is calculated.
 * @param direction The direction of the next row.
 * @return The index if the next row or the given ´y´ for invalid attributes.
 */
<type> get_next_y_pos(<params>);

