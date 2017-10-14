#include "Renderer.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "Game.h"


Renderer::Renderer()
{
	float diameter = 100.0f;
	for (float y = 0; y < 6; y++)
	{
		for (float x = 0; x < 7; x++)
		{
			sf::CircleShape empty;
			empty.setOutlineColor(sf::Color::Black);
			empty.setFillColor(sf::Color::White);
			empty.setRadius(diameter / 2.0f);
			empty.setPosition(x * diameter, y * diameter);
			empty.setOutlineThickness(2.0f);
			emptys.push_back(empty);

			sf::CircleShape red;
			red.setOutlineColor(sf::Color::Black);
			red.setFillColor(sf::Color::Red);
			red.setRadius(diameter / 2.0f);
			red.setPosition(x * diameter, y * diameter);
			red.setOutlineThickness(2.0f);
			reds.push_back(red);

			sf::CircleShape blue;
			blue.setOutlineColor(sf::Color::Black);
			blue.setFillColor(sf::Color::Blue);
			blue.setRadius(diameter / 2.0f);
			blue.setPosition(x * diameter, y * diameter);
			blue.setOutlineThickness(2.0f);
			blues.push_back(blue);
		}
	}
}


Renderer::~Renderer()
{
}

void Renderer::render(sf::RenderWindow& window, const Game & game)
{
	for (int i = 0; i < 42; i++)
	{
		switch (game.getTile(i))
		{
		case 0:
			window.draw(emptys[i]);
			break;
		case 1:
			window.draw(reds[i]);
			break;
		case 2:
			window.draw(blues[i]);
			break;
		default:
			break;
		}
	}
}
