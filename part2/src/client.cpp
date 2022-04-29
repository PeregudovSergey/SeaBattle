#include "client.h"

void Client::setSize(int n, int m) {
	return; 
}

void Client::addShip(Ship* ship) {
	return; 
}

bool Client::attack(int x, int y) {
	return opponentField->attack(x, y); 
}

bool Client::gameOver() {
	return opponentField->gameOver(); 
}

std::vector<std::vector<char> > Client::returnOpponentField() {
	return opponentField->returnOpponentField();	 	   
}

std::vector<std::vector<char> > Client::returnMyField() {
	return myField->returnMyField();
}

std::ostream& Client::writeOpponentField(std::ostream& os) {
	return opponentField->writeOpponentField(os);
}

std::ostream& Client::writeMyField(std::ostream& os) {
	return myField->writeMyField(os);
}