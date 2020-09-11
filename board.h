// Set t
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include "Battleship.h"

using namespace std;

class Board {
    private:
        //board to place ships
        string **m_board;
        //board to keep track player's moves
        string **m_playerViewBoard;
        Battleship* ships;
        int m_shipNums;

    public:
        Board(int shipNums);

        //print m_board
        void printBoard();

        //print m_playerViewBoard
        void printPlayerViewBoard();

        //return a character of a location on m_board
        string getLocation(int row, int col);

        //set a character on a location on m_board
        void setLocation(int row, int col, string newChar);

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

        //Place a Ship
        bool setShip(char orientation, int rowStart, char colStart, int rowEnd, char colEnd);

        //return true if player hit another player's ship and update player's view board
        bool Hit(Board otherPlayerBoard, int row, char col);

        ~Board();
};
#endif