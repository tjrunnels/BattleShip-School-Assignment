#pragma once
#include "Ship.h"

class Carrier : public Ship{
public:
	Carrier(int x, int y) : Ship(x, y, 5) {};		//length 5
	bool isThere(int xCor, int yCor);				//Horizontal Ship
	bool operator==(Carrier ship);
};



class BattleShip : public Ship{
public:
	BattleShip(int x, int y) : Ship(x, y, 4) {};	//length 4
	bool isThere(int xCor, int yCor);				//Verticle Ship
};



class Submarine : public Ship{
public:
	Submarine(int x, int y) : Ship(x, y, 3) {};		//length 3
	bool isThere(int xCor, int yCor);				//Horizontal Ship
};



class Destroyer : public Ship{
public:
	Destroyer(int x, int y) : Ship(x, y, 2) {};		//length 2
	bool isThere(int xCor, int yCor);				//Verticle Ship
};

