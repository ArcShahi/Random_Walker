#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <vector>

#include "Walker.hpp"
#include "Log.hpp"

class App
{
public:
	App();
	void Run();

private:
	sf::RenderWindow window;
	Walker algae;
	std::vector<Walker> colony;
	Log stats;
	sf::Time updateTimeStats;
	int fps;
	sf::Clock elapsedTime;

	void processEvents();
	void update(sf::Time time);
	void render();
	void updateStats(sf::Time eT);
};

#endif
