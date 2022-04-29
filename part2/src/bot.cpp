#include "bot.h"

std::vector<Ship*> Bot::setShips() {
	std::vector<Ship*> ships; 		
	ships.push_back(Builder::buildStandardShip(0, 0, 0, 0)); 
	ships.push_back(Builder::buildStandardShip(0, 9, 0, 9)); 
	ships.push_back(Builder::buildStandardShip(9, 9, 9, 9)); 
	ships.push_back(Builder::buildStandardShip(9, 0, 9, 0)); 

	ships.push_back(Builder::buildStandardShip(0, 2, 0, 3));
	ships.push_back(Builder::buildStandardShip(0, 5, 0, 6));
	ships.push_back(Builder::buildStandardShip(2, 2, 2, 3));

	ships.push_back(Builder::buildStandardShip(9, 2, 9, 4));
	ships.push_back(Builder::buildStandardShip(7, 2, 7, 4));

	ships.push_back(Builder::buildStandardShip(0, 2, 0, 5));

	return ships; 
}

std::pair<int, int> Bot::getRandomCell(int n, int m) {
	return std::make_pair(rand() % n, rand() % m); 
}