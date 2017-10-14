#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include "NeuralNet.h"
#include "Renderer.h"
#include "Settings.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(Settings::windowX, Settings::windowY), "4 i rad", sf::Style::Default, settings);

	Game game;
	Menu menu;
	Renderer renderer;

	NeuralNet net(126, 7, 1);
	net.setNeuronCountInLayer(0, 100);
	net.init();
	float input[126];
	float * output;
	for (int i = 0; i < 126; i++)
	{
		if (i % 2 == 0)
			input[i] = 0.0;
		else
			input[i] = 1.0;
	}

	output = net.think(input);
	for (int i = 0; i < 7; i++)
	{
		std::cout << output[i] << std::endl;
	}

	net.save("test.nn");
	net.load("test.nn");

	std::cout << std::endl;

	output = net.think(input);
	for (int i = 0; i < 7; i++)
	{
		std::cout << output[i] << std::endl;
	}

	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		menu.update(window, game);
		window.clear(sf::Color::White);
		renderer.render(window, game);
		window.display();

		float deltaTime = clock.restart().asSeconds();
		
	}

	return 0;
}