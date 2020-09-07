#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

#include "board.h"

using namespace std;

class Player
{
public:
  Player(int ShipNums);

  void setGuessPlace(string guess);

  string getGuessPlace() const;

  void shooting(bool hit, string guess);

  bool GettingShot(string guess);

  board* getBoard() const;

  ~Player();
private:

};
#endif
