#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>

namespace Poker
{

	static std::map<std::string, int> HandRanking = { {"HighCard", 0}, {"Pair", 1}, {"TwoPair", 2}, {"Set", 3}, {"Straight", 4}, {"Flush", 5}, {"FullHouse", 6}, {"Quads", 7}, {"StraightFlush", 8} };
	static std::vector<char> cards = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	static std::vector<char> suits = { 's', 'd', 'h', 'c' };

	std::vector<char> Cards();
	std::vector<char> Suits();

	static std::map<char, int> CardValue = { {'A', 13}, {'K', 12}, {'Q', 11}, {'J', 10}, {'T', 9}, {'9', 8}, {'8', 7}, {'7', 6}, {'6', 5}, {'5', 4}, {'4', 3}, {'3', 2}, {'2', 1} };
	static std::map<char, int> SuitValue = { {'s', 1}, {'d', 2}, {'h', 3}, {'c', 4} };

class Game {};

struct Deck
{
private:
	std::vector<std::string> D;

public:
	Deck();
	Deck(std::vector<std::string> d);
	bool Empty();
	std::string Deal();
	void Shuffle();
};
/*
struct Hand
{
private:
	std::vector<std::string> H;

public:
	Hand();
	void DealIn(std::string c);
	std::string Strength(Board B);
};

struct Player
{
private:
	Hand Ruka;

public:
	Player();
	void DealIn(std::string c);
};

struct Board
{
private:
	Hand B;

public:
	Board();
	void DealIn(std::string c);
};

class Game
{
private:
	Board B;
	Deck Spil;
	std::vector<Player*> Players;
	std::string GameType;
	std::string Street;

public:
	Game(std::vector<Player*> p);
	void Deal();
	void Flop();
	void Turn();
	void River();
	void Evaluate();
};
*/
}