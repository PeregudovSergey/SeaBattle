#include "ship.h"

std::vector<BaseCell> Ship::getCells() {
	return cells; 
}

bool Ship::isThatShipCell(int x, int y) {
	bool ok = false; 
	for (auto pt : cells) {			
		ok |= (pt == BaseCell(x, y, false));
	}
	return ok; 
}

bool Ship::alive() {		
	for (auto& cell : cells) {
		if (!cell.isKilled) return true; 
	}
	return false; 
}

void Ship::addCell(BaseCell& cell) {
	cells.push_back(cell); 
}



void StandardShip::buildShip(std::vector<BaseCell>& pos) {		
	for (auto x : pos) {
		addCell(x);
	}
}		

void StandardShip::attack(int x, int y) {
	BaseCell pt(x, y, false); 
	for (auto& cell : cells) {
		if (cell == pt) {
			cell.attack(); 
			break; 
		}
	}		
}	
