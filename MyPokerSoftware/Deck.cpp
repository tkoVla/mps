#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "Deck.h"

std::vector<std::string> Deck::Cards = { "A", "K", "Q", "J", "T", "9", "8", "7", "6", "5", "4", "3", "2" };
std::vector<std::string> Deck::Suits = { "s", "d", "h", "c" };

Deck::Deck() {
	for (std::string i : Deck::Cards)
		for (std::string j : Deck::Suits)
			D.push_back(i + j);
};

void Deck::shuffle() {
	int k;
	std::string temp;
	for (int i = 0; i < D.size() - 1; i++) {
		k = rand() % (D.size() - i) + i;
		temp = D[i]; D[i] = D[k]; D[k] = temp;
	}
};

std::string Deck::deal() {
	shuffle();
	std::string ret = D[0];
	D.erase(D.begin());
	return ret;
};

bool Deck::empty() {
	return D.size() == 0;
};

void Hand::deal_in(std::string h) {
	H.push_back(h);
};