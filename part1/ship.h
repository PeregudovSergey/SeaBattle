#pragma once

#include <bits/stdc++.h>

///standard cell without armor and any properies 
struct BaseCell {
	int x, y;
	bool isKilled;	
	BaseCell() = default; 
	BaseCell(int x, int y, bool isKilled) : x(x), y(y), isKilled(isKilled) {}
	virtual void attack() {
		isKilled = true; 
	}	
}; 

bool operator==(BaseCell lhs, BaseCell rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y; 
}

///pattern abstract factory 
class Ship {
protected:
	std::vector<BaseCell> cells; 	
public: 
	virtual ~Ship() = 0; 
	virtual void attack(int x, int y) = 0; 		
	virtual void buildStandardShip(std::vector<BaseCell>& pos) = 0; 

	std::vector<BaseCell> getCells() {
		return cells; 
	}

	bool isThatShipCell(int x, int y) {
		bool ok = false; 
		for (auto pt : cells) {			
			ok |= (pt == BaseCell(x, y, false));
		}
		return ok; 
	}

	bool alive() {		
		for (auto& cell : cells) {
			if (!cell.isKilled) return true; 
		}
		return false; 
	}

	void addCell(BaseCell& cell) {
		cells.push_back(cell); 
	}

}; 

Ship::~Ship() {
}


class StandardShip : public Ship {
public: 			
	void buildStandardShip(std::vector<BaseCell>& pos) override {		
		for (auto x : pos) {
			addCell(x);
		}
	}		
	
	void attack(int x, int y) override {
		BaseCell pt(x, y, false); 
		for (auto& cell : cells) {
			if (cell == pt) {
				cell.attack(); 
				break; 
			}
		}		
	}	
}; 
