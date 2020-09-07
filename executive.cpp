/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Grant Henry
 * Assignment:   EECS-448 Project 1
 * Description:  Defines all methods established in the executive.h file
 * Date: 9-7-2020
 *
 ---------------------------------------------------------------------------- */
//Start your program.
#include "Executive.h"
#include <stdexcept>
Executive::Executive()//This is how we will be defining the constructor needed to connect all of the files in the lab
{

}

void Executive::run()
{
    int userChoice=0;
    std::cout<<"Welcome to Team 6's Battleship Game!\n";
    std::cout<<"This is a two-player game.\n\n";
    std::cout<<"How many battleships will each team be starting with?\n";
    std::cout<<"Please type out your choice and hit enter:\n\n";
    std::cout<<"1 battleship (for each player): '1'\n";
    std::cout<<"2 battleships:                  '2'\n";
    std::cout<<"3 battleships:                  '3'\n";
    std::cout<<"4 battleships:                  '4'\n";
    std::cout<<"5 battleships:                  '5'\n";
    std::cout<<"Your choice: ";
    std::cin>>userChoice;
    std::cout<<std::endl;


    for(int i=0;i<userChoice;i++)
    {
    std::cout<<"Player 1, place your Battleship No. "<

    }
    while(1)
    {
        //initiallize array

        
        
    }  
}
Executive::~Executive()
{
 
}
