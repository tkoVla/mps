#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Deck {

public:

	Deck();
	void shuffle();
	std::string deal();
	bool empty();
	static std::vector<std::string> Cards; // = { "A", "K", "Q", "J", "T", "9", "8", "7", "6", "5", "4", "3", "2" };
	static std::vector<std::string> Suits; // = { "s", "d", "h", "c" };

private:

	std::vector<std::string> D;

};
