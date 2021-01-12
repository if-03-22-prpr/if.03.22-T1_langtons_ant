/**
* @mainpage
* @section intro Introduction
* The console version of 'Langton's Ant'.
*
* Langton's ant (beware: his ant, not his aunt!) lives in it's special universe.

* That universe is flat but endless - like the surface of a Doughnut - and consits
* of a number of discrete regions - the cells. Each cell shows one color from a range of colors.
* The color range is rather limited: it consists of WHITE and BLACK 
* (probably due to the limited vision of the ant).
*
* The ant is capable of recognizing the color of the cell it currently resides on and decides - based 
* on that color - whether it turns left or right before moving on. When the ant leaves a cell, 
* it changes the color of that cell. It is not known, if the ant is aware or surprised of the different
* color when it visits the cell again, most probably it does not even remember that it was already there.
* 
* **Background Info - Fun Facts**
*
* Christopher Langton invited this two-dimensional universal Turing machine in 1986 as an example
* for a self-contained, complete, deterministic system with simple rules and initial state, 
* which can get both,surprisingly 'chaotic' as well as surprisingly regular states. 
* The state of the universe (expressed as colors of its cells) for a given number of steps 
* cannot be calculated using a formula. Each step has to be performed to 
* determine the state of the universe after a number of steps.
* 
* @section objective Assignment Objective
* In this assignment the required Abstract Data Types and the (rather simple) render loop
* shall be implemented. A visualizer (renderer) is provided and shall be used.
* All unit tests provided for this assignment shall become 'green' and the application shall
* render the walk of the ant frame by frame.
* 
* **Configuration**
*
* Because we operate on static memory, the maximum size of the ant's world in each dimension 
* along with the number of steps to take can be configured in `config.h`.
* 
* **Setup and Execution**
*
* The world - there is exactly one world - is initialized with its dimensions, 
* which may be at maximum as large as the related `MAX_WORLD_SIZE` configuration. 
* Initially all cells have a `WHITE` color.
*
* The ant is initialized with it's starting position on the world and the initial viewing position.
*
* To run the application, the function `run_langtons_ant(...)` need to be implemented in `la_main_driver.c` 
* as follows:
*   -# initializes the ant's world 
*   -# initializes the ant 
*   -# renders the first frame via la_render_frame(...) function
*   -# makes the ant performing a step
*   -# renders the next frame in the same way as described above
*   -# continues at bullet 4) for the number of steps.
*
* As usually the tests can be compiled and performed via `make test` or `make cleartest`.
* The application can be compiled and run via `make` or `make clear`.
*
* **Rules**
*
* The ant steps on the surface of it's world in and endless manner. 
*
* This 'world' is represented by a two-dimensional array of colored cells.
* The endlessness of the surface is realized as follows:
*   - When the ant steps over the right border, it appears in the left-most cell of the same row.
*   - When the ant steps over the left border, it appears in the right-most cell of the same row.
*   - When the ant steps over the bottom border, it appears in the top-most cell of the same column. 
*   - When the ant steps over the top border, it appears in the bottom-most cell of the same column.
*
* For each step, the ant performs the following actions in the given order:
*  -# it determinats the color of the cell it currently sits on
*  -# it changes its direction depending on the cell-color
*     -# if the color is `WHITE`: the ant turns 90° clockwise (e.g from `NORTH` to `EAST` or from `SOUTH` to `WEST`)
*     -# if the color is `BLACK`: the ant turns 90° counter-clockwise (e.g from `SOUTH` to `EAST` or from `NORTH` to `WEST`)
*  -# it flips the color of the cell (from `WHITE` to `BLACK` and vice versa)
*  -# it jumps to the next cell according to the current direction. The position of the next cell is determined 
*     by `get_next_x_pos(...)` and `get_next_y_pos(...)` of `la_world.h`.
* 
* **Visualization**
*
* The world including the ant on it is rendered using function `la_render_frame(...)` provided by 
* `la_visualizer.h`. The world need to be rendered initially and after each step. The step number
* is printed as well.
*
* @section assignment Assignment
* To complete this assignment in a short time, it is vital, 
* to develop the code in a focused and clean way, step by step.
*
* Many unit tests are provided to ease development. If too many 
* failed unit tests appear - especially at the beginning of development- they 
* can be commented in file `la_test_driver.c` for files that are currently 
* not in focus. However, they need to be reactivated as development proceeds.
* 
* **Hint:**
* Read and obey the API docs of the types and functions as well as the comments within the code.
*
* -# Complete 
*   - include guards
*   - forward declarations, 
*   - types, 
*   - and function for ADTs in `general.h`, `la_ant.h`, `la_world.c`, and `la_main_driver.c`.
*   .
*   - Types in template files may be marked as `<type>` within header and source files 
*     or may be omitted completely. Replace `<type>` with the correct type 
*     and complete missing types. Some types, those which are shared among multiple sources, 
*     are located in `general.h`.
*   - Parameter lists of function in template files may be missing or incomplete.
* -# Make the program and tests compile: Implement all functions in all relevant files 
*    declared in the headers EMTPY (return nothing, 0, false, ... as required).
*   - All unit tests shall run but FAIL after this step
*   - **--COMMIT--**
* -# Implement the empty functions one by one to make the unit tests pass one by one.
*   - Proposed order: la_ant, la_world, la_main_driver.
*   - The purpose of a function is specified as API documentation within the header files.
*   - Obey comments in source files. Run the unit tests frequently and fix failures.
*   - **--COMMIT-- after each implemented function.**
* -# Implement the main render loop and other missing parts in `la_main_driver.c` function.
*   - **--COMMIT--**
* -# Let the ant begin its journey.
*
* @section notes Notes
* -# Visualization is implemented for Linux shell, it will not work on Windows.
* -# Sometimes changes are not properly detected by incremental builds. If something very strange 
*    happens during compilation, try to run `make clean` followed by `make` to start a clean build.
*    This approach is also recommended after everthing is done, because some compiler warning appears
*    only in clean builds. 
*/