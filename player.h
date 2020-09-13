/* -----------------------------------------------------------------------------
 *
 * File Name:  player.h
 * Author: Wenxuan Hu , Thang Minh Le
 * Assignment:   EECS-448 Project 1
 * Description:  Header file for the player's class
 * Date: 9-13-2020
 *
 ---------------------------------------------------------------------------- */
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "board.h"

using namespace std;

class Player
{
public:
  Player(int playerId, int ShipNums);
  /*Pre: none
  Post: player constructor
  Return: none
  */
  bool setShip(char orientation, string shipType, int rowStart, char colStart, int rowEnd, char colEnd);
  /*Pre: origentation, shipType, rowStart, colStart, rowEnd, and colEnd must be valid
  Post: set the ship place
  Return:  none
  */
  bool Attack(Board*otherPlayerBoard, int row, char col);
  /*Pre: none
  Post: call printBoard() in board.h
  Return: return true if attack oppent's ship
  */
  void printMyCurrentBoard();
  /*Pre: none
  Post: print the current board
  Return: return the current board
  */
  void printMyMovesHistory();
  /*Pre: none
  Post: print the moves history
  Return: print the moves history
  */
  bool isLost();
  /*Pre: none
  Post: check the remaining ship
  Return: return of remainningShip == 0
  */
  int getPlayerID();
  /*Pre: none
  Post: get playerId
  Return: return m_playerId
  */
  int getNumsOfRemainingShip();
  /*Pre: none
  Post: get numbers of remaining ship
  Return: return remainingShip
  */
  Board* getBoard() const;
  /*Pre:none
  Post: the player's board
  Return: return player's board
  */
  //show the player's board include guess place, hit place, have been hit place
  ~Player();
  /*Pre: none
  Post: player destructor
  Return: none
  */
private:
  int numofships;
  int m_playerId;
  Board* m_Board;
  string historyguess;
};
#endif
