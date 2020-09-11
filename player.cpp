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

void Player::shooting(string UserGuess, bool Hit)//show the user shooting place in other player's board
{
    m_board->otherPlayerBoard(UserGuess, Hit);//update other player's board
}

bool Player::GettingShot(string UserGuess)//show the user getting shot place in user board
{
  if(m_board->isOffArray(UserGuess))
  {
    return (m_board->m_playerViewBoard(UserGuess));//update player's board
  }
  else
  {
    throw(runtime_error("Out of Boundary! Please try again.\n"))
  }
  //need throw runtime message if the guess not working
}
Board* Player::getBoard() const
{
  return m_board;
}
