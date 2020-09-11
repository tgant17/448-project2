#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

#include "board.h"

using namespace std;

class Player
{
public:
  Player(int ShipNums);
  //constructor
  void setGuessPlace(string guess);
  //set the user guess place
  string getGuessPlace() const;
  //get the user guess place
  void shooting(bool hit, string guess);
  //show the place that user shoot
  bool GettingShot(string guess);
  //show the place that user getting shoot
  Board* getBoard() const;
  //show the player's board include guess place, hit place, have been hit place
  ~Player();
  //destructor
private:
  int numofships;
  Board* m_Board =nullptr;
  string historyguess;
};
#endif
