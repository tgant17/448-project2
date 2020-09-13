/* -----------------------------------------------------------------------------
 *
 * File Name:  board.h
 * Author: Thang Minh Le
 * Assignment:   EECS-448 Project 1
 * Description:  Header file for the board class
 * Date: 9-13-2020
 *
 ---------------------------------------------------------------------------- */

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
        Battleship** ships;
        int remainingShip;
        int m_shipNums;
    public:

        Board(int shipNums);
        /*Pre: none
        Post: board constructor
        Return: none
        */
        //print m_board
        void printBoard();
        /*Pre:
        Post:
        Return:
        */
        //return remainingShip
        int getShipNums();
        /*Pre:
        Post:
        Return:
        */
        //print m_playerViewBoard
        void printPlayerViewBoard();
        /*Pre:
        Post:
        Return:
        */
        //return a character of a location on m_board
        string getLocation(int row, int col);
        /*Pre:
        Post:
        Return:
        */
        //return a location on m_playerViewBoard
        string getHistoryMove(int row, char col);
        /*Pre:
        Post:
        Return:
        */
        //set a character on a location on m_board
        void setLocation(int row, int col, string newChar);
        /*Pre:
        Post:
        Return:
        */
        //convert character coordinate into an interger coordinate
        int convertCharToInt(char character);
        /*Pre:
        Post:
        Return:
        */
        //return true if the coordinate of the ship is off the board
        bool isOffArray(int p, int shipStart, int shipEnd);
        /*Pre:
        Post:
        Return:
        */
        //return true if size of the ship is within the range
        bool isValidSize(string shipType, int shipStart, int shipEnd);
        /*Pre:
        Post:
        Return:
        */
        //return true if there is an occupied in a horizontal ship
        bool isOccupiedHorizontally(int p, int shipStart, int shipEnd);
        /*Pre:
        Post:
        Return:
        */
        //return true if there is an occupied in a vertical ship
        bool isOccupiedVertically(int p, int shipStart, int shipEnd);
        /*Pre:
        Post:
        Return:
        */
        //return true if the ship is valid
        bool isValidShip(string shipType, int p, int shipStart, int shipEnd);
        /*Pre:
        Post:
        Return:
        */
        //Place a horizontal ship on the board
        bool setShipHorizontally(string shipType, int row, char colStart, char colEnd);
        /*Pre:
        Post:
        Return:
        */
        //Place a vertical ship on the board
        bool setShipVertically(string shipType, char col, int rowStart, int rowEnd);
        /*Pre:
        Post:
        Return:
        */
        //Place a Ship
        bool setShip(char orientation, string shipType, int rowStart, char colStart, int rowEnd, char colEnd);
        /*Pre:
        Post:
        Return:
        */
        void updateShip(string shipType);
        /*Pre:
        Post:
        Return:
        */
        //return true if player hit another player's ship and update player's view board
        bool Hit(Board* otherPlayerBoard, int row, char col);
        /*Pre:
        Post:
        Return:
        */
        //return if remainingShip == 0
        bool isLost();
        /*Pre:
        Post:
        Return:
        */

        ~Board();
        /*Pre: none
        Post: board destructor
        Return: none
        */

};
#endif
