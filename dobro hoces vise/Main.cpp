#include <iostream>
#include "Deck.h"
#include <cstdlib>
#include <ctime>

int main() {

	srand(time(NULL));

	Deck D = Deck();

	std::cout << D.deal() << std::endl;

	std::cout << "Radi!\n";

	return 0;
}