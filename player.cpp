#include "player.h"

Player::Player(int ShipNums)
{
  m_Board=new Board(ShipNums);
  numofships=ShipNums;
}

Player::~Player()
{
  
}
