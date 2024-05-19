#ifndef WALKER_HPP
#define WALKER_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include "randum.hpp"

#endif // !WALKER_HPP

class Walker
{


public:
	sf::Vector2f nextStep();

public:

	sf::CircleShape cell{};

};

