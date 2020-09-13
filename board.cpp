/* -----------------------------------------------------------------------------
 *
 * File Name:  board.cpp
 * Author: Thang Minh Le
 * Assignment:   EECS-448 Project 1
 * Description:  Defines all methods established in the board.h file
 * Date: 9-7-2020
 *
 ---------------------------------------------------------------------------- */

#include "board.h"
#include <iostream>
#include <string>
#include <stdexcept>

Board::Board(int shipNums){
    m_shipNums = shipNums;
    remainingShip = shipNums;
    ships = new Battleship*[m_shipNums];
    for(int i = 0; i < m_shipNums; i++){
        ships[i] = new Battleship(i + 1);
    }

    //create m_board
    m_board = new string*[10];
    for (int i = 0; i < 10; i++){
        m_board[i] = new string[10];
    }
    
    for (int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
                m_board[i][j] = "-";
            }
        }
    //create m_playerViewBoard
    m_playerViewBoard = new string*[10];
    for (int i = 0; i < 10; i++){
        m_playerViewBoard[i] = new string[10];
    }

    
    for (int i = 1; i < 10; i++){
        for(int j = 1; j < 10; j++){
                m_playerViewBoard[i][j] = "-";   
        }
    }
}

//print m_board
void Board::printBoard(){
    cout<< " "<<"\t";
    char colLabel = 'A';
    for(char i = colLabel; i <= 'I'; i++){
        cout<< i << "\t";
    }
    cout<<endl;
    cout<<endl;
    int rowLabel = 1;
    for (int i = 1; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                cout<< rowLabel << "\t";
                rowLabel++;
            }
            else{
                cout<<m_board[i][j]<<"\t";
            }        
        }
        cout<<endl;
    }
    cout<<endl;
}

//print m_playerViewBoard
void Board:: printPlayerViewBoard(){
    cout<< " "<<"\t";
    char colLabel = 'A';
    for(char i = colLabel; i <= 'I'; i++){
        cout<< i << "\t";
    }
    cout<<endl;
    cout<<endl;
    int rowLabel = 1;
    for (int i = 1; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                cout<< rowLabel <<"\t";
                rowLabel++;
            }
            else{
                cout<<m_playerViewBoard[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

//return a character of a location on m_board
string Board:: getLocation(int row, int col){
    return m_board[row][col];
}

string Board:: getHistoryMove(int row, char col){
    int intCol = convertCharToInt(col);
    return m_playerViewBoard[row][intCol];
}

//set a location of m_board to a character
void Board:: setLocation(int row, int col, string newChar){
    m_board[row][col] = newChar;
}

//convert character column into integer
int Board::convertCharToInt(char character){
    switch (character)
    {
    case 'A':
        return 1;
    case 'B':
        return 2;
    case 'C':
        return 3;
    case 'D':
        return 4;
    case 'E':
        return 5;
    case 'F':
        return 6;
    case 'G':
        return 7;
    case 'H':
        return 8;
    case 'I':
        return 9;
    default:
        return 0;
        break;
    }
}


//check if the ship is off the board
bool Board::isOffArray(int p, int shipStart, int shipEnd){
    if(p < 1 || p > 9 || shipStart < 1 || shipEnd > 9 ){
        return true;
    }
    return false;
}

//check if the ship size is valid
bool Board::isValidSize(string shipType, int shipStart, int shipEnd){
    int size = stoi(shipType);
    if(shipEnd - shipStart == size - 1){
        return true;
    }
    else{
        return false;
    }
}

//check if the position is occupied horizontally
bool Board::isOccupiedHorizontally(int p, int shipStart, int shipEnd){
    for(int i = shipStart; i <= shipEnd; i++){
        if(m_board[p][i] != "-"){
            return true;
        }
    }
    return false;    
}

//check if the postion is occupied vertically
bool Board::isOccupiedVertically(int p, int shipStart, int shipEnd){
    for(int i = shipStart; i <= shipEnd; i++){
        if(m_board[i][p] != "-"){
            return true;
        }
    }
    return false;    
}
//check if it is valid to set the Ship
bool Board::isValidShip(string shipType, int p, int shipStart, int shipEnd){
    return (!isOffArray(p, shipStart, shipEnd) && isValidSize(shipType, shipStart, shipEnd));
}


//Set a ship horizontally on the board
bool Board::setShipHorizontally(string shipType, int row, char colStart, char colEnd){
    int shipStart = convertCharToInt(colStart);
    int shipEnd = convertCharToInt(colEnd);
    if(isValidShip(shipType, row, shipStart, shipEnd) && !isOccupiedHorizontally(row, shipStart, shipEnd)){
        for(int i = shipStart; i <= shipEnd; i++){
            m_board[row][i] = shipType;
        }
        return true;
    }
    else{
       return false;
    }
    
}

//Set a ship vertically on the board
bool Board::setShipVertically(string shipType, char col, int rowStart, int rowEnd){
    int intCol = convertCharToInt(col);
    if(isValidShip(shipType, intCol, rowStart, rowEnd) && !isOccupiedVertically(intCol, rowStart, rowEnd)){
        for(int i = rowStart; i <= rowEnd; i++){
            m_board[i][intCol] = shipType;
        }
        return true;
    }
    else{
       return false;
    }
}

//Set a ship
bool Board::setShip(char orientation, string shipType, int rowStart, char colStart, int rowEnd, char colEnd){
    if(orientation == 'h'){
        return (rowStart == rowEnd && setShipHorizontally(shipType, rowStart,colStart, colEnd));
    }
    else if(orientation == 'v'){
        return (colStart == colEnd && setShipVertically(shipType, colStart, rowStart, rowEnd));
    }
    else{
       return false;
    }
}

void Board:: updateShip(string shipType){
    for(int i = 0; i < m_shipNums; i++){
        if(ships[i]->getShipType() == shipType){
            ships[i]->isAttacked();
            if(ships[i]->isDestroyed()){
                remainingShip--;
            }
        }
    }
}

//return true if player hit a board and updatge m_playerViewBoard
bool Board::Hit(Board* otherPlayerBoard, int row, char col){
    int intCol = convertCharToInt(col);
        //check if player's move is valid
        if(row <= 0 || row > 9 || intCol <= 0 || row >9 || m_playerViewBoard[row][intCol] == "M" || m_playerViewBoard[row][intCol] == "H"){
            throw(runtime_error("Error: Your attack is off the board or you have made this move. Please try again"));
        }
        else{
            //check if player has missed the ship
            if(otherPlayerBoard->getLocation(row, intCol) == "-"){
                m_playerViewBoard[row][intCol] = "M";
                return false;
            }
            else{
            //check which ship is being attacked
                otherPlayerBoard->updateShip(otherPlayerBoard->getLocation(row, intCol));
                otherPlayerBoard->setLocation(row, intCol, "X");
                m_playerViewBoard[row][intCol] = "H";
                return true;
            } 
        }
        
}

int Board::getShipNums(){
    return remainingShip;
}

bool Board:: isLost(){
    return(remainingShip==0);
}

//destructor, deallocatte m_board and m_playerViewBoard
Board:: ~Board(){
    for(int i = 0; i < 10; i++){
    delete [] m_board[i];
  }
  delete[] m_board;

  for(int i = 0; i < 10; i++){
    delete [] m_playerViewBoard[i];
  }
  delete[] m_playerViewBoard;
}