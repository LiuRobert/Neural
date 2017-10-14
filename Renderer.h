#pragma once
#include <vector>

namespace sf 
{
	class RenderWindow;
	class CircleShape;
}
class Game;

class Renderer
{
public:
	Renderer();
	~Renderer();

	void render(sf::RenderWindow& window, const Game& game);

private:
	std::vector<sf::CircleShape> emptys;
	std::vector<sf::CircleShape> reds;
	std::vector<sf::CircleShape> blues;
};

