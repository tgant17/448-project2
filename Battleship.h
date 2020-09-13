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

    //Constructor
    Battleship(int size);

    //Destructor
    ~Battleship();

    //return m_size
    int getSize();

    //Call this method after each landed hit to check for ships total destruction
    bool isDestroyed();

    //return shipType
    string getShipType();
    
    //Update m_status when the ship is being attacked
    void isAttacked();

    
    
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
