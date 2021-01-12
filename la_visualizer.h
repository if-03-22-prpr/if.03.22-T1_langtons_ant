/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: n/a
 * ---------------------------------------------------------
 * Exercise Number: T1
 * Title:			Langton's Ant Visualizer
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Visualizes a single frame of Langton's Ant on its world.
 * ----------------------------------------------------------
 */
#ifndef ___LA_VISUALIZER_H
#define ___LA_VISUALIZER_H

#include <stdbool.h>

#include "la_world.h"
#include "la_ant.h"

/**
 * Specifies whether or not visualization is enabled.
 * With enabled visualization, the frames are shown on
 * standard output. Disabled visualization does 
 * neither print the board nor does it add a delay. 
 * 
 * Default value is enabled. This feature is intended for 
 * automatic testing.
 * 
 * @param disable True to disable, false to enable the visualizer.
 */
void la_disable_visualizer(bool disable);

/**
 * Prints the current state of the ant and it's universe.
 * The configured delay is added to rendering to support
 * continuous rendering in a simple loop.
 * 
 * @param world The ant's universe.
 * @param ant The ant.
 * @param step The number of the current step.
 */
void la_render_frame(World world, Ant ant, int step);

#endif