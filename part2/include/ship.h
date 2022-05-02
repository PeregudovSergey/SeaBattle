#pragma once 
#include <iostream>
#include <vector>
#include <string>
///standard cell without armor and any properies 
struct BaseCell {
	int x, y;
	bool isKilled;	
	BaseCell() = default; 
	BaseCell(int x, int y, bool isKilled) : x(x), y(y), isKilled(isKilled) {}
	bool operator==(BaseCell rhs) {
		return x == rhs.x && y == rhs.y; 
	}

	virtual void attack() {
		isKilled = true; 
	}	

	virtual char showForOpponent() {
		if (isKilled) return 'X'; 
		return '?'; 
	}

	virtual char showForMe() {
		if (isKilled) return 'X'; 
		return '#'; 
	}
}; 

///pattern abstract factory 
class Ship {
protected:
	std::vector<BaseCell> cells; 	
public: 	
	virtual void attack(int x, int y) = 0; 		
	virtual void buildShip(std::vector<BaseCell>& pos) = 0; 

	std::vector<BaseCell> getCells();

	bool isThatShipCell(int x, int y); 		

	bool alive(); 	

	void addCell(BaseCell& cell); 		

}; 

class StandardShip : public Ship {
public: 			
	void buildShip(std::vector<BaseCell>& pos) override; 		
	
	void attack(int x, int y) override;		
}; 
