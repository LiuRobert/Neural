#pragma once
#include "SFML\Graphics\RenderWindow.hpp"

class Game;

class Menu
{
public:
	Menu();
	~Menu();

	void test(int x);
	void update(const sf::RenderWindow & window, Game& game);

private:
	bool leftMouseDown;
	bool turn;
};

