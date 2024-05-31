#include "Log.hpp"

Log::Log()
{
     if (!font.loadFromFile("assets/arial.ttf"))
     {
          throw std::runtime_error("COULDN'T LOAD 'arial.ttf'");
     }

     text.setFont(font);
     text.setCharacterSize(15);
     text.setFillColor(sf::Color::Cyan);
     text.setPosition({ 5.0f, 5.0f });
}
