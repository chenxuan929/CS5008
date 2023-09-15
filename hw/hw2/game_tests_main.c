/*  ========== H02 - Guessing Game ============
 *
 *   Student: UPDATE
 *   Semester: UPDATE
 *
 *   This file builds the foundation for a 'testing' framework for the game
 *   You will want to build unit tests in this file, and run them. 
 *   You have freedom to use this file as you need. It also provides
 *   an example of how to control the random seed.
 * 
 *   For reference, we are using a file similar to this for auto-grading. 
 */
#include <stdlib.h> 
#include <string.h>
#include <stdlib.h>
#include "guessing_game.h"  


/**
 * This function test the make_computer() fucntion - if computer's choice is in the resenable range between MAX and MIN.
 * Return 0 if the test passed successfully
 * Return 1 - if test failed
*/
int test_make_computer() {
    game tempGame = make_computer();
    if ((tempGame.computerChoice > MAX_RANDOM) ||tempGame.computerChoice <  MIN_RANDOM) {
        printf("Erroe: computer's choice is bigger or smaller than expected range.");
        return 1;
    }
    return 0; // if there weren't errors
}

/**
 * This function test the getplayer() function - if player's input stored correctly.
 * Return adjust = 0 if the test passed successfully
*/
int test_getplayer() {
    int adjust = 0;
    printf( "Guess a number (1 to 10): 10\n");
    int num1 = getplayer();
    if (num1 != 10) {
        adjust = 1;
    }

    printf( "Guess a number (1 to 10): 1\n");
    int num2 = getplayer();
    if (num2 != 1) {
        adjust = 1;
    }

    printf( "Guess a number (1 to 10): 5\n");
    int num3 = getplayer();
    if (num3 != 5) {
        adjust = 1;
    }
    return adjust;
}

/**
 * This function test startPlay() function - if player's guess times are in valid range.
 * guess times shoule be in range of 1 to 10 because game have 10 numbers in total.
 * Return 0 if the test passed successfully
*/
int test_startPlay(){
    int timesArray[5];
    startPlay(timesArray, getplayer);
    for (int i = 0; i < 5; i++) {
        if (timesArray[i] < 1 || timesArray[i] > MAX_RANDOM) {
            printf("Error: not in resonable range of guess times");
            return 1;
        }
    }
    return 0;
}

/**
 * This function tests the start_game function by calling it and checking its return value. 
 * Also checks that the values stored in the timesArray are within a reasonable range of guess times.
 * Return 0 if the test passed successfully
*/
int test_start_game() {
    //srand(time(NULL)); // seed the random number generator
    int timesArray[5];
    int result;
    result = start_game();
    if (result != 0) {
        printf("Error: start_game returned a non-zero value\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        if (timesArray[i] < 1 || timesArray[i] > MAX_RANDOM) {
            printf("Error: not in resonable range of guess times");
            return 1;
        }
    }
    return 0;
}
    
    



/** saves the random number seed out to a file,
 * so it can be regenerated for testing purposes.
 *
 * The way to save out the values would be
 * tester.out random 20 > rand_sequence.txt
 *
 * assuming tester is what you setup for your compile command of
 *  clang -Wall tests/game_tests_main.c -o tester.out
 */
void save_random(char *count_c) {
    char *end;
    long count = strtol(count_c, &end, 10);

    for(int i = 0; i < count; i++) {
       printf("%d\n", rand() % MAX_RANDOM + MIN_RANDOM);
    }

}

/* Program entry point*/
/* Options for running 

Run the unit tests: > game_tester.out  
Run the game with a set random seed: > game_tester.out play
Generate random numbers: > game_tester.out random ## 
(were ## is a number)

*/
int main(int argc, char *argv[]) {

    /**rand() generates psuedo random numbers
     * based on a seed. In production it is common
     * to use the system clock time as the seed as that
     * is always changing. however, for tests, you want
     * to fix the random numbers so you want to set the seed.
     * 
     * The problem is that different OS version + Hardware
     * still generate different random numbers even if the
     * seed is the same. A 'hacky' (but works) way to do it
     * is write a quick program that generates a series of random
     * numbers based on a specific seed. Then call your
     * other program using that specific seed. 
     * 
     * In order to conserve files, kept this as one program using
     * the program arguments to generate the random numbers. If no
     * 
    */

    srand(1); // to force the tests to have a set random number group
    if(argc > 1) {
        if(argc > 2) {
            save_random(argv[2]);
            return 1;
        }else { // assume play
            return start_game(); /* run the came for client based testing */
        }
    }else {
        int errors = 0;
        errors += test_make_computer();
        errors += test_getplayer() ; 
        //errors += test_startPlay();
        errors += test_start_game();

        if (errors == 0) {
            printf("Test seccessfully!");
        } else {
            printf("\n**Fail %d unit tests.**\n", errors);
        }
    }
    return 0;
}
