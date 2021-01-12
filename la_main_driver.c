/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant
 * Author:			*/<your name>/*
 * ----------------------------------------------------------
 * Description:
 * The Langton's Ant Application.
 * ----------------------------------------------------------
 */


#include <stdio.h>
#include <string.h>
#include "config.h"

/* missing includes go here */
/* note: common data types are declared in general.h */

#include "la_visualizer.h"

/** 
 * Executes 'Langton's ant' on a universe of the given size for the given number of steps.
 * 1) initializes the ant's world
 * 2) initializes the ant: placed in the center (w/2, h/2), looking south
 * 3) renders the first frame via la_render_frame(...) function
 * 4) makes the ant performing a step
 * 5) renders the next frame in the same way as described above
 * 6) continues at bullet 4) for the number of steps.
 * 
 * @param width The width of the ant's world
 * @param height The height of the ant's world
 * @param steps The number steps to execute.
 */
void run_langtons_ant(Size width, Size height, int steps)
{
	/* initialization */

	/* main render loop */
	
}


/* Main function evaluates the number of command line arguments.
 * If the user passed one main switches into test mode, i.e., that
 * the function test_branch() is called and the command line argument
 * is handed over to this function. If no command line argument is given
 * main switches into user interface mode and delegates the handling
 * of this to the function ui_branch().
 * @see test_branch, ui_branch.
 */
int main(int argc, char *argv[])
{
	/* NOTE: Don't change this function, required for auto. testing */
	/* Implement ´run_langtons_ant(...)´ instead */
	int tmp_value = 0;
	bool disable_rendering = false;
	Size width = MAX_WORLD_SIZE / 2;
	Size height = MAX_WORLD_SIZE / 2;
	int steps = STEP_COUNT;
	if (argc > 1) {
		sscanf(argv[1], "%d", &tmp_value);
		width = tmp_value;
	}
	if (argc > 2) {
		sscanf(argv[2], "%d", &tmp_value);
		height = tmp_value;
	}
	if (argc > 3) {
		sscanf(argv[3], "%d", &tmp_value);
		steps = tmp_value;
	}
	if (argc > 4) {
		sscanf(argv[4], "%d", &tmp_value);
		disable_rendering = (tmp_value != 0);
	}
	la_disable_visualizer(disable_rendering);
	run_langtons_ant(width, height, steps);
	if (disable_rendering) {
		la_disable_visualizer(false);
		la_render_frame(get_world(), get_ant(), steps);
	}
	return 0;
}