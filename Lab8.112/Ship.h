#pragma once


class Ship{
private:
	int posX;
	int posY;
	int length;
public:
	Ship(int x, int y, int len){ setX(x); setY(y); setLength(len); }
	int getX() { return posX; }
	void setX(int x) { posX = x; }
	int getY() { return posY; }
	void setY(int y) { posY = y; }
	int getLength() { return length; }
	void setLength(int len) { length = len; }
	virtual bool isThere(int xCor, int yCor) = 0;
};