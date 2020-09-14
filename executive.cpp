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
#include <limits>
using namespace std;
Executive::Executive()//This is how we will be defining the constructor needed to connect all of the files in the lab
{
    
}

void Executive::run()
{
    // char playAgain = '\0';
    int userChoice=0;
    int playerToggle=1;
    int rowStart = 0;
    char colStart = '0';
    int rowEnd = 0;
    char colEnd = '0';
    char orientation = '\0';
    string shipType = "";

    cout<<"Welcome to Team 6's Battleship Game!\n";
    cout<<"This is a two-player game.\n\n";
    cout<<"How many battleships will each team be starting with?\n";
    cout<<"Please type out your choice and hit enter:\n\n";
    cout<<"1 battleship (for each player): '1'\n";
    cout<<"2 battleships:                  '2'\n";
    cout<<"3 battleships:                  '3'\n";
    cout<<"4 battleships:                  '4'\n";
    cout<<"5 battleships:                  '5'\n";
    
    //Input validation, loop breaks when user input correctly
    while(1){
        cout<<"Your choice: ";
        if(cin>>userChoice){
            if(userChoice >= 1 && userChoice <= 5){
                break;
            }
            else{
                cout<<"Your choice should be in range of 1 to 5"<<endl;
            }
        }
        else{
            cout << "Please enter a valid integer" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    cout<<"Each player has "<<userChoice<<" battle ships"<<endl;
    // Board m_Board1(userChoice);//Constructing two boards for the game
    // Board m_Board2(userChoice);
    player1 = new Player(1,userChoice);
    player2 = new Player(2,userChoice);

    cout<<endl;
    //Set up phase

    //Player1 set ships
    int i = 1;
    cout<<"----------------------------------------------------------------------------"<<endl;
    while(i <= userChoice)
    {
        //Players put ships on their boards
        if(playerToggle == 1)
        {
            shipType = to_string(i);
            cout<<"Player "<<playerToggle<<", place your 1X"<<i<<" battleship onto your board.\n";
            while(1){
                cout<<"Enter orientation (h for horizontal, v for vertical): ";
                if(cin>>orientation){
                    if(orientation == 'h' || orientation == 'v'){
                        break;
                    }
                    else{
                        cout<<"Please enter h or v for orientation"<<endl;
                    }
                }
                else{
                    cout << "Please enter a valid character" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            if(i == 1){
                cout<<"Enter ship "<< i <<" position (i.e A1): ";
                cin>>colStart>>rowStart;
                if(player1->setShip(orientation, shipType, rowStart, colStart, rowStart, colStart)){
                    i++;
                }
                else{
                    cout<<"Invalid Ship please check for orientation or size of the ship"<<endl;
                }    
            }
            else{
                cout<<"Enter ship "<< i <<" starting position: ";
                cin>>colStart>>rowStart;
                cout<<"Enter ship "<< i <<" ending position: ";
                cin>>colEnd>>rowEnd;
                cout<<endl;
                if(player1->setShip(orientation, shipType, rowStart, colStart, rowEnd, colEnd)){
                    i++;
                }
                else{
                    cout<<"Invalid Ship please check for orientation or size of the ship"<<endl;
                }
            }
                 
        }        
    }
    system("clear");
    playerToggle = 2;
    //Player2 set ships
    int j = 1;
    cout<<"----------------------------------------------------------------------------"<<endl;
    while(j <= userChoice)
    {
        //Players put ships on their boards
        if(playerToggle == 2)
        {
            shipType = to_string(j);
            cout<<"Player "<<playerToggle<<", place your 1x"<<j<<" battleship onto your board.\n";
            while(1){
                cout<<"Enter orientation (h for horizontal, v for vertical): ";
                if(cin>>orientation){
                    if(orientation == 'h' || orientation == 'v'){
                        break;
                    }
                    else{
                        cout<<"Please enter h or v for orientation"<<endl;
                    }
                }
                else{
                    cout << "Please enter a valid character" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            if(j == 1){
                cout<<"Enter ship "<< j <<" position (i.e A1): ";
                cin>>colStart>>rowStart;
                if(player2->setShip(orientation, shipType, rowStart, colStart, rowStart, colStart)){
                    j++;
                }
                else{
                    cout<<"Invalid Ship please check for orientation or size of the ship"<<endl;
                }    
            }
            else{
                cout<<"Enter ship "<< j <<" starting position: ";
                cin>>colStart>>rowStart;
                cout<<"Enter ship "<< j <<" ending position: ";
                cin>>colEnd>>rowEnd;
                cout<<endl;
                if(player2->setShip(orientation, shipType, rowStart, colStart, rowEnd, colEnd)){
                    j++;
                }
                else{
                    cout<<"Invalid Ship please check for orientation or size of the ship"<<endl;
                }
            }
        }        
    }
    system("clear");
    playerToggle = 1;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"Now that everyone has placed down their battleships, we can begin the game.\n";
    //Battle phase
    int row;
    char col;
    while(1)
    {
        //Player toggle for game turns
        if(playerToggle == 1)
        {
            cout<<"Player"<<playerToggle<<"'s remaining ships: "<<player1->getNumsOfRemainingShip()<<endl;
            cout<<"Player"<<playerToggle<<"'s current board"<<endl;
            player1->printMyCurrentBoard();
            cout<<"Player"<<playerToggle<<"'s move history"<<endl;
            player1->printMyMovesHistory();
            cout<<"Enter a coordinator to send a missle (i.e A1):";
            cin>>col>>row;
            try{
                if(player1->Attack(player2->getBoard(), row, col)){
                    system("clear");
                    cout<<"It's a hit!\n";
                    if(player2->isLost()){
                        cout<<"Player"<<playerToggle<<" wins"<<endl;
                        player2->printMyCurrentBoard();
                        break;
                    }
                }
                else{
                        system("clear");
                        cout<<"It's a miss, try again next turn\n";
                    }
                playerToggle = 2;
            }
            catch(runtime_error& e){
                cout<<e.what()<<endl;
            }       
        }
        else
        {
            cout<<"Player"<<playerToggle<<"'s remaining ships: "<<player2->getNumsOfRemainingShip()<<endl;
            cout<<"Player"<<playerToggle<<"'s current board"<<endl;
            player2->printMyCurrentBoard();
            cout<<"Player"<<playerToggle<<"'s move history"<<endl;
            player2->printMyMovesHistory();
            cout<<"Enter a coordinator to send a missle (i.e A1):";
            cin>>col>>row;

            if(player2->Attack(player1->getBoard(), row, col))
            {
                system("clear");
                cout<<"It's a hit!\n";
                if(player1->isLost()){
                    cout<<"Player"<<playerToggle<<" wins"<<endl;
                    player1->printMyCurrentBoard();
                    break;
                }
            }
            else
            {
                system("clear");
                cout<<"It's a miss, try again next turn\n";
            }
            playerToggle = 1;
        }
    }  
}
Executive::~Executive()
{
 delete player1;
 delete player2;
}
