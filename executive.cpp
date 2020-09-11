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
#include "executive.h"
#include <stdexcept>
Executive::Executive()//This is how we will be defining the constructor needed to connect all of the files in the lab
{
    
}

void Executive::run()
{
    char playAgain = '\0';
    int userChoice=0;
    int playerToggle=1;
    int rowNumber = 0;
    char columnNumber = 0;
    char leftBoundColumn = '\0';
    char rightBoundColumn = '\0';
    char horizontalOrVertical = '\0';


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

    Board m_Board1(userChoice);//Constructing two boards for the game
    Board m_Board2(userChoice);

    std::cout<<std::endl;


    for(int i=1;i<=userChoice;i++)
    {
        //Players put ships on their boards
        if(playerToggle == 1)
        {
            std::cout<<"Player "<<playerToggle<<", place your Battleship No. "<<userChoice<<" onto your board.\n";
            std::cout<<"Either type 'H' for Horizontal or 'V' for Vertical: ";
            std::cin>>horizontalOrVertical;
            if(horizontalOrVertical='H')
            {
                std::cout<<"Enter Row Number: ";
                std::cin>>rowNumber;
                std::cout<<"Enter Column Range:\n";
                std::cout<<"Left-Bound: ";
                std::cin>>leftBoundColumn;
                std::cout<<"Right-Bound: ";
                std::cin>>rightBoundColumn;
                std::cout<<std::endl;
                
                //Board Method called to install battleship
                //Battleship method called to deal with battleships taking up multiple spaces

                m_Board1.setShipHorizontally(rowNumber,leftBoundColumn,rightBoundColumn);
            }
            else
            {
                std::cout<<"Enter Column Number: ";
                std::cin>>rowNumber;
                std::cout<<"Enter Row Range:\n";
                std::cout<<"Upper-Bound: ";
                std::cin>>leftBoundColumn;
                std::cout<<"Lower-Bound: ";
                std::cin>>rightBoundColumn;
                std::cout<<std::endl;
                
                //Board Method called to install battleship
                //Battleship method called to deal with battleships taking up multiple spaces

                m_Board1.setShipVertically(rowNumber,leftBoundColumn,rightBoundColumn);
            }
            playerToggle = 2;
        }
        else
        {
            std::cout<<"Player "<<playerToggle<<", place your Battleship No. "<<userChoice<<" onto your board.\n";
            std::cout<<"Either type 'H' for Horizontal or 'V' for Vertical: ";
            std::cin>>horizontalOrVertical;
            if(horizontalOrVertical='H')
            {
                std::cout<<"Enter Row Number: ";
                std::cin>>rowNumber;
                std::cout<<"Enter Column Range:\n";
                std::cout<<"Left-Bound: ";
                std::cin>>leftBoundColumn;
                std::cout<<"Right-Bound: ";
                std::cin>>rightBoundColumn;
                std::cout<<std::endl;
                
                //Board Method called to install battleship
                //Battleship method called to deal with battleships taking up multiple spaces

                m_Board2.setShipHorizontally(rowNumber,leftBoundColumn,rightBoundColumn);
            }
            else
            {
                std::cout<<"Enter Column Number: ";
                std::cin>>rowNumber;
                std::cout<<"Enter Row Range:\n";
                std::cout<<"Upper-Bound: ";
                std::cin>>leftBoundColumn;
                std::cout<<"Lower-Bound: ";
                std::cin>>rightBoundColumn;
                std::cout<<std::endl;
                
                //Board Method called to install battleship
                //Battleship method called to deal with battleships taking up multiple spaces

                m_Board2.setShipVertically(rowNumber,leftBoundColumn,rightBoundColumn);
            }
            playerToggle = 1;
        }        
    }

    std::cout<<"Now that everyone has placed down their battleships, we can begin the game.\n";

    while(1)
    {
        //Player toggle for game turns
        if(playerToggle == 1)
        {
            std::cout<<"Player "<<playerToggle<<", select row and column to send a missle.\n";
            m_Board1.printBoard();
            std::cout<<"Enter Row Number: ";
            std::cin>>rowNumber;
            std::cout<<"Enter Column Number: ";
            std::cin>>columnNumber;

            if(m_Board1.Hit(m_Board2, rowNumber, columnNumber))
            {
                std::cout<<"It's a hit!\n";
                /*if(the targeted battleship is sunk completely)
                {
                    std::cout<<"It's a hit! Player "<<playerToggle<<" has sunk a battleship!\n";
                    if(all ships on that player's board are sunk)
                    {
                        std::cout<<"Player 1 has sunk all of Player 2's battleships, so Player 1 wins!!\n"
                        std::cout<<"Play again? (y/n)";
                        std::cin>>playAgain;
                        if(playAgain == y)
                        {
                            run();
                            break;
                        }
                        else
                        {
                            std::cout<<"Thanks for playing!\n";
                            break;
                        }
                    }
                }
                else
                {
                    std::cout<<"It's a hit! Try to hit that ship again on your next turn!\n";
                }*/
            }
            else
            {
                std::cout<<"It's a miss, try again next turn\n";
            }
            playerToggle = 2;
        }
        else
        {
            std::cout<<"Player "<<playerToggle<<", select row and column to send a missle.\n";
            m_Board1.printBoard();
            std::cout<<"Enter Row Number: ";
            std::cin>>rowNumber;
            std::cout<<"Enter Column Number: ";
            std::cin>>columnNumber;

            if(m_Board2.Hit(m_Board1, rowNumber, columnNumber))
            {
                std::cout<<"It's a hit!\n";
                /*if(the targeted battleship is sunk completely)
                {
                    std::cout<<"It's a hit! Player "<<playerToggle<<" has sunk a battleship!\n";
                    if(all ships on that player's board are sunk)
                    {
                        std::cout<<"Player 2 has sunk all of Player 1's battleships, so Player 2 wins!!\n"
                        std::cout<<"Play again? (y/n)";
                        std::cin>>playAgain;
                        if(playAgain == y)
                        {
                            run();
                            break;
                        }
                        else
                        {
                            std::cout<<"Thanks for playing!\n";
                            break;
                        }
                    }
                }
                else
                {
                    std::cout<<"It's a hit! Try to hit that ship again on your next turn!\n";
                }*/
            }
            else
            {
                std::cout<<"It's a miss, try again next turn.\n";
            }
            playerToggle = 1;
        }

        
    }  
}
Executive::~Executive()
{
 
}
