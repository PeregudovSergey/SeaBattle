#pragma once
#include "field.h"
///клиент у которого будут поддерживаться такие операции
class Client {
private:
	InterfaceForFields* opponentField;
public:
	Client() : opponentField(nullptr) {}

	Client(InterfaceForFields* opponentField)
	 : opponentField(opponentField) {}	

	bool attack(int x, int y); 		

	bool gameOver(); 		

	void showOpponentField(std::ostream& os); 		
};