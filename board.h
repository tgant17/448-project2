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
        /*Pre: m_board is inititalized
        Post: print m_board
        Return: None
        */
        //return remainingShip
        int getShipNums();
        /*Pre: User choose number of ships
        Post:   get number of ships
        Return: m_shipNums
        */
        //print m_playerViewBoard
        void printPlayerViewBoard();
        /*Pre: m_playerViewBoard is initialized
        Post: print m_playerViewBoard
        Return: None
        */
        //return a character of a location on m_board
        string getLocation(int row, int col);
        /*Pre: row and col should be valid
        Post:   get string at a location on m_board
        Return: return m_board[row][col]
        */
        //return a location on m_playerViewBoard
        string getHistoryMove(int row, char col);
        /*Pre: row col should be valid
        Post: get string at a location on m_playerViewBoard
        Return: return m_playerViewBoard[row][col]
        */
        //set a character on a location on m_board
        void setLocation(int row, int col, string newChar);
        /*Pre: row col should be valid
        Post: change the string at a location on board
        Return: None
        */
        //convert character coordinate into an interger coordinate
        int convertCharToInt(char character);
        /*Pre: input should be char from A - I
        Post: change a char to an int
        Return: an integer
        */
        //return true if the coordinate of the ship is off the board
        bool isOffArray(int p, int shipStart, int shipEnd);
        /*Pre: user inputs the location of the ship
        Post: check if the input location is not on the board
        Return: true if the input is not on the board
        */
        //return true if size of the ship is within the range
        bool isValidSize(string shipType, int shipStart, int shipEnd);
        /*Pre: user inputs the location of the ship
        Post: check if size of the ship is valid
        Return: true if the size is correct
        */
        //return true if there is an occupied in a horizontal ship
        bool isOccupiedHorizontally(int p, int shipStart, int shipEnd);
        /*Pre: user inputs the location of the ship
        Post: check if any m_board location is different from "-" 
        Return: true when detecting a location different from "-"
        */
        //return true if there is an occupied in a vertical ship
        bool isOccupiedVertically(int p, int shipStart, int shipEnd);
        /*Pre: user inputs the location of the ship
        Post: check if any m_board location is different from "-"
        Return: true when detecing a location different from "-"
        */
        //return true if the ship is valid
        bool isValidShip(string shipType, int p, int shipStart, int shipEnd);
        /*Pre: user inputs location of the ship
        Post: call isOffArray and isValidSize
        Return: true if isOffArray and isValidSize returns true
        */
        //Place a horizontal ship on the board
        bool setShipHorizontally(string shipType, int row, char colStart, char colEnd);
        /*Pre: user inputs location and orientation of the ship
        Post: Place the ship in horizontal direction on the board
        Return: true if ship is set successfully
        */
        //Place a vertical ship on the board
        bool setShipVertically(string shipType, char col, int rowStart, int rowEnd);
        /*Pre: user inputs location and orientation of the ship
        Post: Place the ship in vertical direction on the board
        Return: true if ship is set successfully
        */
        //Place a Ship
        bool setShip(char orientation, string shipType, int rowStart, char colStart, int rowEnd, char colEnd);
        /*Pre: orientation, shipType, and location of the ship
        Post: call setShipHorizontally if orientation is 'h', call setShipVertically if orientation is 'v
        Return: true if ship is set successfully
        */
        void updateShip(string shipType);
        /*Pre: shipType
        Post: update the status of the ship if the ship get Hit
        Return: None
        */
        //return true if player hit another player's ship and update player's view board
        bool Hit(Board* otherPlayerBoard, int row, char col);
        /*Pre: opponent's board and location
        Post: call updateShip if opponent's ship get Hit
        Return: true if the location on otherPlayerBoard is not "-"
        */
        //return if remainingShip == 0
        bool isLost();
        /*Pre: User choose number of ships
        Post: check if remainingShip == 0
        Return: true if remainingShip == 0
        */

        ~Board();
        /*Pre: none
        Post: board destructor
        Return: none
        */

};
#endif
