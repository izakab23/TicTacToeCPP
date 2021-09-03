/********************************************
Programmer	: Izak Bounds
Date		: December 19th, 2018
Assignment# : Page 239, problem 9
Course#		: N/A
Purpose		: Make TicTacToe
Language	: C++
********************************************/
#include <iostream>
#include  <stdlib.h>
using namespace std;

void drawBoard(char[]);
void boardChoice(char[], int&, bool);
bool winStatus(char[], int, bool&);

int main() 
{
	char location[9] = { '1','2','3','4','5','6','7','8','9'};	//Each board spot
	bool player = 0;	//Player 0 and 1, X and O
	bool win = 0;		//Finished game
	int choice = 1;	
	int plays = 0;		//Counts number of plays
	do
	{
		drawBoard(location);
		boardChoice(location, choice, player);
		plays++;
		win = winStatus(location, plays, player);
	} while (win == 0);
	cout << endl;
	return EXIT_SUCCESS;
}

void drawBoard(char location[])
//Pre: takes the location array
//Post: Outputs the location array to look like a TicTacToe board
{
	cout << endl;
	int position = 0;
	for (int col = 0; col < 3; col++)	//Generates Columns
	{
		for (int row = 0; row < 2; row++)	//Generates Rows
		{
			cout << " " << location[position] << " |";
			position++;
		}
		cout << " " << location[position];
		position++;
		if (col != 2)
			cout << "\n-----------\n";
	}
	cout << endl;
}

void boardChoice(char location[], int& choice, bool Nplayer)
//Pre: Takes the given player, their choice, and the location array
//Post: Changes the player's choice to the Player's Character, X or O
{
	cout << endl;
	char Cplayer;
	if (Nplayer == 0)
		Cplayer = 'X';
	else
		Cplayer = 'O';
	do
	{
		cout << "Player " << Cplayer << ": ";
		cin >> choice;
		choice = (choice - 1);
		if (location[choice] == 'X' || location[choice] == 'O' || choice > 9 || choice < 0)
			cout << "Invalid!" << endl;
	} while (location[choice] == 'X' || location[choice] == 'O' || choice > 9 || choice < 0);
	location[choice] = Cplayer;
}

bool winStatus(char location[], int plays, bool& Nplayer)
//Pre: Takes the location array, the total plays, and the player
//Post: Checks for any win condition or tie condition
{
	cout << endl;
	char Cplayer;
	if (Nplayer == 0)
		Cplayer = 'X';
	else
		Cplayer = 'O';

	//Horizontal Wins
	if ((location[0] == Cplayer && location[1] == Cplayer && location[2] == Cplayer) ||
		(location[3] == Cplayer && location[4] == Cplayer && location[5] == Cplayer) ||
		(location[6] == Cplayer && location[7] == Cplayer && location[8] == Cplayer) ||
		//Vertical Wins
		(location[0] == Cplayer && location[3] == Cplayer && location[6] == Cplayer) ||
		(location[1] == Cplayer && location[4] == Cplayer && location[7] == Cplayer) ||
		(location[2] == Cplayer && location[5] == Cplayer && location[8] == Cplayer) ||
		//diagnal Wins
		(location[0] == Cplayer && location[4] == Cplayer && location[8] == Cplayer) ||
		(location[6] == Cplayer && location[4] == Cplayer && location[2] == Cplayer))
	{
        printf("\E[2J\E[2H");   //system("CLS");
		drawBoard(location);
		cout << "\nPlayer " << Cplayer << " wins!";
		return 1;
	}
	else if (plays == 9)	//Tie
	{
        printf("\E[2J\E[2H");   //system("CLS");
		drawBoard(location);
		cout << "\nTie game";
		return 1;
	}
	else	//Continue Game
	{
		if (Nplayer == 0)
			Nplayer = 1;
		else if (Nplayer == 1)
			Nplayer = 0;
		printf("\E[2J\E[2H");   //system("CLS");
		return 0;
	}
}