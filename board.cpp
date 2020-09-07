#include "board.h"
#include <iostream>
#include <string>

Board::Board(){
    m_board = new char*[10];
    for (int i = 0; i < 10; i++){
        m_board[i] = new char[10];
    }
    
    char rowLabel = '0';
    for (int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                m_board[i][j] = rowLabel;
                rowLabel++;
            }
            else{
                m_board[i][j] = 'O';
            }
            
        }
    }
}

void Board::printBoard(){
    cout<< " "<<"\t";
    char colLabel = 'A';
    for(char i = colLabel; i <= 'I'; i++){
        cout<< i << "\t";
    }
    cout<<endl;
    cout<<endl;
    for (int i = 1; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout<<m_board[i][j]<<"\t";    
        }
        cout<<endl;
    }
    cout<<endl;
}

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
bool Board::isOffArray(int row, int shipStart, int shipEnd){
    if(row < 1 || row > 9 || shipStart < 1 || shipEnd > 9 ){
        return true;
    }
    return false;
}

//check if the ship size is valid
bool Board::isValidSize(int shipStart, int shipEnd){
    return (shipStart <= shipEnd);
}

//check if the position is occupied
bool Board::isOccupied(int row, int shipStart, int shipEnd){
    for(int i = shipStart; i <= shipEnd; i++){
        if(m_board[row][i] == 'T'){
            return true;
        }
    }
    return false;    
}

//check if it is valid to set the Ship
bool Board::isValidShip(int row, int shipStart, int shipEnd){
    return (!isOffArray(row, shipStart, shipEnd) && !isOccupied(row, shipStart, shipEnd) && isValidSize(shipStart, shipEnd));
}


//change the 'O' coordinates into 'T' coordinates
void Board::setShip(int row, char colStart, char colEnd){
    int shipStart = convertCharToInt(colStart);
    int shipEnd = convertCharToInt(colEnd);
    if(isValidShip(row, shipStart, shipEnd)){
        for(int i = shipStart; i <= shipEnd; i++){
            m_board[row][i] = 'T';
        }
    }
    else{
        cout<<"This ship is invalid"<<endl;
    }
    
}

//check if player hit a occupied tile
bool Board::Hit(char **board, int row, char col){
    int integerCol = convertCharToInt(col);
    if(board[row][integerCol] == 'T'){
        board[row][integerCol] = 'O';
        return true;
    }
    return false;
}

Board:: ~Board(){
    for(int i = 0; i < 10; i++){
    delete [] m_board[i];
  }
  delete[] m_board;
}