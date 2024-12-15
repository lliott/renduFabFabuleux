#include <iostream>
#include "JankenPon.h"

int FindRandNumb(int limit)
{
    srand((unsigned)time(NULL));

    int random = rand() % limit;

    return random;
}

void DisplayWelcomeMsg()
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~~ Welcome to rock paper scissors ! ~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "" << std::endl;
}

int PlayerChooseRounds()
{
    int rounds = 0;

    std::cout << "Please specify amount of desired rounds :" << std::endl;
    std::cout << "" << std::endl;
    std::cin >> rounds;

    return rounds;
}

void JanKenPon()
{
    std::cout << "Jaaan" << std::endl;
    std::cout << "Keen" << std::endl;
    std::cout << "Pon" << std::endl;
}

int PlayerChoise()
{
    std::string choise;

    std::cout << "Can you choose between rock, paper, or scissors ?" << std::endl;
    std::cout << "" << std::endl;

    std::cin >> choise;

    if (choise == "rock") { 

        return 0;

    } else if (choise == "paper") {

        return 1;

    } else if (choise == "scissors") {

        return 2;

    } else  {

        std::cout << "Choose an actual option..." << std::endl;
        std::cout << "" << std::endl;

        return PlayerChoise();
    }
}


void DisplayCurrentWins(int a, int b, int c)
{
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~~          Current score :         ~~" << std::endl;
    std::cout << "~~       Wins : " << a << "                   ~~" << std::endl;
    std::cout << "~~       Losses : " << b << "                 ~~" << std::endl;
    std::cout << "~~       Ties : " << c << "                   ~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "" << std::endl;
}

//  0 = win ; 1 = lose ; 2 = tie
//  0 = rock ; 1 = paper ; 2 = scissors
int DidHeWin(int a, int b)
{
    const std::string names[3] = { "Rock", "Paper", "Scissors" };

    JanKenPon();
    std::cout << names[a] << " to " << names[b] << std::endl;

    if (a == b)
    {
        return 2;
    }

    if (a == 0) //rock
    {
        if (b == 1) //to paper
        {
            return 1;

        } else if (b == 2) { //to scissors

            return 0;
        }
    }
    else if (a == 1) //paper
    {
        if (b == 0) //to rock
        {
            return 0;

        } else if (b == 2) { //to scissors

            return 1;
        }
    }
    else if (a == 2) //scissors
    {
        if (b == 0) //to rock
        {
            return 1;

        } else if (b == 1) { //to paper

            return 0;
        }
    }
}

int Replay(std::string choise)
{
    if (choise == "y") { return 0; }

    else if (choise == "n") {
        return 1;
    }
    else { return 2; }
}

void GameLoop()
{
    int currentRounds = 0;

    int nmbWins = 0;
    int nmbLoss = 0;
    int nmbTies = 0;
    int replayVal = 0;

    while (replayVal == 0)
    {
        int rounds = PlayerChooseRounds();

        currentRounds = 0;
        nmbWins = 0;
        nmbLoss = 0;
        nmbTies = 0;

        while (currentRounds < rounds)
        {
            int playerChoise = PlayerChoise();

            int rand = FindRandNumb(2);

            int winVal = DidHeWin(playerChoise, rand);

            //wincheck here
            if (winVal == 0)
            {
                std::cout << "You win !" << std::endl;
                std::cout << "" << std::endl;

                nmbWins++;
            }
            else if (winVal == 1)
            {
                std::cout << "You lose !" << std::endl;
                std::cout << "" << std::endl;

                nmbLoss++;
            }
            else if (winVal == 2)
            {
                std::cout << "Its a tie !" << std::endl;
                std::cout << "" << std::endl;

                nmbTies++;
            }

            currentRounds++;
            DisplayCurrentWins(nmbWins, nmbLoss, nmbTies);
        }

        if (nmbWins > nmbLoss)
        {
            std::cout << "You've won ! Congrats, have a cookie" << std::endl;
            std::cout << "" << std::endl;
        }
        else if (nmbWins < nmbLoss)
        {
            std::cout << "Looks like you've lost :/" << std::endl;
            std::cout << "" << std::endl;
        }
        else if (nmbWins == nmbLoss)
        {
            std::cout << "Its a tie ! " << std::endl;
            std::cout << "" << std::endl;
        }

        std::string choise = "";

        while (choise != "y" && choise != "n" )
        {
            std::cout << "Would you like to play again ? (y/n)" << std::endl;
            std::cout << "" << std::endl;

            std::cin >> choise;

            replayVal = Replay(choise);

            if (replayVal == 2)
            {
                continue;
            }
        }
    }
}
