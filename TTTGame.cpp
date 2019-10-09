/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    //create object
    TicTacToe TTT;
    //generate a random number seed with ctime
    srand(time(0));
    //declare variables
    int row;
    int column;
    int currentPlayerNum = (rand() % 2 + 1); //initialize the current player number



    //check whether it is a one or two player game
    int numOfPlayer;
    cout << "One-player or Two-player: ";
    cin >> numOfPlayer;


    TTT.initializeBoard(); //initialize board
    TTT.printBoard(); //print board
    if(numOfPlayer == 2) {
        //check whether the board is full
        while (TTT.isBoardFull() == false) {

            //choose whether player 1 or player 2 go first
            if (currentPlayerNum == 1) {
                cout << "Player 1: " << endl;
                cout << "Please enter the row and column you want to place your mark: ";
                cin >> row >> column;

                //place mark
                while (TTT.placeMark(row-1, column-1) == false) {
                    cout << "The location chosen is out of bound or already occupied , please choose another position: ";
                    cin >> row >> column;
                }
                TTT.printBoard();
                if (TTT.checkForWin() == true) {
                    cout << "We got the winner";
                    return 0; //end the program if somebody wins
                } else {
                    TTT.changePlayer();
                    currentPlayerNum = 2;
                }
            }
            else {
                cout << "Player 2: " << endl;
                cout << "Please enter the row and column you want to place your mark: ";
                cin >> row >> column;

                //place mark
                while (TTT.placeMark(row-1, column-1) == false) {
                    cout << "The location chosen is out of bound or already occupied , please choose another position: ";
                    cin >> row >> column;
                }
                TTT.printBoard();

                if (TTT.checkForWin() == true) {
                    cout << "We got the winner";
                    return 0; //end the program if somebody wins
                } else {
                    TTT.changePlayer();
                    currentPlayerNum = 1;
                }
            }
        }
        cout << "It is a tie" << endl; //if the board is full, it means that it is a tie game
    }

    else{
        while (TTT.isBoardFull() == false) {

            //choose whether player 1 or the computer go first
            if (currentPlayerNum == 1) {
                cout << "Player 1: " << endl;
                cout << "Please enter the row and column you want to place your mark: ";
                cin >> row >> column;

                //place mark
                while (TTT.placeMark(row-1, column-1) == false) {
                    cout << "The location chosen is out of bound or already occupied , please choose another position: ";
                    cin >> row >> column;
                }
                TTT.printBoard();
                if (TTT.checkForWin() == true) {
                    cout << "We got the winner";
                    return 0; //end the program if somebody wins
                } else {
                    TTT.changePlayer();
                    currentPlayerNum = 2;
                }
            }
            else {
                cout << "Computer: " << endl;
                //set random numbers for the computer to enter
                row = rand() % 3;
                column = rand() % 3;


                //place mark
                while (TTT.placeMark(row-1, column-1) == false) {
                    cout << "The location chosen is already occupied , please choose another position: ";
                    row = rand() % 3;
                    column = rand() % 3;
                }
                TTT.printBoard();
                if (TTT.checkForWin() == true) { //FIXME
                    cout << "We got the winner";
                    return 0; //end the program if somebody wins
                } else {
                    TTT.changePlayer();
                    currentPlayerNum = 1;
                }
            }
        }
        cout << "It is a tie" << endl; //if the board is full, it means that it is a tie game
        }

    return 0;
}