/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Exercise Number: n/a
 * Title:			general.h
 * Author:			P. Bauer, S. Schraml
 * ----------------------------------------------------------
 * Description:
 * General usable definitions and types.
 * ----------------------------------------------------------
 */
#ifndef ___GENERAL_H
#define ___GENERAL_H

/** The unsigned integer type for sizes of dimensions. */
typedef unsigned short Size;

/** The unsigned integer type for position coordinates on a grid. */
typedef Size Coord;

/** The cardinal directions used for orientation within the universe. */
!! Declare an enumeration named 'Direction' containing items NORTH, EAST, SOUTH, WEST

/** Convenience macro do get maximum of two numbers */
#define MAX(x, y) ((x) > (y) ? (x) : (y))
/** Convenience macro do get maximum of two numbers */
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#endif
