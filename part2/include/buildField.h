#pragma once 
#include "ship.h"
#include "field.h"
///pattern builder. We want to set properties for different games.
namespace Builder {

	///the coordinates of bottom left and top right corner
	Ship* buildStandardShip(int x1, int y1, int x2, int y2); 		

	struct rect {
		int x1, y1;
		int x2, y2; 
	}; 

	InterfaceForFields* buildClassicGame(std::vector<Ship*> ships); 		
};