//Tom Runnels Lab 8
//CSIS 112 

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include "InheritedShips.h"
#include "Ship.h"
#include "Header.h"
using namespace std;

//i couldn't find a way to incorporate templates into the game so i just did it here.
template<typename T>
void calcArea(T val)
{
	cout << "Area is " << val << " squared, which is " << val * val << endl;
}

void readShipsFromFile(array<Ship*,5>&, int*);
void printScreen(array<Ship*, 5>&, int**,int,int);

int main()
{
	cout << "Tom Runnels  -  Battleship Lab" << endl;

	//template code
	int integ = 5;		
	double doub = 5.4;	
	calcArea(integ);	//area should be 25
	calcArea(doub);		//area should be 29.16
	
	//overloading code
	Carrier c1(3, 4);
	Carrier c2(3, 4);
	Carrier c3(5, 5);
	cout << (c1 == c2) << " <- should be true" << endl;
	cout << (c1 == c3) << " <- should be false" << endl;
	




	//main program code
	int shipCounter = 0; int*countPtr = &shipCounter;
	array<Ship*, 5> ships;
	try{
		readShipsFromFile(ships, countPtr);
	}
	catch (myexception ex){
		cout << ex.what() << endl;
	}
	
	//setting up the board
	int col = 25;
	int row = 25;

	int**p_p_board;
	p_p_board = new int*[col];
	for (int i = 0; i < row; i++)
		p_p_board[i] = new int[col];

	for (int i = 0; i < row; i++)			//each row
	{
		for (int j = 0; j < col; j++)		//each column
		{
			p_p_board[i][j] = 1;			
		}
	}

	int sX, sY;
	bool cont = true;
	printScreen(ships, p_p_board, row, col);
	while (true)
	{
		cout << "Enter a position to shoot (X [space] Y) or '0 0' to quit: ";
		cin >> sX >> sY;
		//how to break out
		if (sX == 0 && sY == 0)
			break;

		if (!(sX >= 1 && sX <= 25) || !(sY >= 1 && sX <= 25) || cin.fail()) //if the value is a letter, or either is outside 1-25
		{
			cout << "invalid input, try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		system("CLS");
		sX--; sY--;

		bool there = false;
		for (int k = 0; k < shipCounter; k++)	//each ship
		{
			if ((*ships[k]).getLength() > 1)	//if the ship at array[k] is not null
				if ((*ships[k]).isThere(sX, sY)){
					p_p_board[sX][sY] = 3; there = true; //hit
					cout << "HIT!" << endl;
				}
		}
		if (!there)
		{
			p_p_board[sX][sY] = 2; // miss
			cout << "Miss..." << endl;
		}

		printScreen(ships, p_p_board, row, col);
	}
		



	system("pause");
	return 0;
}

void readShipsFromFile(array<Ship*, 5>& ships, int* p){
	ifstream infile;
	infile.open("lvl.txt");
	int counter = 0;
	string line;
	char val;
	myexception ex;

	while (infile >> line)
	{
		val = line[0];
		switch (val)
		{
		case 'C':
			if (line[1] == 'r')		//if position is to be randomly generated
				ships[counter] = new Carrier(rand() % (25 - 5), rand() % 25);
			else					//if position is given
			{
				int value1; infile >> value1;
				int value2; infile >> value2;
				ships[counter] = new Carrier(value1, value2);
			}
				
			//cout << line[2] << "C read: " << (*ships[counter]).getX() << "," << (*ships[counter]).getY() << endl;
			counter++;
			break;


		case 'B':
			if (line[1] == 'r')		//if position is to be randomly generated
				ships[counter] = new BattleShip(rand() % (25 - 4), rand() % 25);
			else					//if position is given
			{
				int value1; infile >> value1;
				int value2; infile >> value2;
				ships[counter] = new BattleShip(value1, value2);
			}

			//cout << line[2] << "B read: " << (*ships[counter]).getX() << "," << (*ships[counter]).getY() << endl;
			counter++;
			break;


		case 'S':
			if (line[1] == 'r')		//if position is to be randomly generated
				ships[counter] = new Submarine(rand() % (25 - 3), rand() % 25);
			else					//if position is given
			{
				int value1; infile >> value1;
				int value2; infile >> value2;
				ships[counter] = new Submarine(value1, value2);
			}

			//cout << line[2] << "S read: " << (*ships[counter]).getX() << "," << (*ships[counter]).getY() << endl;
			counter++;
			break;


		case 'D':
			if (line[1] == 'r')		//if position is to be randomly generated
				ships[counter] = new Destroyer(rand() % (25 - 2), rand() % 25);
			else					//if position is given
			{
				int value1; infile >> value1;
				int value2; infile >> value2;
				ships[counter] = new Destroyer(value1, value2);
			}

			//cout << line[2] << "D read: " << (*ships[counter]).getX() << "," << (*ships[counter]).getY() << endl;
			counter++;
			break;

		default:
			throw ex;
			break;
		}
	}
	*p = counter;
}

void printScreen(array<Ship*, 5>& ships, int** map,int row, int col)
{
	for (int i = 0; i < row; i++)			//each row
	{
		for (int j = 0; j < col; j++)		//each column
		{
			switch (map[i][j])
			{
			case 1:	//water
				cout << "~";
				break;
			case 2:	//miss shot
				cout << "o";
				break;
			case 3:	//hit shot
				cout << "H";
				break;
			}
		}
		cout << endl;
	}

	//bool there = false;
	//for (int k = 0; k < shipCounter; k++)	//each ship
	//{
	//	if ((*ships[k]).getLength() > 1)	//if the ship at array[k] is not null
	//		if ((*ships[k]).isThere(i, j)){
	//			cout << "#"; there = true;
	//		}
	//}
	//if (!there)
	//cout << "~";

}

