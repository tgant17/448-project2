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
    int playerToggle=1;
    int rowNumber = 0;
    int columnNumber = 0;
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


    for(int i=1;i<=userChoice;i++)
    {
        std::cout<<"Player "<<playerToggle<<", place your Battleship No. "<<userChoice<<" onto your board.\n";
        std::cout<<"Enter Row Number: ";
        std::cin>>rowNumber;
        std::cout<<"Enter Column Number: ";
        std::cin>>columnNumber;
        
        //Board Method called to install battleship
        //Battleship method called to deal with battleships taking up multiple spaces



        //Toggle between player 1 and 2
        if(playerToggle == 1)
        {
            playerToggle = 2;
        }
        else
        {
            playerToggle = 1;
        }
        
    }
    while(1)
    {
        //Player toggle for game turns
        if(playerToggle == 1)
        {
            playerToggle = 2;
        }
        else
        {
            playerToggle = 1;
        }


        std::cout<<"Now that everyone has placed down their battleships, we can begin the game.\n";
        std::cout<<"Player "<<playerToggle<<", select row and column to send a missle.\n";
        std::cout<<"Enter Row Number: ";
        std::cin>>rowNumber;
        std::cout<<"Enter Column Number: ";
        std::cin>>columnNumber;

        /*if(player 1's selection matches coordinates of player 2's battleship)
        {
            std::cout<<"It's a hit!\n";
            if(the targeted battleship is sunk completely)
            {
                std::cout<<"It's a hit! Player "<<playerToggle<<" has sunk a battleship!\n";
            }
            else
            {
                std::cout<<"It's a hit! Try to hit that ship again on your next turn!\n";
            }
        }
        else
        {
            std::cout<<"It's a miss.....\n";
        }*/

        
    }  
}
Executive::~Executive()
{
 
}
