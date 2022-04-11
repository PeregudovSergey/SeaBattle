#include "buildField.h"

Ship* Builder::buildStandardShip(int x1, int y1, int x2, int y2) {
	Ship* ship = new StandardShip;
	std::vector<BaseCell> pos; 
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			pos.push_back({i, j, false}); 
		}
	}
	ship->buildShip(pos); 
	return ship; 
}

InterfaceForFields* Builder::buildClassicGame(std::vector<Ship*> ships) {		
	InterfaceForFields* interfaceField = new StandardField;
	interfaceField->setSize(10, 10); 		
	for (auto ship : ships) {
		interfaceField->addShip(ship); 
	}
	return interfaceField;
}