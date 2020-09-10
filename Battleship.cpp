/*
 * @project EECS 448 Project1 - Battleship
 * @file: Battleship.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Battleship class.
 * @date: 09-06-2020
 */

#include "Battleship.h"

Battleship::Battleship(int size, bool orientation, std::string position)
{
  m_size = size;
  m_orientation = orientation;
  m_position = position;
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

bool Battleship::getOrientation()
{
  return m_orientation();
}

std::string Battleship::getPosition()
{
  return m_position;
}

bool Battleship::isDestroyed()
{
  bool shipSunk = true;
  for(int i=0;i<m_size;++i)
  {
    if(m_status.at(i) == 'S')
    {
      shipSunk = false;
    }
  }
  return shipSunk;
}

void Battleship::landHit(int shipSpot)
{
  m_status.erase(shipSpot-1, 1);
  m_status.insert(shipSpot-1, "H");
}
