/*Branden Fox
Csci 207
3/15/2018
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cmath> 
#include <cctype>

using std::cout;
using std::cin;
using std::getline;
using namespace std;

int lastGuess = 0;
int counter = 0;
int difficulty = 0;
char menuOption;
int guess = 0;
int randnum = 0;
int difficultyChoice = 0;

int topFive = 5;
string users[5] = { "FOX", "BILL", "BOO", "MAR", "HIM" };

int score = 0;
int scores[5] = { 5, 6, 7, 9, 11 };


int closeGuesser(int, int);
void directionHelper(int, int);
int pickDifficulty(char, int);



int pickDifficulty(char menuOption, int difficulty)
{
	cout << "Choose a difficulty\nA) 10 B) 100 C) 1000 D) Custom" << endl;
	cin >> menuOption;
	menuOption = toupper(menuOption);

	if (menuOption == 'A')
	{
		difficulty = 10;
		return difficulty;
	}
	else if (menuOption == 'B')
	{
		difficulty = 100;
		return difficulty;
	}
	else if (menuOption == 'C')
	{
		difficulty = 1000;
		return difficulty;
	}
	else
	{
		cout << "enter a number\n"; //default to custom answer if wrong input
		cin >> difficulty;
		return difficulty;
	}

}

void directionHelper(int userGuess, int randnum)
{
	if (lastGuess == 0)
	{
		//do nothing	
	}
	else if (abs(userGuess - randnum) < abs(lastGuess - randnum))
	{
		cout << "Getting closer\n" << endl;
	}
	else if (abs(userGuess - randnum) > abs(lastGuess - randnum))
	{
		cout << "Getting further\n" << endl;
	}
	lastGuess = userGuess;
}
void highScores(string users[], int scores[], int counter)
{
	if (counter < scores[topFive-1])
	{
		for (int i = 0; i < topFive - 1; i++)  //redoes every score worse than new score. needs to be fixed
		{
			if (counter < scores[i])
			{
				string username;
				cout << "\n\nNEW HIGH SCORE!\n";
				cout << "Enter a 3 digit name\n";//redo  move everything down, put new high score in 0 position.  then sort later.
				cin >> username;
				users[i] = username;
				scores[i] = counter;

			}
		}
	}

	for (int i = 0; i < topFive - 1; i++)
	{
		cout << users[i] << " " << scores[i] << endl;
	}


}
int closeGuesser(int guess, int randnum)
{
	while (guess != randnum)
	{
		cin >> guess;
		int userGuess = guess;



		if (guess == randnum)
		{
			cout << "You found it!\n";
		}
		else if (abs(guess - randnum) <= 2)
		{
			cout << "VERY CLOSE" << endl;
			directionHelper(userGuess, randnum);
		}
		else if (abs(guess - randnum) <= 5)
		{
			cout << "Close!" << endl;
			directionHelper(userGuess, randnum);
		}
		else if (abs(guess - randnum) <= 10)
		{
			cout << "Kind of close" << endl;
			directionHelper(userGuess, randnum);
		}
		else if (abs(guess - randnum) <= 20)
		{
			cout << "a little off..." << endl;
			directionHelper(userGuess, randnum);
		}
		else
		{
			cout << "Way off" << endl;
			directionHelper(userGuess, randnum);
		}
		counter++;
	}
	cout << "it took you " << counter << " tries to find the number!" << endl;
	return counter;
}

int main()
{
	cout << "Welcome to the Number Guesser game!";

	do {
		difficulty = pickDifficulty(menuOption, difficulty);

		srand(time(0));
		randnum = ((rand() % difficulty + 1));

		cout << "Number Guesser 1-" << difficulty << endl;

		closeGuesser(guess, randnum);

		highScores(users, scores, counter);

		cout << "Play again? Y/N";
		cin >> menuOption;

	} while (toupper(menuOption) != 'N');
	cout << "Thanks for playing";
	return 0;
}