
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
        bool isOffArray(int row, int shipStart, int shipEnd);

        //return true if size of the ship is within the range
        bool isValidSize(int shipStart, int shipEnd);

        //return true if a tile of the board is occupied by another ship, prevent the ships from overlapping each other
        bool isOccupied(int row, int shipStart, int shipEnd);

        //return true if the ship is valid
        bool isValidShip(int row, int shipStart, int shipEnd);

        //Place a ship on the board
        void setShip(int row, char colStart, char colEnd);

        //return true if player hit another player's ship
        bool Hit(char **board, int row, char col);
        
        ~Board();
};
#endif