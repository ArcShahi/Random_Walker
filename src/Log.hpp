#ifndef LOG_HPP
#define LOG_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class Log
{
public:
	Log();
	sf::Font font{};
	sf::Text text{};
};

#endif // LOG_HPP
