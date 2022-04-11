#pragma once 
#include <bits/stdc++.h>
#include "ship.h"
////interface for fields
///set size
///add ship 
///print field

class InterfaceForFields {
public: 	
	virtual void setSize(int n, int m) = 0;
	virtual void addShip(Ship* ship) = 0;
	///returns true/false: did you hit the ship? 
	virtual bool attack(int x, int y) = 0; 
	virtual bool gameOver() = 0; 
	virtual std::vector<std::vector<char> > returnOpponentField() = 0; 
	virtual std::vector<std::vector<char> > returnMyField() = 0; 
	virtual std::ostream& writeOpponentField(std::ostream& os) = 0; 			
	virtual std::ostream& writeMyField(std::ostream& os) = 0; 			
	////нужно будет добавить вывод своего поля, пока что есть только чужое
};

class Observer {
public: 
	Ship* ship;
public: 
	Observer() : ship(nullptr) {}
	Observer(Ship* ship) : ship(ship) {} 
	bool update(int x, int y);
	bool alive(); 
	Ship* getShip(); 		
};


class StandardField : public InterfaceForFields {
private:
	int N, M; 	
	std::vector<Observer*> views;	
	bool check(int xx, int yy); 
	bool notify(int x, int y); 		
	void killShip(Ship* ship, std::vector<std::vector<char> >& matrix, char c); 
public:	
	void setSize(int n, int m) override;		

	void addShip(Ship* ship) override; 

	bool attack(int x, int y) override;

	bool gameOver() override;

	std::vector<std::vector<char> > returnOpponentField() override; 
	std::vector<std::vector<char> > returnMyField() override; 

	std::ostream& writeOpponentField(std::ostream& os) override; 			
	std::ostream& writeMyField(std::ostream& os) override; 			
};  
