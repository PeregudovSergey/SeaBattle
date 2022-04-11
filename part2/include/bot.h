#pragma once 
#include "buildField.h"
#include <bits/stdc++.h>

namespace Bot {
	std::vector<Ship*> setShips();

	std::pair<int, int> getRandomCell(int n, int m);
}; 