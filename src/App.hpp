
#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "Walker.hpp"

class App
{
public:
	App();

	void Run();


private:
	void update();
	void render();
	void processEvent();

private:
	sf::RenderWindow m_window{};
	Walker m_algae{};

};


#endif // !APP_HPP



