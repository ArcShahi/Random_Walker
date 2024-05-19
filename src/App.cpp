
#include "App.hpp"

App::App()
	:m_window(sf::VideoMode(1200, 900), "Cell Automaton", sf::Style::Close)
	
{
	m_algae.cell.setRadius(2.3f);
	m_algae.cell.setFillColor(sf::Color{ 0,255,100,20 });
	m_algae.cell.setPosition({ 500.f,500.f });



}

void App::Run()
{
	while (m_window.isOpen())
	{
		processEvent();

		update();

		render();
	}

}

void App::update()
{

	m_algae.cell.move(m_algae.nextStep());
}

void App::render()
{
	m_window.draw(m_algae.cell);
	m_window.display();
}

void App::processEvent()
{

	sf::Event e{};

	while (m_window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			m_window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			m_window.close();
		}
	}
}
