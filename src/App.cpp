#include "App.hpp"

App::App()
     : window(sf::VideoMode(1200, 900), "Cell Automaton", sf::Style::Close),
     algae(sf::Vector2f(600.f, 450.f), sf::Color::Green, 2.f),
     updateTimeStats(sf::Time::Zero), fps(0)
{
     colony.push_back(algae);
     window.setFramerateLimit(240);
}

void App::Run()
{
     sf::Clock clock{};

     while (window.isOpen())
     {
          processEvents();

          sf::Time elapsedTime = clock.restart();

          update(elapsedTime);

          render();

          updateStats(elapsedTime);
     }
}

void App::processEvents()
{
     sf::Event e{};

     while (window.pollEvent(e))
     {
          if (e.type == sf::Event::Closed)
          {
               window.close();
          }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
          {
               window.close();
          }
     }
}

void App::update(sf::Time time)
{
     float elapsedSeconds = elapsedTime.getElapsedTime().asSeconds();

     // Determine the color of the new cell based on the elapsed time
     sf::Color cellColor = sf::Color(250, 250, 250, 25);  // Default color

     if (elapsedSeconds >= 15 && elapsedSeconds < 30)
     {
          cellColor = sf::Color(0, 255, 100, 20);
     }
     else if (elapsedSeconds >= 30 && elapsedSeconds < 45)
     {
          cellColor = sf::Color(0, 30, 255, 25);
     }

     else if (elapsedSeconds >= 45 && elapsedSeconds < 60)
     {
          cellColor = sf::Color(255, 0, 50, 20);
     }
     else
     {
          cellColor = sf::Color::Cyan;
     }

     // Add new cell with the determined color
     sf::Vector2f lastPosition = colony.back().cell.getPosition();
     sf::Vector2f newPosition = lastPosition + step();
     Walker newCell(newPosition, cellColor, 2.3f);
     colony.emplace_back(newCell);
}

void App::render()
{
     window.clear();

     for (const auto& walker : colony)
     {
          window.draw(walker.cell);
     }

     window.draw(stats.text); // Draw stats

     window.display();
}

void App::updateStats(sf::Time eT)
{
     updateTimeStats += eT;
     fps++;

     if (updateTimeStats >= sf::seconds(1.0f))
     {
          float elapsedSeconds = elapsedTime.getElapsedTime().asSeconds();

          stats.text.setString(
               "FPS: " + std::to_string(fps) + "\n" +
               "Cells: " + std::to_string(colony.size()) + "\n" +
               "Time: " + std::to_string(static_cast<int>(elapsedSeconds)) + "s"
          );

          updateTimeStats -= sf::seconds(1.0f);
          fps = 0;
     }
}
