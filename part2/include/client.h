#pragma once
#include "field.h"
///клиент у которого будут поддерживаться такие операции
class Client : public InterfaceForFields {
private:
	InterfaceForFields* opponentField;
	InterfaceForFields* myField;
public:
	Client() : opponentField(nullptr), myField(nullptr) {}

	Client(InterfaceForFields* opponentField, InterfaceForFields* myField)
	 : opponentField(opponentField), myField(myField) {}

	Client(const Client& client)
	 : opponentField(client.opponentField), myField(client.myField) {}

	void setSize(int n, int m) override;
	void addShip(Ship* ship) override;
	bool attack(int x, int y) override;
	bool gameOver() override; 		

	std::vector<std::vector<char> > returnOpponentField() override; 
	std::vector<std::vector<char> > returnMyField() override; 
	std::ostream& writeOpponentField(std::ostream& os) override; 			
	std::ostream& writeMyField(std::ostream& os) override; 			
};