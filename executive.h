/* -----------------------------------------------------------------------------
 *
 * File Name: Executive.h
 * Author: Grant Henry
 * Assignment:  EECS 448 Project1
 * Description:  This program handle the executive action needed for the project
 * Date: 9-7-20
 *
 ---------------------------------------------------------------------------- */
//Start your program.
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Battleship.h"
#include "board.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
class Executive
{
private:
    // Board m_Board1;
    // Board m_Board2;
    Player *player1;
    Player *player2;
    Player *AI;

public:
    Executive();
    /*Pre: constructor for executive object
    Post: takes in data from the file to create the tree
    Return: executive object*/
    void run();
    /*Pre: runs program once an object is created
    Post: will present a menu that will allow the user to alter data in the tree
    Return: nothing*/
    ~Executive();
    /*Pre: destructor for object
    Post: destroys executive object once if falls out of scope
    Return: nothing*/

    char convertIntToChar(int number);
};
#endif
