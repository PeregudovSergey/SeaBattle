#pragma once
#include "client.h"

bool Client::attack(int x, int y) {
	return opponentField->attack(x, y); 
}

bool Client::gameOver() {
	return opponentField->gameOver(); 
}

void Client::showOpponentField(std::ostream& os) {
	opponentField->writeOpponentField(os);
}