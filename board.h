// Set t
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>

using namespace std;

class Board {
    private:
        char **m_board;

    public:
        Board();

        //print the board
        void printBoard();

        //convert character coordinate into an interger coordinate
        int convertCharToInt(char character);

        //return true if the coordinate of the ship is off the board
        bool isOffArray(int p, int shipStart, int shipEnd);

        //return true if size of the ship is within the range
        bool isValidSize(int shipStart, int shipEnd);

        //return true if there is an occupied in a horizontal ship
        bool isOccupiedHorizontally(int p, int shipStart, int shipEnd);

        //return true if there is an occupied in a vertical ship
        bool isOccupiedVertically(int p, int shipStart, int shipEnd);

        //return true if the ship is valid
        bool isValidShip(int p, int shipStart, int shipEnd);

        //Place a horizontal ship on the board
        bool setShipHorizontally(int row, char colStart, char colEnd);

        //Place a vertical ship on the board
        bool setShipVertically(char col, int rowStart, int rowEnd);

        //return true if player hit another player's ship
        bool Hit(char **board, int row, char col);

        ~Board();
};
#endif