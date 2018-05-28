#include <stdio.h> //import stdio.h
#include <stdbool.h> //import stdbool.h
#include <ctype.h> //import ctype.h
/*
 * Declare functions
 */
void printBoard(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3); //Declare printBoard() function
bool isCompleted(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3); //Declare isCompleted() function
void processCoordinates(int col, char row, char player); //Declare processCoordinate() function
char getWinner(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3); //Declare getWinner() function
void changePlayer(); //Declare changePlayer() function
bool exists(int position); //Declare exists() function
bool isTie(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3); //Declare isTie() function
void playAgain(char response); //Declare playAgain() function
void emptyBoard(); //Declare emptyBoard() function
/*
 * Declare global variables
 */
char Position[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; //Declare and initialize Position[] array
char currentPlayer = 'X'; //Declare and initialize currentPlayer char variable with default first player (X)
bool play = true; //Declare and initialize boolean play that determines if the user wants to play.
int xWins = 0; //Declare and initialize xWins
int oWins = 0; //Declare and initialize oWins
/*
 * Functions
 */
void main () {  //Main function start
    while(play) { //Checks if the user wants to play
        printf("  _______ _        _______           _______         "); //Prints tic tac toe banner
        printf("\n |__   __(_)      |__   __|         |__   __|        "); //Prints tic tac toe banner
        printf("\n    | |   _  ___     | | __ _  ___     | | ___   ___"); //Prints tic tac toe banner
        printf("\n    | |  | |/ __|    | |/ _` |/ __|    | |/ _ \\ / _ \\ "); //Prints tic tac toe banner
        printf("\n    | |  | | (__     | | (_| | (__     | | (_) |  __/"); //Prints tic tac toe banner
        printf("\n    |_|  |_|\\___|    |_|\\__,_|\\___|    |_|\\___/ \\___|"); //Prints tic tac toe banner
        printf("\n\n"); //Prints space
        printf("Player X Wins: %d\n", xWins); //Prints X wins
        printf("Player O Wins: %d\n", oWins); //Prints O wins
        printf("\n\n"); //Prints space
        while (isCompleted(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]) == false && isTie(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]) == false) { //Start the loop. While loop checks that the game is not over and that the board is not full
            int col; //Declare integer col (column)
            char row; //Declare character row
            printBoard(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]); //Prints the board with the current Position array
            printf("Player %c Enter Column: ", currentPlayer); //Prints instructions for player to enter column
            scanf("%d", &col); //Prompts for column
            printf("Player %c Enter Row: ", currentPlayer); //Prints instructions for player to enter row
            scanf(" %c", &row); //Prompts for row
            processCoordinates(col, tolower(row), currentPlayer); //Enters column, row, and player to processCoordinates to make sure the coordinates are valid, are not used, and updates the Position[] array
        } //End while loop
        printBoard(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]); //Prints the board after the game is finished
        if (isTie(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8])) { //isTie() checks if the game ended because of a tie or win
            printf("It's a tie!"); //Prints that the game is a tie
        } else { //The game is not a tie, but a win
            char winner = getWinner(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]); //Gets the winner of the game
            printf("Player %c Won! Rewards:\n+1 Gracious Professionalism\n+1 Coopertition\n-----------------------------------------------------------------\n ", winner); //Prints the winner and grants the winner +1 Gracious Professionalism and Coopertition
            if(winner == 'X') { //If the winner is X
                xWins++; //Add 1 point to X
            } else if(winner == 'O') { //Else if the winer is O
                oWins++; //Add 1 point to O
            } //End of if/else statement
        } //End of if/else statement
        char playres; //Declares character playres
        printf("Want to play again? (Y/N): "); //Prints the question to ask of the user wants to play again
        scanf(" %c", &playres); //Prompts for response
        playAgain(tolower(playres)); //Calls function playAgain() to determine if the user wants to play again
    } //End of while(play) loop
    printf("\n\n"); //Prints space
    printf("Player X Wins: %d\n", xWins); //Prints X wins
    printf("Player O Wins: %d\n\n", oWins); //Prints O wins
    if (xWins > oWins) { //If X has more wins than O
        printf("Player X wins with %d Gracious Professionalism and Coopertition points!", xWins); //Print that X won
    } else if (xWins < oWins) { //Else if O has more wins than X
        printf("Player O wins with %d Gracious Professionalism and Coopertition points!", oWins); //Print that O won
    } else if (xWins == oWins) { //Else if it is a tie
    printf("Player X and Player O tie with %d Gracious Professionalism and Coopertition points!", xWins); //Print that it is a tie
    } //End if/else statement
    printf("\n\nThanks for playing!\n"); //Thanks the user for playing with gracious professionalism
} //End main

