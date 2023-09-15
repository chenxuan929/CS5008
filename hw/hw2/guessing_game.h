/*  ========== H02 - Guessing Game ============
 *
 *   Student: Chenxuan Xu
 *   Semester: 2023 Spring
 *
 * A simple guessing game program. 
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H

#define MAX_RANDOM 10
#define MIN_RANDOM 1

/** add as many functions as you need 
 * remember good design practices 
*/

typedef struct guess_game{
    int computerChoice; // variable to store computer's randomly generated number
    int guesstimes; // variable to store the number of guesses it too the player to guess the correct number
}game;

/**
 * This function creates an instance of the game struct, sets the number of the guesses to 0, and generates a random number between MIN and MAX for the computer' choice.
 * @return tempGame - an instance of the game stuct with the computers choice and the number of guesses set to 0
*/
game make_computer(){
    game tempGame;
    tempGame.guesstimes = 0;
    tempGame.computerChoice = rand() % MAX_RANDOM + MIN_RANDOM;
    return tempGame;
}
/**
 * This function takes input from the player and returns it.
 * @return playerInput - the numern entered by the player
*/
int getplayer(){
    int playerInput;
    //printf( "Guess a number (1 to 10): ");
    scanf( "%d", &playerInput);
    return playerInput;
}

/**
 * This function plays the guessing game, takes in an array of integers to store the number of guess for each round and a function pointer to get the player's input.
 * It plays the game 5 times and save the number of guesses for each round in the timesArray.
 * @param timesArray - an array of integers to store the number of guesses for each round
 * @param getplayer - a function pointer to get the player's input
 * @return 0 - if the game ran validly
*/
int startPlay(int *timesArray, int (*getplayer)()){
    game tempGame;
    int i;
    int playerInput;

    for (int i = 0; i < 5; i++ ){
        printf("|                     Round %d                      |\n", i + 1);
        printf("====================================================\n");

        tempGame = make_computer();
        while(1){
            printf( "Guess a number (1 to 10): \n");
            playerInput = getplayer();

            if (playerInput > tempGame.computerChoice) {
                printf("Your guess is too high.\n");
                tempGame.guesstimes ++;
            }
            else if (playerInput < tempGame.computerChoice) {
                printf("Your guess is too low. \n");
                tempGame.guesstimes ++;
            }
            else
            {
                printf("Congratulations, you found it! \n");
                tempGame.guesstimes ++;
                timesArray[i] = tempGame.guesstimes;
                break;
            }
        }
    }
    return 0;
}

/** This is the start location for the guessing game, it calls the startPlay function and prints the number of guesses for each round.
 * remain the starting point. DO NOT reset the random seed.
 * @return 0 - if the game ran validly
 */

int start_game(){
    int timesArray[5];
    //int getplayer = getlayer();
    startPlay(timesArray, getplayer);
    
    printf("Round 1 took you %d guesses.\n", timesArray[0]);
    printf("Round 2 took you %d guesses.\n", timesArray[1]);
    printf("Round 3 took you %d guesses.\n", timesArray[2]);
    printf("Round 4 took you %d guesses.\n", timesArray[3]);
    printf("Round 5 took you %d guesses.\n", timesArray[4]);

    return 0; // returns 0 if game ran validly
}

#endif
