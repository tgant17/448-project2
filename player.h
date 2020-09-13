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
  //constructor
  bool setShip(char orientation, string shipType, int rowStart, char colStart, int rowEnd, char colEnd);

  //return true if attack opponent's ship
  bool Attack(Board*otherPlayerBoard, int row, char col);

  //call printBoard() in board.h
  void printMyCurrentBoard();

  //call printPlayerViewBoard in board.h
  void printMyMovesHistory();

  //return true if remainningShip == 0
  bool isLost();

  //return m_playerId
  int getPlayerID();

  //return remainingShip
  int getNumsOfRemainingShip();

  Board* getBoard() const;
  //show the player's board include guess place, hit place, have been hit place
  ~Player();
  //destructor
private:
  int numofships;
  int m_playerId;
  Board* m_Board;
  string historyguess;
};
#endif
