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

#include "la_visualizer.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "config.h"
#include "la_world.h"
#include "la_ant.h"

/* The grid separation symbols */
#define SEP    '|'
#define CROSS  '+'
#define LINE   '-'
#define BORDER '='

/* The encapsulated visualizer data */
struct VisData {
    bool disabled;
    int refresh_line_count;
    int left_margin;
    int offset;
    int width;
};

/* The visualizer instance */
static struct VisData vis_data = {false, 0, 4, 0, 0};

/* sets the cursor TO given position in the same line */
static void set_cursor_hor(int pos) {
    printf("\033[%dG", pos);
}

/* Provides the number output lines for a configured game. */ 
static void print_new_line() {
    vis_data.refresh_line_count++;
    printf("\n\033[2K");                             /* next line */
}

/* Starts a new line */
static void start_line(int offset) {
    printf("\033[2K");                                 /* clear current line */
    printf("\033[%dG", vis_data.left_margin + offset); /* set cursor to end of offset */
}

static void print_terminated_new_line(char terminator) {
        set_cursor_hor(vis_data.left_margin + vis_data.offset + vis_data.width -1);
        printf("%c", SEP);
        print_new_line();
}

/* Prints the given amount of the given sign. */
static void print_sign(char sign, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", sign);
    }
}

/* Prints a full-width terminated bar of the given sign. */
static void print_terminated_bar_line(char left, char sign, char right, int offset) {
    start_line(offset);
    int w = vis_data.width - (left != '\0' ? 1 : 0) - (right != '\0' ? 1 : 0);
    printf("%c", left);
    print_sign(sign, w);
    printf("%c", right);
    print_new_line();
}

/* Prints the line of text */
static void print_text_line(char* text, int offset) {
    start_line(offset);
    printf("%s", text);
    print_new_line();
}

/* Prints the given text centered between the border characters. */
static void print_centered(char* left_border, char* text, char* right_border, int offset) {
    start_line(offset);
    int gap = (vis_data.width - strnlen(text, 128)) / 2;
    if (left_border != 0) {
        printf("%s", left_border);
    }
    int marg = gap - strnlen(left_border, 128);
    if (marg > 0) { print_sign(' ', marg); }
    if (text != 0) {
        printf("%s", text);
    }
    marg = vis_data.width - gap - strnlen(text, 128) - strnlen(right_border, 128);
    if (marg > 0) { print_sign(' ', marg); }
    if (right_border != 0) {
        printf("%s", right_border);
    }
    print_new_line();
}

/* Provides the code to clear applied colors. */
static char* get_clear_color() {
    return "\033[0m";
}

/* Provides the color string for a color code */
static char* get_color_string(Color color) {
    char* white    = "\033[1;31;47m";
    char* black    = "\033[1;31;40m";
    return (color == WHITE ? white : black);
}

/* Prints a the given cell. */
static void print_cell(World world, Ant ant, Coord x, Coord y) {
    char ant_symbol = ' ';
    if (get_ant_x_pos(ant) == x && get_ant_y_pos(ant) == y) {
        switch (get_ant_direction(ant)) {
            case NORTH:
                ant_symbol = '^';    
                break;
            case EAST:
                ant_symbol = '>';    
                break;
            case SOUTH:
                ant_symbol = 'v';    
                break;
            case WEST:
                ant_symbol = '<';    
                break;
        }
    }
    Color color = get_cell_color(world, x, y);
    char* color_str = get_color_string(color);
    printf("%s%c", color_str, ant_symbol);
}

/* Prepares the frame to print */
static void prepare_frame(World world) {
    printf("\033[%dA", vis_data.refresh_line_count); /* move cursor to the first line of the game output */
    vis_data.refresh_line_count = 0;
    vis_data.width = (is_world_valid(world)
        ? get_world_width(world) + 2 
        : 0);
    print_new_line();
    print_new_line();
}

/* Prints the header */
static void print_header(World world, Ant ant) {
    if(!(is_ant_valid(ant) && is_world_valid(world))) {
        print_text_line("=============================================", vis_data.offset);
        print_text_line("==---     Langton's ant is not VALID    ---==", vis_data.offset);
        print_text_line("=============================================", vis_data.offset);
    } else {
        print_centered("|", "Langton's ant", "|", vis_data.offset);
    }
}

/* Prints the board */
static void print_world(World world, Ant ant) {
    if(is_ant_valid(ant) && is_world_valid(world)) {
        print_terminated_bar_line(CROSS, LINE, CROSS, vis_data.offset);
        for (Coord y = 0; y < get_world_height(world); y++) {
            start_line(vis_data.offset);
            printf("%c", SEP);
            for (Coord x = 0; x < get_world_width(world); x++) {
                print_cell(world, ant, x, y);
            }
            printf("%s", get_clear_color());
            print_terminated_new_line(SEP);
        }
        print_terminated_bar_line(CROSS, LINE, CROSS, vis_data.offset);
    }
}

/* Prints the status bar of the game */
static void print_status_bar(World world, Ant ant, int step) {
    if(is_ant_valid(ant) && is_world_valid(world)) {
        start_line(vis_data.offset);
        printf("%c %d x %d", SEP, get_world_width(world), get_world_height(world));
        print_terminated_new_line(SEP);
        start_line(vis_data.offset);
        printf("%c %4d steps", SEP, step);
        print_terminated_new_line(SEP);
    }
}


void la_disable_visualizer(bool disable) {
    vis_data.disabled = disable;
}

void la_render_frame(World world, Ant ant, int step) {
    if (!vis_data.disabled) {
        prepare_frame(world);
        print_terminated_bar_line(CROSS, BORDER, CROSS, vis_data.offset);
        print_header(world, ant);
        print_world(world, ant);
        print_status_bar(world, ant, step);
        print_terminated_bar_line(CROSS, BORDER, CROSS, vis_data.offset);
        if (FRAME_TIME > 0) {
            usleep(FRAME_TIME * 100 * 1000);
        } else {
            usleep(15 * 1000);
        }
    }
}
