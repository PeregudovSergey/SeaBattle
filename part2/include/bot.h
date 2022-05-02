#pragma once 
#include "buildField.h"
#include <iostream>
#inluce <vector>
#inluce <string>

namespace Bot {
	std::vector<Ship*> setShips();

	std::pair<int, int> getRandomCell(int n, int m);
}; 
