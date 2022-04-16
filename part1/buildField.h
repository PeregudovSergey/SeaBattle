#pragma once

#include "field.h"

///pattern builder. We want to set properties for different games.
namespace Builder {

	///the coordinates of bottom left and top right corner
	Ship* buildStandardShip(int x1, int y1, int x2, int y2) {
		Ship* ship = new StandardShip;
		std::vector<BaseCell> pos; 
		for (int i = x1; i <= x2; ++i) {
			for (int j = y1; j <= y2; ++j) {
				pos.push_back({i, j, false}); 
			}
		}
		ship->buildStandardShip(pos); 
		return ship; 
	}

	struct rect {
		int x1, y1;
		int x2, y2; 
	}; 

	InterfaceForFields* buildClassicGame(std::vector<Ship*> ships) {		
		InterfaceForFields* interfaceField = new StandardField;
		interfaceField->setSize(10, 10); 		
		for (auto ship : ships) {
			interfaceField->addShip(ship); 
		}
		return interfaceField;
	}
};