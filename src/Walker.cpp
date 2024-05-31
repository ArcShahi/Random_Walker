#include "Walker.hpp"

Walker::Walker(sf::Vector2f position, sf::Color color, float size)
{
     cell.setPosition(position);
     cell.setRadius(size);
     cell.setFillColor(color);
}

Walker::Walker(sf::Vector2f position, sf::Color color)
{
     cell.setPosition(position);
     cell.setFillColor(color);
}

Walker::Walker(sf::Vector2f position)
{
     cell.setPosition(position);
}

sf::Vector2f step()
{
     auto step = rand() % 9;

     switch (step)
     {
     case 0:
          return { 1.f, 0.f };
     case 1:
          return { -1.f, 0.f };
     case 2:
          return { 0.f, 1.f };
     case 3:
          return { 0.f, -1.f };
     case 4:
          return { 0.f, 0.f };
     case 5:
          return { 1.f, 1.f };
     case 6:
          return { -1.f, -1.f };
     case 7:
          return { 1.f, -1.f };
     case 8:
          return { -1.f, 1.f };
     default:
          return { 0.f, 0.f };
     }
}
