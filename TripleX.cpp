#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print welcome messages to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nYou need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declare 3 numbers to 3 variables
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product to the terminal
    std::cout << "+ There are three numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if the players guess is correct.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win! You have gained access to the level " << Difficulty << " server room.";
        return true;
    }
    else
    {
        std::cout << "\nThat is the incorrect Code, level " << Difficulty << " was too much of a challenge for you! Please try again.";
        return false;
    }
}

int main()
{
    srand(time(NULL));

    int LevelDifficulty = 1;

    int const MaxLevel = 10;

    while (LevelDifficulty <= MaxLevel) // Loop the game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n\n\nCongratulations, you have accessed all server room security levels!";
    return 0;
}
