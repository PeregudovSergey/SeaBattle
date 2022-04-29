#include "field.h"

/////observer
bool Observer::update(int x, int y) {
	if (ship->isThatShipCell(x, y)) {
		ship->attack(x, y); 
		return true; 
	}
	return false; 
}

bool Observer::alive() {
	return ship->alive(); 
}

Ship* Observer::getShip() {
	return ship; 
}


////////////standard field
bool StandardField::check(int xx, int yy) {
	return xx >= 0 && yy >= 0 && xx < N && yy < M; 
} 

void StandardField::setSize(int n, int m) {
	N = n; 
	M = m; 	
}

void StandardField::addShip(Ship* ship) {
	Observer* ms = new Observer;	
	ms->ship = ship; ////пока костыльно, нужно перегрузить оператор new
	views.push_back(ms); 
}	

bool StandardField::attack(int x, int y) {
	bool ok = notify(x, y); 		
	if (!ok) {
		miss.push_back(std::make_pair(x, y));
	}
	return ok; 
}

bool StandardField::notify(int x, int y) {
	bool ok = false; 
	for (int i = 0; i < views.size(); ++i) {
		ok |= (views[i]->update(x, y)); 
	}
	return ok; 
}

bool StandardField::gameOver() {	
	for (int i = 0; i < views.size(); ++i) {
		if (views[i]->alive()) return false; 		
	}
	return true; 
}

void StandardField::killShip(Ship* ship, std::vector<std::vector<char> >& field, char c) {
	for (auto cell : ship->getCells()) {			
		for (int dx = -1; dx <= 1; ++dx) {
			for (int dy = -1; dy <= 1; ++dy) {
				int xx = cell.x + dx; 
				int yy = cell.y + dy;
				if (!check(xx, yy)) continue; 
				if (ship->isThatShipCell(xx, yy)) continue; 
				field[xx][yy] = c; 
			}
		}
	}
}

std::vector<std::vector<char> > StandardField::returnOpponentField() {
	std::vector<std::vector<char> > field(N, std::vector<char>(M, '?'));
	for (auto cell : miss) {
		field[cell.first][cell.second] = 'o'; 
	}
	for (int i = 0; i < views.size(); ++i) {
		Ship* ship = views[i]->getShip(); 
		std::vector<BaseCell> cells = ship->getCells(); 
		for (auto cell : cells) {
			field[cell.x][cell.y] = cell.showForOpponent(); 
		}
		if (!(ship->alive())) {
			killShip(ship, field, '#'); 
		} 
	}
	return field; 
}

std::vector<std::vector<char> > StandardField::returnMyField() {
	std::vector<std::vector<char> > field(N, std::vector<char>(M, '.'));
	for (auto cell : miss) {
		field[cell.first][cell.second] = 'R'; 
	}
	for (int i = 0; i < views.size(); ++i) {
		Ship* ship = views[i]->getShip(); 
		std::vector<BaseCell> cells = ship->getCells(); 
		for (auto cell : cells) {
			field[cell.x][cell.y] = cell.showForMe(); 
		}
		if (!(ship->alive())) {
			killShip(ship, field, 'o'); 
		} 
	}
	return field; 
}


std::ostream& StandardField::writeOpponentField(std::ostream& os) {        		
	std::vector<std::vector<char> > field = returnOpponentField();
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < M; ++j) {
    		os << field[i][j];     	
    	}
    	os << '\n'; 
    }            
    return os;
}

std::ostream& StandardField::writeMyField(std::ostream& os) {        		
	std::vector<std::vector<char> > field = returnMyField();
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < M; ++j) {
    		os << field[i][j];     	
    	}
    	os << '\n';
    }            
    return os;
}