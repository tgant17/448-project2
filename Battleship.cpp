/*
 * @project EECS 448 Project1 - Battleship
 * @file: Battleship.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Battleship class.
 * @date: 09-06-2020
 */

#include "Battleship.h"

Battleship::Battleship(int size)
{
  m_size = size;
  shipType = to_string(m_size);
  for(int i=0;i<m_size;++i)
  {
    m_status.append("S");
  }
}

Battleship::~Battleship()
{
}

int Battleship::getSize()
{
  return m_size;
}

void Battleship::isAttacked(){
  m_status.erase(m_status.length() - 1);
}

bool Battleship::isDestroyed()
{
  return (m_status.length() == 0);
}

string Battleship:: getShipType(){
  return shipType;
}

// void Battleship::landHit(int shipSpot)
// {
//   m_status.erase(shipSpot-1, 1);
//   m_status.insert(shipSpot-1, "H");
// }
