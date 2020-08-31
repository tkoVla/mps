#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <map>
#include "Poker.h"

std::vector<char> Poker::Cards()
{
	return cards;
};

std::vector<char> Poker::Suits()
{
	return suits;
};

using namespace Poker;

Deck::Deck()
{
	std::string r = "";
	D.clear();
	for(char c : cards)
		for (char s : suits)
		{
			r = "01";
			r[0] = c;
			r[1] = s;
			D.push_back(r);
		}
};

Deck::Deck(std::vector<std::string> d)
{
	D = d;
};

void Deck::Shuffle()
{
	std::string a;
	unsigned int k;

	for (unsigned int i = 0; i < D.size() - 1; i++)
	{
		k = rand() % (D.size() - i);
		k += i;
		a = D[0];
		D[0] = D[k];
		D[k] = a;
	}
};

std::string Deck::Deal()
{
	Shuffle();
	std::string a = D[0];
	D.erase(D.begin());
	return a;
};

bool Deck::Empty()
{
	return D.size() == 0;
};

/*
Hand::Hand()
{
	H.clear();
};

void Hand::DealIn(std::string c)
{
	H.push_back(c);
};

Player::Player()
{
	Ruka.clear();
};

void Player::DealIn(std::string c)
{
	Ruka.DealIn(c);
};

Board::Board()
{
	B = Hand();
};

void Board::DealIn(std::string c)
{
	B.DealIn(c);
};

Game::Game(std::vector<Player*> p)
{
	B = Board();
	Spil = Deck();
	Players = p;
	GameType = "Hold'em";
	Street = "Pre";
};

void Game::Deal()
{
	for (Player* it : Players)
	{
		it->DealIn(Spil.Deal());
		it->DealIn(Spil.Deal());
	}
};

void Game::Flop()
{
	B.DealIn(Spil.Deal());
	B.DealIn(Spil.Deal());
	B.DealIn(Spil.Deal());
};

void Game::Turn()
{
	B.DealIn(Spil.Deal());
};

void Game::River()
{
	B.DealIn(Spil.Deal());
};

void Game::Evaluate()
{

};
*/