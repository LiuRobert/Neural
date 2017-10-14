#include "Menu.h"
#include "SFML\Window\Mouse.hpp"
#include <iostream>
#include "Game.h"
#include "Settings.h"


Menu::Menu()
{
	leftMouseDown = false;
}


Menu::~Menu()
{
}

void Menu::test(int x)
{

}

void Menu::update(const sf::RenderWindow & window, Game& game)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (mousePos.x > 0 && mousePos.x < Settings::windowX && mousePos.y > 0 && mousePos.y < Settings::windowY)
	{
		if (leftMouseDown && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (game.getTile(mousePos.x / 100, 0) == 0)
			{
				bool winning = game.playMove(turn ? 1 : 2, mousePos.x / 100);
				if (winning)
				{
					std::cout << (turn ? "Red" : "Blue") << " Wins!" << std::endl;
				}
				turn = !turn;
			}
		}
	}
	leftMouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
