/*
 * @project EECS 448 Project1 - Battleship
 * @file: Battleship.h
 * @author: Jack Gould
 * @brief: Header file for Battleship class.
 * @date: 09-06-2020
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <string>

using namespace std;

class Battleship
{
  public:
    Battleship(int size);
    /*Pre: none
    Post: battleship constructor
    Return: none
    */

    ~Battleship();
    /*Pre: none
    Post: battleship destructor
    Return: none
    */

    int getSize();
    /*Pre: the size can not exceed 5
    Post: get the ship size
    Return: return the ship size (m_size)
    */

    bool isDestroyed();
    /*Pre: the ship is hit
    Post: Call this method after each landed hit to check for ships total destruction
    Return: return true if ship is sunk
    */

    string getShipType();
    /*Pre: none
    Post: get the ship type
    Return: return shipType
    */

    void isAttacked();
    /*Pre: the ship is hit
    Post: update m_status when the ship is being attacked
    Return: return the ship status
    */

    //Call this method when ship is hit to update stored data.
    //int shipSpot should be the ships position that is hit, starting from the left for horizontal ships, and top from vertical ships. Values 1 - size.
    // void landHit(int shipSpot);

  private:
    int m_size; // stores length of ship. 1-5
    bool m_orientation; // boolean stores orientation of ship (horizontal or vertical)
    string shipType;
    string m_status = ""; // string stores status of the ship
};
#endif
