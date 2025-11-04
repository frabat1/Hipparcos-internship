// In this code, I want to generate a program to play rock, paper and scissor against the computer.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// I want to implement two functions: main() and game(). 

// In game() I want to write the rules of the game, comprehending all the possible solution
void game(int user_choice, int pc_choice) {

    printf("The Computer chose %d.\n", pc_choice);

    if (user_choice == pc_choice) { 
        printf("It's a tie!");
    }
    else if (user_choice == 1 & pc_choice == 2) {
        printf("The Computer wins!");
    }
    else if (user_choice == 1 & pc_choice == 3) {
        printf("You win!");
    }
    else if (user_choice == 2 & pc_choice == 1) {
        printf("You win!");
    }
    else if (user_choice == 2 & pc_choice == 3) {
        printf("The Computer wins!");
    }
    else if (user_choice == 3 & pc_choice == 1) {
        printf("The Computer wins!");
    }
    else if (user_choice == 3 & pc_choice == 2) {
        printf("You win!");
    }
    else {
        printf("Invalid character, please select one between 1, 2 and 3.");
    }
}


// Now I need to generate a random number (each time different) to create the computer response
int random_number(int min, int max) {
    int num = rand() % (max - min + 1) + min;
    return num;
}



// main(): it consists of the declaration of variable, the input from the user and the random generation of a value from the computer
int main (void) {
    srand(time(NULL));

    printf("Welcome to the Rock/Paper/Scissor game.\n");

    char continue_game[4] = "yes";

    while (strcmp(continue_game, "yes") == 0) {
        printf("Please, select one of the three:\n"
            "Rock (1)\n"
            "Paper (2)\n"
            "Scissor (3)\n"
        );
        int user_choice;
        scanf("%d", &user_choice); //input from the user

        int pc_choice = random_number(1, 3); // the randomly generated value for the pc

        game(user_choice, pc_choice);

        printf("\nDo you want to play again? [yes/no]\n");
        if (scanf("%3s", continue_game) != 1) {
            break;
        }
    }
    return 0;
}