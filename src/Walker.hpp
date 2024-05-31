#ifndef WALKER_HPP
#define WALKER_HPP

#include <SFML/Graphics/CircleShape.hpp>

class Walker
{
public:
	Walker() = default;
	Walker(sf::Vector2f position, sf::Color color, float size = 1.3f);
	Walker(sf::Vector2f position, sf::Color color);
	Walker(sf::Vector2f position);

	sf::CircleShape cell{};
};

sf::Vector2f step();

#endif // WALKER_HPP
