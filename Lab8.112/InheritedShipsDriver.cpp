#include "InheritedShips.h"
#include "Ship.h"

bool	Carrier::isThere(int xCor, int yCor) { 
	bool value = false;		//Horizontal Ship
	if (xCor == getX())		//has to be in same row
	{
		if (getY() <= yCor && yCor < getY() + getLength()) // has to be within the length of the ship
			value = true;
	}
	return value;
}
bool Carrier::operator==(Carrier ship){
	if (this->getX() == ship.getX() && this->getY() == ship.getY())
		return true;
	else
		return false;
}



bool	BattleShip::isThere(int xCor, int yCor) {
	bool value = false;		//Verticle Ship
	if (yCor == getY())		//has to be in same column
	{
		if (getX() <= xCor && xCor < getX() + getLength()) // has to be within the length of the ship
			value = true;
	}
	return value;
}




bool	Submarine::isThere(int xCor, int yCor) {
	bool value = false;		//Horizontal Ship
	if (xCor == getX())		//has to be in same row
	{
		if (getY() <= yCor && yCor < getY() + getLength()) // has to be within the length of the ship
			value = true;
	}
	return value;
}



bool	Destroyer::isThere(int xCor, int yCor) {
	bool value = false;		//Verticle Ship
	if (yCor == getY())		//has to be in same column
	{
		if (getX() <= xCor && xCor < getX() + getLength()) // has to be within the length of the ship
			value = true;
	}
	return value;
}

