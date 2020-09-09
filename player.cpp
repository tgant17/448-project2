#include "player.h"

Player::Player(int ShipNums)
{
  m_Board=new Board(ShipNums);
  numofships=ShipNums;
}

Player::~Player()
{
  delete m_board;
}

void Player::setGuessPlace(string UserGuess)//set the place have been guess
{
  historyguess=UserGuess;
}

string Player::getGuessPlace() const//return the place have been guess
{
  return historyguess;
}

void Player::shooting(/*string UserGuess, bool Hit*/)//show the user shooting place
{
  //not finished yet
  //need throw runtime message if the guess not working
}

bool Player::GettingShot(/*string UserGuess*/)//show the user getting shot place
{
  //not finished yet
  //need throw runtime message if the guess not working
}