void printBoard(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) {  //Start printBoard(). Prints the board with current Position[] array
    printf("\n\n   1   2   3\n"); //Prints column IDs
    printf("A: %c | %c | %c \n", a1, a2, a3); //Prints 1st row of board
    printf("  ------------\n"); //Prints horizontal line
    printf("B: %c | %c | %c \n", b1, b2, b3); //Prints 2nd row of board
    printf("  ------------\n"); //Prints horizontal line
    printf("C: %c | %c | %c \n\n\n", c1, c2, c3); //Prints 3rd row of board
} //End printBoard()

bool isCompleted(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) { //start isCompleted(). Checks of someone has won the game
    if (a1 == a2 && a1 == a3 && a1 != ' ') { //Checks if a1 is the same as a2 and a3, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else if (b1 == b2 && b1 == b3 && b1 != ' ') { //Checks if b1 is the same as b2 and b3, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else if (c1 == c2 && c1 == c3 && c1 != ' ') { //Checks if c1 is the same as c2 and c3, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else if (a1 == b1 && a1 == c1 && a1 != ' ') { //Checks if a1 is the same as b1 and c1, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else if (a2 == b2 && a2 == c2 && a2 != ' ') { //Checks if a2 is the same as b2 and c2, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else if (a3 == b3 && a3 == c3 && a3 != ' ') { //Checks if a3 is the same as b3 and c3, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else if (a1 == b2 && a1 == c3 && a1 != ' ') { //Checks if a1 is the same as b2 and c3, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else if (a3 == b2 && a3 == c1 && a3 != ' ') { //Checks if a3 is the same as b2 and c1, and are not empty for a win
        return true; //Returns isCompleted() as true
    } else { //There is no win
        return false; //Returns isCompleted() as false
    } //End if/else statement
} //End isCompleted()

