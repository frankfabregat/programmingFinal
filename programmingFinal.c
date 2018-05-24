#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
/*
 * Declare functions
 */
void printBoard(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3);// declare printBoard function
bool isCompleted(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3); // declare isCompleted function
void processCoordinates(int col, char row, char player); // declare processCoordinate function
char getWinner(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3); // declare getWinner function
void changePlayer(); // declare changePlayer function
bool exists(int position); // declare exists function
bool isTie(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3); // declare isTie function
/*
 * Declare global variables
 */
char Position[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; // declare and initialize Position array
char currentPlayer = 'X'; // declare and initialize currentPlayer with default first player
void main () { //Main function
    while (isCompleted(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]) == false && isTie(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]) == false) {
int col;
char row;
printBoard(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]);
printf("Player %c Enter Column: ", currentPlayer);
scanf("%d", &col);
printf("Player %c Enter Row: ", currentPlayer);
scanf(" %c", &row);
processCoordinates(col, tolower(row), currentPlayer);
    }
    printBoard(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]);
if (isTie(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8])) {
    printf("It's a tie!");
} else {
char winner = getWinner(Position[0], Position[1], Position[2], Position[3], Position[4], Position[5], Position[6], Position[7], Position[8]);
printf("Player %c Won! Rewards:\n+1 Gracious Professionalism\n+1 Coopertition\n-----------------------------------------------------------------\n ", winner);
}
}
void printBoard(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) {
printf("\n   1   2   3\n");
printf("A: %c | %c | %c \n", a1, a2, a3);
printf("  ------------\n");
printf("B: %c | %c | %c \n", b1, b2, b3);
printf("  ------------\n");
printf("C: %c | %c | %c \n\n\n", c1, c2, c3);
}
bool isCompleted(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) {
if (a1 == a2 && a1 == a3 && a1 != ' ') {
    return true;
} else if (b1 == b2 && b1 == b3 && b1 != ' ') {
    return true;
} else if (c1 == c2 && c1 == c3 && c1 != ' ') {
    return true;
} else if (a1 == b1 && a1 == c1 && a1 != ' ') {
    return true;
} else if (a2 == b2 && a2 == c2 && a2 != ' ') {
    return true;
} else if (a3 == b3 && a3 == c3 && a3 != ' ') {
    return true;
} else if (a1 == b2 && a1 == c3 && a1 != ' ') {
    return true;
} else if (a3 == b2 && a3 == c1 && a3 != ' ') {
    return true;
} else {
return false;
}
}
void processCoordinates(int col, char row, char player) {
if (col == 1 && row == 'a') { //0
        if (!exists(0)) {
    Position[0] = player;
    changePlayer();
        }
} else if (col == 1 && row == 'b') { //3
    if (!exists(3)) {
  Position[3] = player;
  changePlayer();
    }
} else if (col == 1 && row == 'c') { //6
    if (!exists(6)) {
    Position[6] = player;
    changePlayer();
    }
} else if (col == 2 && row == 'a') { //1
    if (!exists(1)) {
    Position[1] = player;
    changePlayer();
    }
} else if (col == 2 && row == 'b') { //4
    if (!exists(4)) {
    Position[4] = player;
    changePlayer();
    }
} else if (col == 2 && row == 'c') { //7
    if (!exists(7)) {
    Position[7] = player;
    changePlayer();
    }
} else if (col == 3 && row == 'a') { //2
    if (!exists(2)) {
    Position[2] = player;
    changePlayer();
    }
} else if (col == 3 && row == 'b') { //5
    if (!exists(5)) {
    Position[5] = player;
    changePlayer();
    }
} else if (col == 3 && row == 'c') { //8
    if (!exists(8)) {
    Position[8] = player;
    changePlayer();
    }
} else { //none
}
}
void changePlayer() {
if(currentPlayer == 'X') {
    currentPlayer = 'O';
} else if (currentPlayer == 'O') {
    currentPlayer = 'X';
}
}
char getWinner(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) {
if (a1 == a2 && a1 == a3 && a1 != ' ') {
    return a1;
} else if (b1 == b2 && b1 == b3 && b1 != ' ') {
    return b1;
} else if (c1 == c2 && c1 == c3 && c1 != ' ') {
    return c1;
} else if (a1 == b1 && a1 == c1 && a1 != ' ') {
    return a1;
} else if (a2 == b2 && a2 == c2 && a2 != ' ') {
    return a2;
} else if (a3 == b3 && a3 == c3 && a3 != ' ') {
    return a3;
} else if (a1 == b2 && a1 == c3 && a1 != ' ') {
    return a1;
} else if (a3 == b2 && a3 == c1 && a3 != ' ') {
    return a3;
}
}
bool exists(int position) {
if (Position[position] != ' ') {
    return true;
} else {
return false;
}
}
bool isTie(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3) {
if(a1 != ' ' && a2 != ' ' && a3 != ' ' && b1 != ' ' && b2 != ' ' && b3 != ' ' && c1 != ' ' && c2 != ' ' && c3 != ' ') {
    return true;
} else {
return false;
}
}
