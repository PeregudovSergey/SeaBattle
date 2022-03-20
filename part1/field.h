#pragma once

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
	virtual std::vector<std::string> returnField() = 0; 
	virtual std::ostream& write(std::ostream& os) = 0; 		
	////нужно будет добавить вывод своего поля, пока что есть только чужое
};


class StandardField : public InterfaceForFields {
private:
	int N, M; 
	std::vector<std::string> field; 
	std::vector<Ship*> ships;
	bool check(int xx, int yy) {
		return xx >= 0 && yy >= 0 && xx < N && yy < M; 
	} 
	
public:	
	void setSize(int n, int m) override {
		N = n; 
		M = m; 
		field.resize(N, std::string(M, '?')); 
	}

	void addShip(Ship* ship) override {
		ships.push_back(ship); 
	}	
	void killShip(Ship* ship) {
		for (auto cell : ship->getCells()) {			
			for (int dx = -1; dx <= 1; ++dx) {
				for (int dy = -1; dy <= 1; ++dy) {
					int xx = cell.x + dx; 
					int yy = cell.y + dy;
					if (!check(xx, yy)) continue; 
					if (ship->isThatShipCell(xx, yy)) continue; 
					field[xx][yy] = '#'; 
				}
			}
		}
	}

	bool attack(int x, int y) override {
		bool hit_ship = false; 
		for (auto ship : ships) {
			if (ship->isThatShipCell(x, y)) {				
				ship->attack(x, y); 
				field[x][y] = 'X'; 
				///если убили корабль, то должны изменить поле
				if (!(ship->alive())) {
					killShip(ship); 
				}				
				hit_ship = true; 
				break; 
			}
		}
		if (!hit_ship) {
			field[x][y] = '#'; 
		}
		return hit_ship; 
	}

	bool gameOver() {
		for (auto& ship : ships) {
			if (ship->alive()) return false; 
		}
		return true; 
	}

	std::vector<std::string> returnField() override {
		return field; 
	}

	std::ostream& write(std::ostream& os) override {        		
        for (int i = 0; i < N; ++i) {
        	os << field[i]; 
        	os << '\n'; 
        }            
        return os;
    }
};  

/*
int main() {
	InterfaceForFields* base = new StandardField; 	
	base->setSize(3, 3); 
	base->write(std::cout);
	Ship* ship = new StandardShip; 
	std::vector<BaseCell> ms = {BaseCell(1, 1, false), BaseCell(1, 2, false)}; 
	ship->buildStandardShip(ms); 

	base->addShip(ship); 

	std::cerr << base->attack(1, 1) << '\n'; 
	base->write(std::cout); 
	return 0; 
}
*/