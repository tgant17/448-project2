/* -----------------------------------------------------------------------------
 *
 * File Name:  player.cpp
 * Author: Wenxuan Hu, Thang Minh Le
 * Assignment:   EECS-448 Project 1
 * Description: Defines all methods established in the player.h file
 * Date: 9-13-2020
 *
 ---------------------------------------------------------------------------- */
#include "player.h"
#include <string>
#include <stdexcept>

using namespace std;

Player::Player(int playerId, int ShipNums)
{
  m_playerId = playerId;
  m_Board=new Board(ShipNums);
}

bool Player::setShip(char orientation, string shipType, int rowStart, char colStart, int rowEnd, char colEnd){
   return (m_Board->setShip(orientation, shipType, rowStart, colStart, rowEnd, colEnd));
}

bool Player::Attack(Board*otherPlayerBoard, int row, char col){
    if(m_Board->Hit(otherPlayerBoard, row, col)){
        return true;
    }
    else{
        return false;
    }
  }

void Player::printMyCurrentBoard(){
  m_Board->printBoard();
}

void Player::printMyMovesHistory(){
  m_Board->printPlayerViewBoard();
}

Board* Player::getBoard() const
{
  return m_Board;
}

bool Player::isLost(){
  return (m_Board->isLost());
}

int Player::getPlayerID(){
  return m_playerId;
}

int Player::getNumsOfRemainingShip(){
  return (m_Board->getShipNums());
}

Player::~Player()
{
  delete m_Board;
}
