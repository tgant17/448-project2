/* -----------------------------------------------------------------------------
 *
 * File Name:  Executive.cpp
 * Author: Tristan Gant, Fengming Yang
 * Assignment:   EECS-448 Project 1
 * Description:  Defines all methods established in the executive.h file
 * Date: 10-4-2020
 *
 ---------------------------------------------------------------------------- */
//Start your program.
#include "executive.h"
#include <stdexcept>
#include <stdlib.h>
#include <limits>
#include <time.h>
using namespace std;
Executive::Executive() //This is how we will be defining the constructor needed to connect all of the files in the lab
{
}

void Executive::run()
{
    int userChoice = 0;
    int playerToggle = 1;
    int rowStart = 0;
    char colStart = '0';
    int rowEnd = 0;
    char colEnd = '0';
    char orientation = '\0';
    string shipType = "";
    string user_input;
    int choice = 0;

    system("clear");
    cout << "Welcome to Team 6's Battleship Game!\n";
    cout << "This game was extended by Team 17!" << endl;
    cout << "This is a two-player game or you can play with AI.\n\n";
    cout << "Do you want to play with AI?(YES OR NO): ";
    cin >> user_input;
    if (user_input == "YES" || user_input == "Yes" || user_input == "yes")
    {
        //pick ship
        system("clear");
        cout << "AI level:\n\n";
        cout << "1.Easy\n2.Medium\n3.Hard\n";
        cout << "Input your choice: ";
        cin >> choice;
        system("clear");
        cout << "How many ships do you want to play with?" << endl;
        cout << "Please type out your choice and hit enter:\n\n";
        cout << "1 battleship (for each player): '1'\n";
        cout << "2 battleships:                  '2'\n";
        cout << "3 battleships:                  '3'\n";
        cout << "4 battleships:                  '4'\n";
        cout << "5 battleships:                  '5'\n";
        while (1)
        {
            cout << "\nYour choice: ";
            if (cin >> userChoice)
            {
                if (userChoice >= 1 && userChoice <= 5)
                {
                    break;
                }
                else
                {
                    cout << "Your choice should be in range of 1 to 5" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid integer" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        cout << "Each player has " << userChoice << " battle ships" << endl;
        //player place ship
        Board m_Board1(userChoice); //Constructing two boards for the game
        Board m_Board2(userChoice); //Constructing two boards for the game
        player1 = new Player(1, userChoice);
        AI = new Player(2, userChoice);

        cout << endl;
        //Set up phase

        //Player1 set ships
        int i = 1;
        cout << "----------------------------------------------------------------------------" << endl;
        while (i <= userChoice)
        {
            //Players put ships on their boards
            if (playerToggle == 1)
            {
                system("clear");
                player1->printMyCurrentBoard();
                shipType = to_string(i);
                cout << "Player " << playerToggle << ", place your 1X" << i << " battleship onto your board.\n";
                while (1)
                {
                    cout << "Enter orientation (h for horizontal, v for vertical): ";
                    if (cin >> orientation)
                    {
                        if (orientation == 'h' || orientation == 'v' || orientation == 'H' || orientation == 'V')
                        {
                            break;
                        }
                        else
                        {
                            cout << "Please enter h or v for orientation" << endl;
                            break;

                        }
                    }
                    else
                    {
                        cout << "Please enter a valid character" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                if (i == 1)
                {
                    cout << "Enter ship " << i << " position (i.e A1): ";
                    cin >> colStart >> rowStart;
                    if (player1->setShip(orientation, shipType, rowStart, colStart, rowStart, colStart))
                    {
                        i++;
                    }
                    else
                    {
                        cout << "Invalid Ship please check for orientation or size of the ship" << endl;
                    }
                }
                else
                {
                    cout << "Enter ship " << i << " starting position: ";
                    cin >> colStart >> rowStart;
                    cout << "Enter ship " << i << " ending position: ";
                    cin >> colEnd >> rowEnd;
                    cout << endl;
                    if (player1->setShip(orientation, shipType, rowStart, colStart, rowEnd, colEnd))
                    {
                        i++;
                    }
                    else
                    {
                        cout << "Invalid Ship please check for orientation or size of the ship" << endl;
                    }
                }
            }
        }
        system("clear");
       
        playerToggle = 2;
        //AI set ships
        int j = 1;
        cout << "----------------------------------------------------------------------------" << endl;
        srand((unsigned)time(NULL));
        while (j <= userChoice)
        {
            rowStart = rand() % 9 + 1;
            colStart = convertIntToChar(rand() % 9 + 1);
            rowEnd = rand() % 9 + 1;
            colEnd = convertIntToChar(rand() % 9 + 1);
            int random = rand() % 2 + 1;
            if (playerToggle == 2)
            {
                shipType = to_string(j);
                if (random == 1)
                {
                    orientation = 'h';
                }
                else if (random == 2)
                {
                    orientation = 'v';
                }

                if (j == 1)
                {
                    if (AI->setShip(orientation, shipType, rowStart, colStart, rowStart, colStart))
                    {
                        j++;
                    }
                }
                else
                {
                    if (AI->setShip(orientation, shipType, rowStart, colStart, rowEnd, colEnd))
                    {
                        j++;
                    }
                }
            }
        }

        system("clear");
        playerToggle = 1;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Now that everyone has placed down their battleships, we can begin the game.\n";

        int row;
        char col;
        while (1)
        {
            if (playerToggle == 1)
            {
                cout << "Player" << playerToggle << "'s remaining ships: " << player1->getNumsOfRemainingShip() << endl;
                cout << "Player" << playerToggle << "'s current board" << endl;
                player1->printMyCurrentBoard();
                cout << "Player" << playerToggle << "'s move history" << endl;
                player1->printMyMovesHistory();
                cout << "Enter a coordinator to send a missle (i.e A1):";
                cin >> col >> row;
                try
                {
                    if (player1->Attack(AI->getBoard(), row, col))
                    {
                        system("clear");
                        cout << "It's a hit!\n\n";
                        if (AI->isLost())
                        {
                            cout << "Player" << playerToggle << " wins" << endl;
                            AI->printMyCurrentBoard();
                            break;
                        }
                    }
                    else
                    {
                        system("clear");
                        cout << "It's a miss, try again next turn\n\n";
                    }
                    playerToggle = 2;
                }
                catch (runtime_error &e)
                {
                    cout << e.what() << endl;
                }
            }

            else
            {
                if (choice == 1) //good
                {
                    row = rand() % 9 + 1;
                    col = convertIntToChar(rand() % 9 + 1);
                    try
                    {
                        cout << "AI" << "'s remaining ships: " << AI->getNumsOfRemainingShip() << endl;
                        cout << endl;
                        // cout << "AI" << "'s current board" << endl;
                        // AI->printMyCurrentBoard();
                        if (AI->Attack(player1->getBoard(), row, col))
                        {
                            // system("clear");
                            cout << "It's a hit!\n";
                            if (player1->isLost())
                            {
                                cout << "Player" << playerToggle << " wins" << endl;
                                AI->printMyCurrentBoard();
                                break;
                            }
                        }
                        else
                        {
                            cout << "It's a miss, try again next turn(AI)\n";
                            // system("clear");
                        }
                        cout << "AI" << "'s move history" << endl;
                        AI->printMyMovesHistory();
                        cout << "Enter any character and hit enter to skip---------------------------------------------------";
                        string skip = "";
                        cin >> skip;
                        playerToggle = 1;
                        system("clear");
                    }
                    catch (runtime_error &e)
                    {
                        cout << e.what() << endl;
                    }
                }
                else if (choice == 2)
                {
                    bool checkFire = false;
                    if (checkFire)
                    {
                        char originCol = col;
                        int originRow = row;
                        int current_ship = AI->getNumsOfRemainingShip();
                        while (1)
                        {
                            row++;
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                row = originRow;
                            }

                            row--;
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                row = originRow;
                            }

                            col = convertIntToChar(col++);
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                col = originCol;
                            }

                            col = convertIntToChar(col--);
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                col = originCol;
                            }
                        }
                        try
                        {
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                if (current_ship != AI->getNumsOfRemainingShip())
                                {
                                    checkFire = false;
                                }
                                else
                                {
                                    // system("clear");
                                    cout << "It's a hit!\n";
                                    checkFire = true;
                                    if (player1->isLost())
                                    {
                                        cout << "Player" << playerToggle << " wins" << endl;
                                        AI->printMyCurrentBoard();

                                        break;
                                    }
                                }
                            }
                            else
                            {
                                // system("clear");
                                cout << "It's a miss, try again next turn(AI)\n";
                            }

                            cout << "AI" << "'s remaining ships: " << AI->getNumsOfRemainingShip() << endl;
                            // cout << "AI" << "'s current board" << endl;
                            // AI->printMyCurrentBoard();
                            cout << "AI" << "'s move history" << endl;
                            AI->printMyMovesHistory();
                            cout << "Enter any character and hit enter to skip---------------------------------------------------";
                            string skip = "";
                            cin >> skip;
                            playerToggle = 1;
                            system("clear");
                        }
                        catch (runtime_error &e)
                        {
                            cout << e.what() << endl;
                        }
                    }
                    else //before they have hit they fire randomly -- just like easy
                    {
                        row = rand() % 9 + 1;
                        col = convertIntToChar(rand() % 9 + 1);
                        try
                        {
                            cout << "AI" << "'s remaining ships: " << AI->getNumsOfRemainingShip() << endl;
                            cout << endl;
                            // cout << "AI" << "'s current board" << endl;
                            // AI->printMyCurrentBoard();
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                // system("clear");
                                checkFire = true;
                                cout << "It's a hit!\n";
                                if (player1->isLost())
                                {
                                    cout << "Player" << playerToggle << " wins" << endl;
                                    AI->printMyCurrentBoard();
                                    break;
                                }
                            }
                            else
                            {
                                cout << "It's a miss, try again next turn(AI)\n";
                                // system("clear");
                            }
                            cout << "AI" << "'s move history" << endl;
                            AI->printMyMovesHistory();
                            cout << "Enter any character and hit enter to skip---------------------------------------------------";
                            string skip = "";
                            cin >> skip;
                            playerToggle = 1;
                            system("clear");
                        }
                        catch (runtime_error &e)
                        {
                            cout << e.what() << endl;
                        }
                    }
                }
                else if (choice == 3) //good
                {
                    row = 1;
                    col = 1;
                    bool check = false;
                    if (check == false)
                    {
                        for (int i = 1; i <= 9; i++)
                        {
                            for (int j = 0; j <= 9; j++)
                            {
                                if (player1->getBoard()->getLocation(i, j) == "1" || player1->getBoard()->getLocation(i, j) == "2" || player1->getBoard()->getLocation(i, j) == "3" || player1->getBoard()->getLocation(i, j) == "4" || player1->getBoard()->getLocation(i, j) == "5")
                                {
                                    row = i;
                                    col = j;
                                    break;
                                }
                            }
                        }
                        try
                        {
                            col = convertIntToChar(col);
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                // system("clear");
                                cout << "It's a hit!\n";
                                check = true;
                                if (player1->isLost())
                                {
                                    cout << "Al wins!" << endl;
                                    AI->printMyCurrentBoard();
                                    break;
                                }
                            }
                            else
                            {
                                // system("clear");
                                cout << "It's a miss, try again next turn\n";
                            }

                            cout << "AI" << "'s remaining ships: " << AI->getNumsOfRemainingShip() << endl;
                            // cout << "AI" << "'s current board" << endl;
                            // AI->printMyCurrentBoard();
                            cout << "AI" << "'s move history" << endl;
                            AI->printMyMovesHistory();
                            cout << "Enter any character and hit enter to skip---------------------------------------------------";
                            string skip = "";
                            cin >> skip;
                            playerToggle = 1;
                            system("clear");
                        }
                        catch (runtime_error &e)
                        {
                            cout << e.what() << endl;
                        }
                    }
                    else
                    {
                        char originCol = col;
                        int originRow = row;
                        int current_ship = player1->getNumsOfRemainingShip();
                        while (1)
                        {
                            row++;
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                row = originRow;
                            }

                            row--;
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                row = originRow;
                            }

                            col = convertIntToChar(col++);
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                col = originCol;
                            }

                            col = convertIntToChar(col--);
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                break;
                            }
                            else
                            {
                                col = originCol;
                            }
                        }
                        try
                        {
                            if (AI->Attack(player1->getBoard(), row, col))
                            {
                                if (current_ship != player1->getNumsOfRemainingShip())
                                {
                                    check = false;
                                }
                                else
                                {
                                    system("clear");
                                    cout << "It's a hit!\n";
                                    if (player1->isLost())
                                    {
                                        cout << "Player" << playerToggle << " wins" << endl;
                                        AI->printMyCurrentBoard();

                                        break;
                                    }
                                }
                            }
                            else
                            {
                                system("clear");
                                cout << "It's a miss, try again next turn\n";
                            }

                            cout << "AI" << "'s remaining ships: " << AI->getNumsOfRemainingShip() << endl;
                            // cout << "AI" << "'s current board" << endl;
                            // AI->printMyCurrentBoard();
                            cout << "AI" << "'s move history" << endl;
                            AI->printMyMovesHistory();
                            cout << "Enter any character and hit enter to skip---------------------------------------------------";
                            string skip = "";
                            cin >> skip;
                            playerToggle = 1;
                            system("clear");
                        }
                        catch (runtime_error &e)
                        {
                            cout << e.what() << endl;
                        }
                    }
                }
                //AI-Level function end
            }
        }
    }

    else if(user_input == "no" || user_input == "No" || user_input == "NO" || user_input == "nO")
    {
        system("clear"); 
        cout << "The game will be played with TWO players\n" << endl;
        cout << "How many ships would you like play with?\n";
        cout << "Please type out your choice and hit enter:\n\n";
        cout << "1 battleship (for each player): '1'\n";
        cout << "2 battleships:                  '2'\n";
        cout << "3 battleships:                  '3'\n";
        cout << "4 battleships:                  '4'\n";
        cout << "5 battleships:                  '5'\n";
        //Input validation, loop breaks when user input correctly
        while (1)
        {
            cout << "Your choice: ";
            if (cin >> userChoice)
            {
                if (userChoice >= 1 && userChoice <= 5)
                {
                    break;
                }
                else
                {
                    cout << "Your choice should be in range of 1 to 5" << endl;
                }
            }
            else
            {
                cout << "Please enter a valid integer" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Each player has " << userChoice << " battle ships" << endl;
        Board m_Board1(userChoice); //Constructing two boards for the game
        Board m_Board2(userChoice);
        player1 = new Player(1, userChoice);
        player2 = new Player(2, userChoice);

        cout << endl;
        //Set up phase

        //Player1 set ships
        int i = 1;
        cout << "----------------------------------------------------------------------------" << endl;
        while (i <= userChoice)
        {
            //Players put ships on their boards
            if (playerToggle == 1)
            {
                shipType = to_string(i);
                cout << "Player " << playerToggle << ", place your 1X" << i << " battleship onto your board.\n";
                while (1)
                {
                    cout << "Enter orientation (h for horizontal, v for vertical): ";
                    if (cin >> orientation)
                    {
                        if (orientation == 'h' || orientation == 'v')
                        {
                            break;
                        }
                        else
                        {
                            cout << "Please enter h or v for orientation" << endl;
                        }
                    }
                    else
                    {
                        cout << "Please enter a valid character" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                if (i == 1)
                {
                    cout << "Enter ship " << i << " position (i.e A1): ";
                    cin >> colStart >> rowStart;
                    if (player1->setShip(orientation, shipType, rowStart, colStart, rowStart, colStart))
                    {
                        i++;
                    }
                    else
                    {
                        cout << "Invalid Ship please check for orientation or size of the ship" << endl;
                    }
                }
                else
                {
                    cout << "Enter ship " << i << " starting position: ";
                    cin >> colStart >> rowStart;
                    cout << "Enter ship " << i << " ending position: ";
                    cin >> colEnd >> rowEnd;
                    cout << endl;
                    if (player1->setShip(orientation, shipType, rowStart, colStart, rowEnd, colEnd))
                    {
                        i++;
                    }
                    else
                    {
                        cout << "Invalid Ship please check for orientation or size of the ship" << endl;
                    }
                }
            }
        }
        system("clear");
        playerToggle = 2;
        //Player2 set ships
        int j = 1;
        cout << "----------------------------------------------------------------------------" << endl;
        while (j <= userChoice)
        {
            //Players put ships on their boards
            if (playerToggle == 2)
            {
                shipType = to_string(j);
                cout << "Player " << playerToggle << ", place your 1x" << j << " battleship onto your board.\n";
                while (1)
                {
                    cout << "Enter orientation (h for horizontal, v for vertical): ";
                    if (cin >> orientation)
                    {
                        if (orientation == 'h' || orientation == 'v')
                        {
                            break;
                        }
                        else
                        {
                            cout << "Please enter h or v for orientation" << endl;
                        }
                    }
                    else
                    {
                        cout << "Please enter a valid character" << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                if (j == 1)
                {
                    cout << "Enter ship " << j << " position (i.e A1): ";
                    cin >> colStart >> rowStart;
                    if (player2->setShip(orientation, shipType, rowStart, colStart, rowStart, colStart))
                    {
                        j++;
                    }
                    else
                    {
                        cout << "Invalid Ship please check for orientation or size of the ship" << endl;
                    }
                }
                else
                {
                    cout << "Enter ship " << j << " starting position: ";
                    cin >> colStart >> rowStart;
                    cout << "Enter ship " << j << " ending position: ";
                    cin >> colEnd >> rowEnd;
                    cout << endl;
                    if (player2->setShip(orientation, shipType, rowStart, colStart, rowEnd, colEnd))
                    {
                        j++;
                    }
                    else
                    {
                        cout << "Invalid Ship please check for orientation or size of the ship" << endl;
                    }
                }
            }
        }
        system("clear");
        playerToggle = 1;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Now that everyone has placed down their battleships, we can begin the game.\n";
        //Battle phase
        int row;
        char col;
        while (1)
        {
            //Player toggle for game turns
            if (playerToggle == 1)
            {
                cout << "Player" << playerToggle << "'s remaining ships: " << player1->getNumsOfRemainingShip() << endl;
                cout << "Player" << playerToggle << "'s current board" << endl;
                player1->printMyCurrentBoard();
                cout << "Player" << playerToggle << "'s move history" << endl;
                player1->printMyMovesHistory();
                cout << "Enter a coordinator to send a missle (i.e A1):";
                cin >> col >> row;
                try
                {
                    if (player1->Attack(player2->getBoard(), row, col))
                    {
                        system("clear");
                        cout << "It's a hit!\n";
                        if (player2->isLost())
                        {
                            cout << "Player" << playerToggle << " wins" << endl;
                            player2->printMyCurrentBoard();
                            break;
                        }
                    }
                    else
                    {
                        system("clear");
                        cout << "It's a miss, try again next turn\n";
                    }
                    playerToggle = 2;
                }
                catch (runtime_error &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
            {
                cout << "Player" << playerToggle << "'s remaining ships: " << player2->getNumsOfRemainingShip() << endl;
                cout << "Player" << playerToggle << "'s current board" << endl;
                player2->printMyCurrentBoard();
                cout << "Player" << playerToggle << "'s move history" << endl;
                player2->printMyMovesHistory();
                cout << "Enter a coordinator to send a missle (i.e A1):";
                cin >> col >> row;

                if (player2->Attack(player1->getBoard(), row, col))
                {
                    system("clear");
                    cout << "It's a hit!\n";
                    if (player1->isLost())
                    {
                        cout << "Player" << playerToggle << " wins" << endl;
                        player1->printMyCurrentBoard();
                        break;
                    }
                }
                else
                {
                    system("clear");
                    cout << "It's a miss, try again next turn\n";
                }
                playerToggle = 1;
            }
        }
    }
}
Executive::~Executive()
{
    delete player1;
    delete player2;
    delete AI;
}

char Executive::convertIntToChar(int number)
{
    switch (number)
    {
    case 1:
        return 'A';
        break;
    case 2:
        return 'B';
        break;
    case 3:
        return 'C';
        break;
    case 4:
        return 'D';
        break;
    case 5:
        return 'E';
        break;
    case 6:
        return 'F';
        break;
    case 7:
        return 'G';
        break;
    case 8:
        return 'H';
        break;
    case 9:
        return 'I';
        break;
    }
    return number;
}
