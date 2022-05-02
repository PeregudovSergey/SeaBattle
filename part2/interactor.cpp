//game with bot
#include <iostream>
#include <vector>
#include <string>
#include "client.h"
#include "buildField.h" 
#include "bot.h"

void get_coord(int &x1, int &y1) {
	std::cin >> x1 >> y1; 
}

void get_coord(int &x1, int &y1, int &x2, int &y2) {
	get_coord(x1, y1); 
	get_coord(x2, y2); 	
}

InterfaceForFields* buildClientField() {
	std::cout << "Пока что у вас есть возможность сыграть только с ботом в классический морской бой:(" << std::endl; 

	std::vector<int> size = {4, 3, 2, 1}; 
	std::vector<int> cnt = {1, 2, 3, 4};	
	std::vector<Ship*> myShips = Bot::setShips();
	/*
	for (int it = 0; it < 4; ++it) {
		for (int j = 0; j < cnt[it]; ++j) {
			std::cout << "Введите координаты коробля из " << size[it] << " клеток!" << std::endl; 
			int x1, y1, x2, y2; 
			get_coord(x1, y1, x2, y2); 
			myShips.push_back(Builder::buildStandardShip(x1, y1, x2, y2)); 
		}
	}*/
	return Builder::buildClassicGame(myShips); 
}

void ClientMove(InterfaceForFields* me) {	
	me->writeMyField(std::cout); 	
	std::cout << "\n\n\n\n"; 
	std::cout << "Введите ваш ход" << std::endl; 
	me->writeOpponentField(std::cout);
	int x1, y1; 
	get_coord(x1, y1); 
	std::cerr << x1 << " " << y1 << std::endl; 
	bool hit = me->attack(x1, y1); 
	if (hit) {
		if (me->gameOver()) {
			std::cout << "Вы победили!" << std::endl; 
			exit(0); 
		} 
		std::cout << "Вы ранили корабль, а может и убили!" << std::endl; 
		me->writeOpponentField(std::cout);
		std::cout << "\n\n\n"; 
		ClientMove(me); 		
	} else {
		std::cout << "Мимо:(" << std::endl; 		
		return; 
	}
}

void BotMove(InterfaceForFields* bot) {	
	std::pair<int, int> pr = Bot::getRandomCell(10, 10); 
	int x1 = pr.first, y1 = pr.second; 	
	bool hit = bot->attack(x1, y1); 
	if (hit) {
		if (bot->gameOver()) {
			std::cout << "Вы проиграли:(" << std::endl; 
			exit(0); 
		} 
		std::cout << "Бот ранил ваш корабль!" << std::endl; 
		std::cout << "Вот что с вашем полем!" << std::endl; 		
		bot->writeOpponentField(std::cout); 
		BotMove(bot); 		
	} else {
		std::cout << "Бот промазал" << std::endl; 		
		return; 
	}
}

int main(int argc, char** argv) {
	InterfaceForFields* myField = buildClientField(); 
	std::cout << "Вы успешно расставили свои корабли!" << std::endl; 
	InterfaceForFields* botField = Builder::buildClassicGame(Bot::setShips());
	
	InterfaceForFields* me = new Client(botField, myField); 
	InterfaceForFields* bot = new Client(myField, botField); 	

	std::cout << "Toss a coin!" << std::endl;
	std::cout << "You win! Go first" << std::endl;
	int turn = 0; 
	while (true) {
		if (turn == 0) {
			ClientMove(me); 
		} else {
			BotMove(bot); 
		}
		turn ^= 1; 
	}
}
