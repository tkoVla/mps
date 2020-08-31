#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Poker.h"

int main() {

	srand(time(NULL));
	Poker::Deck D;

	while (!D.Empty()) {
		std::cout << D.Deal() << std::endl;
	}
	
	return 0;
}