void processCoordinates(int col, char row, char player) {  //Start processCoordinates(). Checks if coordinates are valid, not used, and updates the Position[] array from the user's input
    if (col == 1 && row == 'a') { //Checks if input coordinate was 1a1
        if (!exists(0)) { //Makes sure a1 is empty in Position[] array at index 0
            Position[0] = player; //Updates Position[] array at index 0 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 1 && row == 'b') { //Checks if input coordinate was b1
        if (!exists(3)) { //Makes sure b1 is empty in Position[] array at index 3
            Position[3] = player; //Updates Position[] array at index 3 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 1 && row == 'c') { //Checks if input coordinate was c1
        if (!exists(6)) { //Makes sure c1 is empty in Position[] array at index 6
            Position[6] = player; //Updates Position[] array at index 6 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 2 && row == 'a') { //Checks if input coordinate was a2
        if (!exists(1)) { //Makes sure a2 is empty in Position[] array at index 1
            Position[1] = player; //Updates Position[] array at index 1 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 2 && row == 'b') { //Checks if input coordinate was b2
        if (!exists(4)) { //Makes sure b2 is empty in Position[] array at index 4
            Position[4] = player; //Updates Position[] array at index 4 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 2 && row == 'c') { //Checks if input coordinate was c2
        if (!exists(7)) { //Makes sure c2 is empty in Position[] array at index 7
            Position[7] = player; //Updates Position[] array at index 7 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 3 && row == 'a') { //Checks if input coordinate was a3
        if (!exists(2)) { //Makes sure a3 is empty in Position[] array at index 2
            Position[2] = player; //Updates Position[] array at index 2 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 3 && row == 'b') { //Checks if input coordinate was b3
        if (!exists(5)) { //Makes sure b3 is empty in Position[] array at index 5
            Position[5] = player; //Updates Position[] array at index 5 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } else if (col == 3 && row == 'c') { //Checks if input coordinate was c3
        if (!exists(8)) { //Makes sure c3 is empty in Position[] array at index 8
            Position[8] = player; //Updates Position[] array at index 8 to the player that made the move
            changePlayer(); //Changes player to opposite player
        } //End if statement
    } //End if/else statement
} //End processCoordinates()

void changePlayer() { //Start changePlayer(). Changes currentPlayer to opposite player
    if(currentPlayer == 'X') { //Checks if the current set player is X
        currentPlayer = 'O'; //Changes currentPlayer to O
    } else if (currentPlayer == 'O') { //Checks if the current set player is O
        currentPlayer = 'X'; //Changes currentPlayer to X
    } //End if/else statement
} //End changePlayer()

char getWinner(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) { //Start getWinner(). Returns the winner of the game
    if (a1 == a2 && a1 == a3 && a1 != ' ') { //Checks if a1 is the same as a2 and a3, and are not empty to determine if it is the winning line
        return a1; //The winning player is in a1. Returns a1 to determine the winner
    } else if (b1 == b2 && b1 == b3 && b1 != ' ') { //Checks if b1 is the same as b2 and b3, and are not empty to determine if it is the winning line
        return b1; //The winning player is in b1. Returns b1 to determine the winner
    } else if (c1 == c2 && c1 == c3 && c1 != ' ') { //Checks if c1 is the same as c2 and c3, and are not empty to determine if it is the winning line
        return c1; //The winning player is in c1. Returns c1 to determine the winner
    } else if (a1 == b1 && a1 == c1 && a1 != ' ') { //Checks if a1 is the same as b1 and c1, and are not empty to determine if it is the winning line
        return a1; //The winning player is in a1. Returns a1 to determine the winner
    } else if (a2 == b2 && a2 == c2 && a2 != ' ') { //Checks if a2 is the same as b2 and c2, and are not empty to determine if it is the winning line
        return a2; //The winning player is in a2. Returns a2 to determine the winner
    } else if (a3 == b3 && a3 == c3 && a3 != ' ') { //Checks if a3 is the same as b3 and c3, and are not empty to determine if it is the winning line
        return a3; //The winning player is in a3. Returns a3 to determine the winner
    } else if (a1 == b2 && a1 == c3 && a1 != ' ') { //Checks if a1 is the same as b2 and c3, and are not empty to determine if it is the winning line
        return a1; //The winning player is in a1. Returns a1 to determine the winner
    } else if (a3 == b2 && a3 == c1 && a3 != ' ') { //Checks if a3 is the same as b2 and c1, and are not empty to determine if it is the winning line
        return a3; //The winning player is in a3. Returns a3 to determine the winner
    } //End if/else statement
} //End getWinner()

bool exists(int position) { //Start exists(). Checks if the position on the board is empty
    if (Position[position] != ' ') { //Checks if the value of the Position[] array at index inputted by the user is not equal to a space
        return true; //Returns true. The position is used
    } else { //The position is not used
        return false; //Returns false. The position is empty
    } //End if/else statement
} //End exists()

bool isTie(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) { //Start isTie(). Checks the game is a tie (the board is full with no winner)
    if(a1 != ' ' && a2 != ' ' && a3 != ' ' && b1 != ' ' && b2 != ' ' && b3 != ' ' && c1 != ' ' && c2 != ' ' && c3 != ' ') { //Checks that all spots in the board are not empty
        return true; //Returns true. All the spots are full
    } else { //Some spots are not filled
        return false; //Returns false. Not all the spots are filled in
    } //End if/else statement
} //End isTie()

void playAgain(char response) { //Start playAgain. Checks if the user wants to play again, and resets the game if so.
    if (response == 'y') { //If the user says yes
        emptyBoard(); //Calls emptyBoard() function to clear board
    } else { //If the user does not say yes
        play = false; //Sets play to false, meaning the game is over
    } //End if/else statement
} //End playAgain()

void emptyBoard() { //Start emptyBoard(). Clears the board and resets default player.
    Position[0] = ' '; //Sets the Position[] value to ' ' (space) at index 0
    Position[1] = ' '; //Sets the Position[] value to ' ' (space) at index 1
    Position[2] = ' '; //Sets the Position[] value to ' ' (space) at index 2
    Position[3] = ' '; //Sets the Position[] value to ' ' (space) at index 3
    Position[4] = ' '; //Sets the Position[] value to ' ' (space) at index 4
    Position[5] = ' '; //Sets the Position[] value to ' ' (space) at index 5
    Position[6] = ' '; //Sets the Position[] value to ' ' (space) at index 6
    Position[7] = ' '; //Sets the Position[] value to ' ' (space) at index 7
    Position[8] = ' '; //Sets the Position[] value to ' ' (space) at index 8
    currentPlayer = 'X'; //Sets the currentPlayer to X
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); //Gives the effect of clearing the board by printing empty lines
} //End emptyBoard();
