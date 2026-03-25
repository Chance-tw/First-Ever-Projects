/*
A number guessing game for a number between and including 100 to 999.
The game should give the player 10 attempts were play, and give a score based on if they got the number or if they ran out of attempts before getting the number correct.
It will then prompt the player to ask if they want to play again and keep the score persistent over multiple plays of the game.
*/

#include <iostream>
#include <ctime>
using namespace std;

void output_game_instructions(int min, int max, int x);
int generate_rand_num(int min, int max);
void read_and_validate (int& input, int min, int max);
bool play_again();

int main()
{
    //seed random with ctime
    srand(time(0));

    //Step 1: Define and initialize your constants.
    const int MIN = 100;
    const int MAX = 999;
    const int REWARD = 1;
    const int PENALTY = -1;

    //Step 2: Define and initialize your variables.
    int score = 0;
    int attempts = 0;
    int winnum = 0;
    int guess = 0;
    
    do
    {
        //Step 3: Output game logo/instructions by calling function output_game_instructions
        output_game_instructions(MIN, MAX, 10);

        //Step 4: Generate a random number between 100 and 999 by calling function generate_rand_num
        winnum = generate_rand_num(MIN, MAX);

        //Step 5: Initialize the number of tries to 10
        attempts = 10;

        //Step 10: Repeat steps 6,7,8,9 until the player guesses correctly or runs out of tries
        for (attempts; attempts>0; attempts--) //Step 8: Decrement the number of tries available
        {
            //Step 6: Output the number of tries available
            cout << "You have " << attempts << " tries\n";

            //Step 7: Read and validate a guess from the user by calling function read_and_validate
            cout << "Please enter your guess: ";
            cin >> guess;
            read_and_validate (guess, MIN, MAX);

            //Step 9: Compare the player’s guess with the random number and output appropriate message
            if (guess == winnum)
            {
                cout << "Congratulations!\n\n";
                //score update for step 11
                score += REWARD;
                break;
            }
            else if (guess < winnum && attempts > 1)
            {
                cout << "Try higher\n\n";
            }
            else if (guess > winnum && attempts > 1)
            {
                cout << "Try lower\n\n";
            }
            else
            {
                cout << "Sorry, you ran out of guesses!\n\n";
                //score update for step 11
                score += PENALTY;
            }
        }

        //Step 11: Update the score and display it
        cout << "YOUR SCORE IS NOW " << score << endl << endl;

        //Step 12: Ask the user if (s)he wants to play again by calling function play_again
        cout << endl;
    } while (play_again()); //Step 13: If this function returns true repeat steps 3 thru 12; otherwise, let the program terminate
    return 0;
}

void output_game_instructions(int min, int max, int x)
{
    cout << "################################################\n"
    << "#  Welcome to the GUESS THE NUMBER  game !!!   #\n"
    << "#  You have " << x << " attempts to guess a number       #\n"
    << "#  between " << min << " and " << max << "! Your score will go up  #\n"
    << "#  by 1 every time you win, and down by 1 every #\n"
    << "#  time you lose. Ready! Set! Go !              #\n"
    << "################################################\n\n";
}


int generate_rand_num(int min, int max)
{
    int randnum = (rand() % (max - min + 1)) + min;
    return randnum;
}

void read_and_validate (int& input, int min, int max)
{
    while (input < min || input > max)
    {
        cout << "Invalid input! Please enter a number between 100 and 999: ";
        cin >> input;
    }
}

bool play_again()
{
    string answer;

    cout << "Would you like to play again (yes/no): ";
    while (true)
    {
        cin >> answer;
        if (answer == "yes")
        {
            return true;
        }
        else if (answer == "no")
        {
            return false;
        }
        else
        {
            cout << "Please type yes or no: ";
        }
    }
}
