/*  ========== H02 - Guessing Game ============
 *
 *   Student: SOLUTION
 *   Semester:
 *
 *   A simple guessing game program. This
 *   Uses a separate main file where system
 *   specific stuff is set, like the random seed. 
 *
 */

#include <stdlib.h> 
#include <time.h>
#include "guessing_game.h"




/* Program entry point*/
int main() {
    srand(time(NULL)); // to make the game random, purposely set here only! 
    return start_game();
}
